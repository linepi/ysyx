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

#include <sdb.h>


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static int number = 0;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].funcName = NULL;
  }

  head = NULL;
  free_ = wp_pool;
}

WP* get_wp_head() {
  return head;
}

WP* new_wp() {
  if (free_ == NULL) {
    Error("No more freed wp\n");
    assert(0);
  }
  WP *t = free_->next;
  free_->next = head;
  head = free_;
  free_ = t;

  head->NO = ++number;
  return head;
};

void free_wp(WP *wp) {
  if (wp == NULL) return;
  WP *t = head;
  // let funcName to NULL for next use
  wp->funcName = NULL;

  if (t == wp) {
    head = head->next;
    wp->next = free_;
    free_ = wp;
    return;
  }

  while (t->next) {
    if (t->next == wp) {
      t->next = wp->next;
      wp->next = free_;
      free_ = wp;
      break;
    }
    t = t->next;
  }
};

void wp_display() {
  if (get_wp_head() == NULL) return;
  printf("NUM      EXPRESSION     VAL\n");
  for (WP *i = get_wp_head(); i; i = i->next) {
    printf("%d        %s            "EXPR_NUM_FMT"\n", i->NO, i->e, i->val);
  }
}