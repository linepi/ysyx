#include <common.h>
#include <debug.h>
#include "sdb.h"
// 121+((216-818)*819*298)*302

void test_expr() {
    FILE* fp = fopen("/home/w/dev/ysyx-workbench/nemu/tools/gen-expr/build/test0", "r");
    assert(fp != NULL);
    expr_t expect;
    char e[20000];
    int cnt = 0;
    int win = 0;
    while (fscanf(fp, "%lu", &expect) != EOF && fscanf(fp, "%s", e) != EOF) {
        cnt++;
        bool success;
        expr_t res = expr(e, &success);
        if (!success) {
            printf("expr fail for %s\n", e);
            continue;
        }
        if (res != expect) {
            printf("unsame for %s\nexpect: %lu, res: %lu\n", e, expect, res);
            continue;
        }
        win++;
    }
    printf("cnt = %d, win = %d\n", cnt, win);
    fclose(fp);
}