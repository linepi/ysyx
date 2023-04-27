/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>
#include <sdb.h>

enum {
  TK_NOTYPE = 256, 
  TK_DEC,
  TK_REG,
  TK_HEX,
  TK_EQ, TK_NE, TK_GE, TK_GT, TK_LT, TK_LE,
  TK_AND, TK_OR, TK_NOT, TK_BOR, TK_BAND, TK_BXOR, TK_BNOT, 
  TK_LEFT, TK_RIGHT, TK_NEG, TK_DEREFERENCE,
  TK_FUNC_ADDR
  /* TODO: Add more token types */
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\(", '('},         
  {"\\)", ')'},         
  {"-", '-'},         
  {"%", '%'},
  {"\\*", '*'},         
  {"/", '/'},         
  {"<<", TK_LEFT},        
  {">>", TK_RIGHT},        
  {"==", TK_EQ},        // equal
  {"!=", TK_NE},        
  {">=", TK_GE},        
  {"<=", TK_LE},        
  {">", TK_GT},        
  {"<", TK_LT},        
  {"&&", TK_AND},        
  {"\\|\\|", TK_OR},        
  {"!", TK_NOT},        
  {"\\|", TK_BOR},        
  {"&", TK_BAND},        
  {"\\^", TK_BXOR},        
  {"~", TK_BNOT},        
  {"-", TK_NEG},        
  {"\\*", TK_DEREFERENCE},        
  {"0[xX]([0-9]|[a-f]|[A-F])+", TK_HEX},    
  {"[0-9]+", TK_DEC},    // digital number
  {"\\$\\w{2,3}", TK_REG},   
  {"([_]|[a-z]|[A-Z])\\w*", TK_FUNC_ADDR} 
};

#define NR_REGEX ARRLEN(rules)
#define TOKEN_STR_LEN 32

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[TOKEN_STR_LEN];
} Token;

