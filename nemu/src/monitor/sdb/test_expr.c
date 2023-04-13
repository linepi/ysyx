#include <common.h>
#include <debug.h>
sword_t expr(char *e, bool *success);

void test_expr() {
    FILE* fp = fopen("/home/w/dev/ysyx-workbench/nemu/tools/gen-expr/build/test0", "r");
    assert(fp != NULL);
    long expect;
    char e[20000];
    int cnt = 0;
    int win = 0;
    while (fscanf(fp, "%ld", &expect) != EOF && fscanf(fp, "%s", e) != EOF) {
        cnt++;
        bool success;
        sword_t res = expr(e, &success);
        if (!success) {
            printf("expr fail for %s\n", e);
            continue;
        }
        if (res != expect) {
            printf("unsame for %s\nexpect: %ld, res: %ld\n", e, expect, res);
            continue;
        }
        win++;
    }
    printf("cnt = %d, win = %d\n", cnt, win);
    fclose(fp);
}