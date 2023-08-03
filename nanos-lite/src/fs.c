#include <fs.h>

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t serial_write(const void *buf, size_t offset, size_t len);
/* This is the information about all files in disk. */
Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin",  0, 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, 0, invalid_read, serial_write},
#include "files.h"
};

#define NR_FILE sizeof(file_table)/sizeof(file_table[0])
#define MAX(a, b) (a < b ? b : a)
#define MIN(a, b) (a > b ? b : a)

char *get_fd_filename(int fd) {
  return file_table[fd].name;
}

int get_nr_file() {
  return NR_FILE;
}

size_t fs_read(int fd, void *buf, size_t len) {
  if (fd <= FD_STDERR && fd >= FD_STDIN) return 0;
  size_t offset = file_table[fd].disk_offset + file_table[fd].seek_offset;
  size_t size = file_table[fd].size;

  if (len > size) Log("warning: fs read overflow");
  ramdisk_read(buf, offset, MIN(size, len));
  file_table[fd].seek_offset += MIN(size, len);
  return MIN(size, len);
}

size_t fs_write(int fd, const void *buf, size_t len) {
  size_t offset = file_table[fd].disk_offset + file_table[fd].seek_offset;
  size_t size = file_table[fd].size;
  if (len > size) Log("warning: fs write overflow");
  ramdisk_write(buf, offset, MIN(size, len));
  file_table[fd].seek_offset += MIN(size, len);
  return MIN(size, len);
}

int fs_open(const char *pathname, int flags, int mode) {
  int i = 0;
  for (; i < NR_FILE; i++) {
    if (strcmp(pathname, file_table[i].name) == 0) {
      return i;
    }
  }
  assert(0);
}

size_t fs_lseek(int fd, size_t offset, int whence) {
  if (whence == SEEK_CUR) {
    file_table[fd].seek_offset += offset;
  } else if (whence == SEEK_END) {
    Log("warning: whence is SEEK_END");
    file_table[fd].seek_offset = offset + file_table[fd].size;
  } else if (whence == SEEK_SET) {
    file_table[fd].seek_offset = offset;
  }
  return file_table[fd].seek_offset;
}

int fs_close(int fd) {
  return 0;
}

void init_fs() {
  // TODO: initialize the size of /dev/fb
}
