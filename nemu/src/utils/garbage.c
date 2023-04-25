#include <common.h>
#include <sdb.h>

void *wmalloc(size_t sz) {
  return NULL;
}

void wfree(void *p) {

}

void garbage_collect() {
  if (!elf_fp) fclose(elf_fp);
  if (!log_fp) fclose(log_fp);
}