static Token tokens[10000] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  if (!e) return false;
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        int substr_len = pmatch.rm_eo;
        if (substr_len >= TOKEN_STR_LEN) {
          return false;
        }

        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        switch (rules[i].token_type) {
          case TK_NOTYPE: 
            break;
          case TK_DEC: case TK_HEX: case TK_REG: case TK_FUNC_ADDR:
            tokens[nr_token].type = rules[i].token_type;
            memcpy(tokens[nr_token].str, e + position - substr_len, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
          case '-':
            if (nr_token == 0 || tokens[nr_token - 1].type == '(') tokens[nr_token].type = TK_NEG;
            else if (tokens[nr_token - 1].type == TK_DEC || 
                     tokens[nr_token - 1].type == TK_HEX || 
                     tokens[nr_token - 1].type == TK_REG || 
                     tokens[nr_token - 1].type == ')') tokens[nr_token].type = '-';
            else tokens[nr_token].type = TK_NEG;
            nr_token++;
            break;
          case '*':
            if (nr_token == 0 || tokens[nr_token - 1].type == '(') tokens[nr_token].type = TK_DEREFERENCE;
            else if (tokens[nr_token - 1].type == TK_DEC || 
                     tokens[nr_token - 1].type == TK_HEX || 
                     tokens[nr_token - 1].type == TK_REG || 
                     tokens[nr_token - 1].type == ')') tokens[nr_token].type = '*';
            else tokens[nr_token].type = TK_DEREFERENCE;
            nr_token++;
            break;
          default:
            tokens[nr_token++].type = rules[i].token_type;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      // printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(int p, int q, bool *status) {
    if (tokens[p].type != '(') {
        return false;
    }
    int open_parentheses = 1;
    for (p = p + 1; p <= q; ++p) {
        if (tokens[p].type == '(') {
            open_parentheses++;
        } else if (tokens[p].type == ')') {
            open_parentheses--;
            if (open_parentheses == 0 && p != q) {
                return false;
            }
        }
    }
    return open_parentheses == 0;
}

static int get_priority(int type) {
  // 简化的版本
  switch (type) {
    case TK_AND: case TK_OR: return 1;
    case TK_BAND: case TK_BOR: case TK_BXOR: return 2;
    case TK_EQ: case TK_NE: case TK_GE: case TK_GT: case TK_LE: case TK_LT: return 3;
    case TK_RIGHT: case TK_LEFT: return 4;
    case '+': case '-': return 5;
    case '*': case '/': case '%': return 6;
    case TK_BNOT: case TK_NOT: case TK_NEG: case TK_DEREFERENCE: return 7;
    default: return 0;
  }
}

static int get_main_operator(int p, int q) {
  int idx = 0;
  int priority = 100;
  int leftn = 0;
  for (; p <= q; p++) {
    if (tokens[p].type == '(') leftn++;
    if (tokens[p].type == ')') leftn--;
    if ((tokens[p].type <= TK_DEREFERENCE && tokens[p].type >= TK_EQ) || 
        (tokens[p].type < 256 && tokens[p].type != '(' && tokens[p].type != ')')) {
      int tmp = get_priority(tokens[p].type); 
      if (tmp <= priority && leftn == 0) {
        priority = tmp;
        idx = p;
      }
    }
  }
  return idx;
}

static expr_t eval(int p, int q, bool *status) {
  if (*status == false) return 0;

  if (p > q) {
    *status = false;
    return 0;
  } else if (p == q) {
    expr_t val = 0;
    if (tokens[p].type == TK_DEC) {
      val = strtol(tokens[p].str, NULL, 10);
    } else if (tokens[p].type == TK_HEX) {
      val = strtol(tokens[p].str, NULL, 16);
    } else if (tokens[p].type == TK_REG) {
      bool success = true;
      val = isa_reg_str2val(tokens[p].str + 1, &success);
      if (!success) 
        *status = false;
    } else if (tokens[p].type == TK_FUNC_ADDR ){
      if (!functbl) {
        Error("No functbl specified");
        *status = false;
        return 0;
      }
      for (int i = 0; !functbl[i].end; i++) {
        if (strcmp(functbl[i].name, tokens[p].str) == 0)
          val = functbl[i].addr;
      }
    } else {
      *status = false;
    }
    return val;
  } else if (check_parentheses(p, q, status) == true) {
    return eval(p + 1, q - 1, status); 
  } else {
    // get the main operator
    int op_idx = get_main_operator(p, q);
    int type = tokens[op_idx].type;
    expr_t val2 = eval(op_idx + 1, q, status);
    if (type == TK_NOT) {
      return !val2;
    } else if (type == TK_BNOT) {
      return ~val2;
    } else if (type == TK_NEG) {
      return -val2; 
    } else if (type == TK_DEREFERENCE){
      assert(PADDR_VALID(val2));
      return *(uint32_t*)guest_to_host(val2);
    } else {
      expr_t val1 = eval(p, op_idx - 1, status);
      switch (tokens[op_idx].type) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': case '%':
          if (val2 == 0) {
            Error("Division by zero exception\n");
            *status = false;
            return 0;
          }
          if (tokens[op_idx].type == '/')
            return val1 / val2;
          else 
            return val1 % val2;
        case TK_EQ: return val1 == val2;
        case TK_NE: return val1 != val2;
        case TK_GT: return val1 > val2;
        case TK_GE: return val1 >= val2;
        case TK_LT: return val1 < val2;
        case TK_LE: return val1 <= val2;
        case TK_AND: return val1 && val2;
        case TK_OR: return val1 || val2;
        case TK_BAND: return val1 & val2;
        case TK_BOR: return val1 | val2;
        case TK_BXOR: return val1 ^ val2;
        case TK_RIGHT: return val1 >> val2;
        case TK_LEFT: return val1 << val2;
        default: 
          *status = false;
          return 0;
      }
    }
  }
}

expr_t expr(char *e, bool *success) {
  *success = true;
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  return eval(0, nr_token - 1, success); 
}