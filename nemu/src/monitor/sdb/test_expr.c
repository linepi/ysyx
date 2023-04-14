#include <common.h>
#include <debug.h>
#include <sdb.h>
#include <debug.h>
// 121+((216-818)*819*298)*302

void test_expr() {
    FILE* fp = fopen("/home/w/dev/ysyx-workbench/nemu/tools/gen-expr/build/test2", "r");
    assert(fp != NULL);
    expr_t expect;
    char e[200000];
    int cnt = 0;
    int win = 0;
    while (fscanf(fp, "%lu", &expect) != EOF && fscanf(fp, "%[^\n]", e) != EOF) {
        cnt++;
        bool success;
        expr_t res = expr(e, &success);
        if (!success) {
            printf("expr fail for %s\n", e);
            continue;
        }
        if (res != expect) {
            printf(ANSI_FMT("unsame for %s", ANSI_FG_RED)"\nexpect: %lu, res: %lu\n", e, expect, res);
            continue;
        }
        win++;
    }
    printf("cnt = %d, win = %d\n", cnt, win);
    fclose(fp);
}