#include <common.h>
#include <debug.h>
#include "sdb.h"

void test_expr() {
    FILE* fp = fopen("/home/w/dev/ysyx-workbench/nemu/tools/gen-expr/build/test0", "r");
    assert(fp != NULL);
    long expect;
    char e[2000];
    while (fscanf(fp, "%ld", &expect) != EOF && fscanf(fp, "%s", e) != EOF) {
        bool success;
        sword_t res = expr(e, &success);
        if (!success) {
            printf("expr fail for %s\n", e);
            continue;
        }
        if (res != expect) {
            printf("unsame for %s\nexpect: %ld, res: %ld\n", e, expect, res);
        }
    }
    fclose(fp);
}