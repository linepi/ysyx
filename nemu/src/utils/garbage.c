#include <common.h>
#include <sdb.h>
#include <utils.h>

static struct heap_node head = {};

void *wmalloc(size_t sz) {
  void *ret;
  ret = malloc(sz);
  // add addr into list
  struct heap_node *new = (struct heap_node*)malloc(sizeof(struct heap_node));
  new->next = head.next;
  new->addr = ret;
  head.next = new;

  return ret;
}

void garbage_collect(int num) {
  struct heap_node *q = NULL;
  for (struct heap_node *p = head.next; p; p = p->next) {
    free(q);
    free(p->addr);
    q = p;
  }
  free(q);
}

void close_file() {
  if (!elf_fp) fclose(elf_fp);
  if (!log_fp) fclose(log_fp);
}