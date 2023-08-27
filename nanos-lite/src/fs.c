#include <fs.h>

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t serial_write(const void *buf, size_t offset, size_t len);
size_t events_read(void *buf, size_t offset, size_t len);
size_t dispinfo_read(void *buf, size_t offset, size_t len);
size_t fb_write(const void *buf, size_t offset, size_t len);
/* This is the information about all files in disk. */
Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]  = {"stdin",  0, 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, 0, invalid_read, serial_write},
  [FD_STDERR] = {"stderr", 0, 0, 0, invalid_read, serial_write},
  [FD_EVENT] =  {"/dev/events", 0, 0, 0, events_read, invalid_write},
  [FD_DISPINFO] =  {"/proc/dispinfo", 0, 0, 0, dispinfo_read, invalid_write},
  [FD_FB] =  {"/dev/fb", 0, 0, 0, invalid_read, fb_write},
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
  size_t left_size = file_table[fd].size - file_table[fd].seek_offset;
  if (len > left_size) Log("warning: fs write overflow");
  ramdisk_write(buf, offset, MIN(left_size, len));
  file_table[fd].seek_offset += MIN(left_size, len);
  return MIN(left_size, len);
}

int fs_open(const char *pathname, int flags, int mode) {
  int i = 0;
  for (; i < NR_FILE; i++) {
    if (strcmp(pathname, file_table[i].name) == 0) {
      return i;
    }
  }
  Log("No file named %s", pathname);
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
  file_table[fd].seek_offset = 0;
  return 0;
}

extern int system_w;
extern int system_h;
void init_fs() {
  // TODO: initialize the size of /dev/fb
  system_w = io_read(AM_GPU_CONFIG).width;
  system_h = io_read(AM_GPU_CONFIG).height;
  file_table[FD_FB].size = system_w * system_h * 4;
}
