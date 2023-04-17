

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;

typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;

typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void *__timer_t;

typedef long int __blksize_t;

typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __fsword_t;

typedef long int __ssize_t;

typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;

typedef __off64_t __loff_t;
typedef char *__caddr_t;

typedef long int __intptr_t;

typedef unsigned int __socklen_t;

typedef int __sig_atomic_t;

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;

typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;

typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;

typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef int __gwchar_t;

typedef struct {
  long int quot;
  long int rem;
} imaxdiv_t;
extern intmax_t imaxabs(intmax_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern intmax_t strtoimax(const char *__restrict __nptr,
                          char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern uintmax_t strtoumax(const char *__restrict __nptr,
                           char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern intmax_t wcstoimax(const __gwchar_t *__restrict __nptr,
                          __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

extern uintmax_t wcstoumax(const __gwchar_t *__restrict __nptr,
                           __gwchar_t **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__));

typedef long unsigned int size_t;
extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern void *memmove(void *__dest, const void *__src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void *memccpy(void *__restrict __dest, const void *__restrict __src,
                     int __c, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)))
__attribute__((__access__(__write_only__, 1, 4)));

extern void *memset(void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int memcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern int __memcmpeq(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern void *memchr(const void *__s, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern char *strcat(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strncat(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern int strcmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strncmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strcoll(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern size_t strxfrm(char *__restrict __dest, const char *__restrict __src,
                      size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)))
__attribute__((__access__(__write_only__, 1, 3)));

struct __locale_struct {
  struct __locale_data *__locales[13];

  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;

  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef __locale_t locale_t;

extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));

extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n,
                        locale_t __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 4)))
__attribute__((__access__(__write_only__, 1, 3)));

extern char *strdup(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));

extern char *strndup(const char *__string, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__nonnull__(1)));
extern char *strchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *strrchr(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern size_t strcspn(const char *__s, const char *__reject)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern size_t strspn(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strpbrk(const char *__s, const char *__accept)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));
extern char *strstr(const char *__haystack, const char *__needle)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern char *strtok(char *__restrict __s, const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim,
                        char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));

extern char *strtok_r(char *__restrict __s, const char *__restrict __delim,
                      char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern size_t strlen(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern size_t strnlen(const char *__string, size_t __maxlen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern char *strerror(int __errnum) __attribute__((__nothrow__, __leaf__));
extern int strerror_r(int __errnum, char *__buf, size_t __buflen) __asm__(
    ""
    "__xpg_strerror_r") __attribute__((__nothrow__, __leaf__))

__attribute__((__nonnull__(2)))
__attribute__((__access__(__write_only__, 2, 3)));
extern char *strerror_l(int __errnum, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

extern int bcmp(const void *__s1, const void *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern void bcopy(const void *__src, void *__dest, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void bzero(void *__s, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern char *index(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));
extern char *rindex(const char *__s, int __c)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern int ffs(int __i) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

extern int ffsl(long int __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
__extension__ extern int ffsll(long long int __ll)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern int strcasecmp(const char *__s1, const char *__s2)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strncasecmp(const char *__s1, const char *__s2, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2)));

extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1, 2, 3)));

extern int strncasecmp_l(const char *__s1, const char *__s2, size_t __n,
                         locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 4)));

extern void explicit_bzero(void *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
    __attribute__((__access__(__write_only__, 1, 2)));

extern char *strsep(char **__restrict __stringp, const char *__restrict __delim)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *strsignal(int __sig) __attribute__((__nothrow__, __leaf__));
extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *stpncpy(char *__restrict __dest, const char *__restrict __src,
                     size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

typedef int wchar_t;

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long int quot;
  long int rem;
} ldiv_t;

__extension__ typedef struct {
  long long int quot;
  long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void)
    __attribute__((__nothrow__, __leaf__));

extern double atof(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern int atoi(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern long int atol(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int atoll(const char *__nptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
    __attribute__((__nonnull__(1)));

extern double strtod(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern float strtof(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long double strtold(const char *__restrict __nptr,
                           char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr,
                       char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern unsigned long int strtoul(const char *__restrict __nptr,
                                 char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int strtoq(const char *__restrict __nptr,
                                          char **__restrict __endptr,
                                          int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int strtouq(
    const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern long long int strtoll(const char *__restrict __nptr,
                                           char **__restrict __endptr,
                                           int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int strtoull(
    const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *l64a(long int __n) __attribute__((__nothrow__, __leaf__));

extern long int a64l(const char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;

typedef __loff_t loff_t;

typedef __ino_t ino_t;
typedef __dev_t dev_t;

typedef __gid_t gid_t;

typedef __mode_t mode_t;

typedef __nlink_t nlink_t;

typedef __uid_t uid_t;

typedef __off_t off_t;
typedef __pid_t pid_t;

typedef __id_t id_t;

typedef __ssize_t ssize_t;

typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;

typedef __key_t key_t;

typedef __clock_t clock_t;

typedef __clockid_t clockid_t;
typedef __time_t time_t;

typedef __timer_t timer_t;

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;

typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t __bswap_16(__uint16_t __bsx) {
  return __builtin_bswap16(__bsx);
}

static __inline __uint32_t __bswap_32(__uint32_t __bsx) {
  return __builtin_bswap32(__bsx);
}
__extension__ static __inline __uint64_t __bswap_64(__uint64_t __bsx) {
  return __builtin_bswap64(__bsx);
}
static __inline __uint16_t __uint16_identity(__uint16_t __x) { return __x; }

static __inline __uint32_t __uint32_identity(__uint32_t __x) { return __x; }

static __inline __uint64_t __uint64_identity(__uint64_t __x) { return __x; }

typedef struct {
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;

typedef __sigset_t sigset_t;

struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};

struct timespec {
  __time_t tv_sec;

  __syscall_slong_t tv_nsec;
};

typedef __suseconds_t suseconds_t;

typedef long int __fd_mask;
typedef struct {
  __fd_mask __fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];

} fd_set;

typedef __fd_mask fd_mask;

extern int select(int __nfds, fd_set *__restrict __readfds,
                  fd_set *__restrict __writefds, fd_set *__restrict __exceptfds,
                  struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);

typedef __blksize_t blksize_t;

typedef __blkcnt_t blkcnt_t;

typedef __fsblkcnt_t fsblkcnt_t;

typedef __fsfilcnt_t fsfilcnt_t;

typedef union {
  __extension__ unsigned long long int __value64;
  struct {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;

typedef struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist {
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;

  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;

  unsigned char __pad1[7];

  unsigned long int __pad2;

  unsigned int __flags;
};

struct __pthread_cond_s {
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct {
  int __data;
} __once_flag;

typedef unsigned long int pthread_t;

typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;

typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;

union pthread_attr_t {
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;

typedef union {
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union {
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union {
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;

typedef volatile int pthread_spinlock_t;

typedef union {
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random(void) __attribute__((__nothrow__, __leaf__));

extern void srandom(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern char *initstate(unsigned int __seed, char *__statebuf, size_t __statelen)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern char *setstate(char *__statebuf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

struct random_data {
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};

extern int random_r(struct random_data *__restrict __buf,
                    int32_t *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int srandom_r(unsigned int __seed, struct random_data *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int initstate_r(unsigned int __seed, char *__restrict __statebuf,
                       size_t __statelen, struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));

extern int setstate_r(char *__restrict __statebuf,
                      struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int rand(void) __attribute__((__nothrow__, __leaf__));

extern void srand(unsigned int __seed) __attribute__((__nothrow__, __leaf__));

extern int rand_r(unsigned int *__seed) __attribute__((__nothrow__, __leaf__));

extern double drand48(void) __attribute__((__nothrow__, __leaf__));
extern double erand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int nrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern long int mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int jrand48(unsigned short int __xsubi[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void srand48(long int __seedval) __attribute__((__nothrow__, __leaf__));
extern unsigned short int *seed48(unsigned short int __seed16v[3])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

struct drand48_data {
  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  __extension__ unsigned long long int __a;
};

extern int drand48_r(struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int lrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int mrand48_r(struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data *__restrict __buffer,
                     long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int srand48_r(long int __seedval, struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int seed48_r(unsigned short int __seed16v[3],
                    struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern int lcong48_r(unsigned short int __param[7],
                     struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));

extern void *malloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));

extern void *calloc(size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_size__(1, 2)));

extern void *realloc(void *__ptr, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2)));

extern void free(void *__ptr) __attribute__((__nothrow__, __leaf__));

extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__warn_unused_result__))
    __attribute__((__alloc_size__(2, 3)))
    __attribute__((__malloc__(__builtin_free, 1)));

extern void *reallocarray(void *__ptr, size_t __nmemb, size_t __size)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__malloc__(reallocarray, 1)));

extern void *alloca(size_t __size) __attribute__((__nothrow__, __leaf__));

extern void *valloc(size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(1)));

extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void *aligned_alloc(size_t __alignment, size_t __size)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__alloc_align__(1))) __attribute__((__alloc_size__(2)));

extern void abort(void) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern int atexit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int at_quick_exit(void (*__func)(void))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

extern void exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void quick_exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern void _Exit(int __status) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

extern char *getenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int putenv(char *__string) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int setenv(const char *__name, const char *__value, int __replace)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));

extern int unsetenv(const char *__name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));

extern int clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char *mktemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkstemp(char *__template) __attribute__((__nonnull__(1)));
extern int mkstemps(char *__template, int __suffixlen)
    __attribute__((__nonnull__(1)));
extern char *mkdtemp(char *__template) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int system(const char *__command);
extern char *realpath(const char *__restrict __name,
                      char *__restrict __resolved)
    __attribute__((__nothrow__, __leaf__));

typedef int (*__compar_fn_t)(const void *, const void *);
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
                     size_t __size, __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 2, 5)));

extern void qsort(void *__base, size_t __nmemb, size_t __size,
                  __compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));
extern int abs(int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern long int labs(long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));

__extension__ extern long long int llabs(long long int __x)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern div_t div(int __numer, int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern ldiv_t ldiv(long int __numer, long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

__extension__ extern lldiv_t lldiv(long long int __numer, long long int __denom)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));

extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4)));

extern char *gcvt(double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));

extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qgcvt(long double __value, int __ndigit, char *__buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));

extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt,
                  int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));

extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(3, 4, 5)));

extern int mblen(const char *__s, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s,
                  size_t __n) __attribute__((__nothrow__, __leaf__));

extern int wctomb(char *__s, wchar_t __wchar)
    __attribute__((__nothrow__, __leaf__));

extern size_t mbstowcs(wchar_t *__restrict __pwcs, const char *__restrict __s,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__read_only__, 2)));

extern size_t wcstombs(char *__restrict __s, const wchar_t *__restrict __pwcs,
                       size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1, 3)))
__attribute__((__access__(__read_only__, 2)));

extern int rpmatch(const char *__response)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int getsubopt(char **__restrict __optionp,
                     char *const *__restrict __tokens,
                     char **__restrict __valuep)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__nonnull__(1, 2, 3)));
extern int getloadavg(double __loadavg[], int __nelem)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

typedef uint64_t word_t;
typedef int64_t sword_t;

typedef word_t vaddr_t;
typedef uint32_t paddr_t;

typedef uint16_t ioaddr_t;

typedef __builtin_va_list __gnuc_va_list;

typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;

typedef struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t {
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;

struct _IO_FILE;
typedef struct _IO_FILE __FILE;

struct _IO_FILE;

typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;

typedef void _IO_lock_t;

struct _IO_FILE {
  int _flags;

  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;

  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;

  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};
typedef __gnuc_va_list va_list;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

extern int remove(const char *__filename)
    __attribute__((__nothrow__, __leaf__));

extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__, __leaf__));

extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new) __attribute__((__nothrow__, __leaf__));
extern int fclose(FILE *__stream);
extern FILE *tmpfile(void) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1)));
extern char *tmpnam(char[20]) __attribute__((__nothrow__, __leaf__));

extern char *tmpnam_r(char __s[20]) __attribute__((__nothrow__, __leaf__));
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(__builtin_free, 1)));

extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1)));

extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes, FILE *__restrict __stream);
extern FILE *fdopen(int __fd, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));

extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));

extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));

extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size) __attribute__((__nothrow__, __leaf__));

extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int fprintf(FILE *__restrict __stream, const char *__restrict __format,
                   ...);

extern int printf(const char *__restrict __format, ...);

extern int sprintf(char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__));

extern int vfprintf(FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg);

extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf(char *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));

extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));

extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));
extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));

extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...);

extern int scanf(const char *__restrict __format, ...);

extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __attribute__((__nothrow__, __leaf__));
extern int
fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_fscanf")

    ;
extern int scanf(const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_scanf");
extern int
sscanf(const char *__restrict __s, const char *__restrict __format, ...) __asm__(
    ""
    "__isoc99_sscanf") __attribute__((__nothrow__, __leaf__))

;
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));

extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));

extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));

extern int
vfscanf(FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vfscanf")

    __attribute__((__format__(__scanf__, 2, 0)));
extern int
vscanf(const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vscanf")

    __attribute__((__format__(__scanf__, 1, 0)));
extern int
vsscanf(const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__(
    ""
    "__isoc99_vsscanf") __attribute__((__nothrow__, __leaf__))

__attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);

extern int getchar(void);

extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);

extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);

extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);

extern int getw(FILE *__stream);

extern int putw(int __w, FILE *__stream);

extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream)
    __attribute__((__access__(__write_only__, 1, 2)));
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                            int __delimiter, FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                          int __delimiter, FILE *__restrict __stream);

extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);

extern int fputs(const char *__restrict __s, FILE *__restrict __stream);

extern int puts(const char *__s);

extern int ungetc(int __c, FILE *__stream);

extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream);

extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

extern int fseek(FILE *__stream, long int __off, int __whence);

extern long int ftell(FILE *__stream);

extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);

extern __off_t ftello(FILE *__stream);
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);

extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern void clearerr(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int ferror(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern void clearerr_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));

extern void perror(const char *__s);

extern int fileno(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int fileno_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int pclose(FILE *__stream);

extern FILE *popen(const char *__command, const char *__modes)
    __attribute__((__malloc__)) __attribute__((__malloc__(pclose, 1)));

extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1)));
extern void flockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));

extern void funlockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int __uflow(FILE *);
extern int __overflow(FILE *, int);

enum { NEMU_RUNNING, NEMU_STOP, NEMU_END, NEMU_ABORT, NEMU_QUIT };

typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NEMUState;

extern NEMUState nemu_state;

uint64_t get_time();

typedef struct {
  word_t gpr[32];
  vaddr_t pc;
} riscv64_CPU_state;

typedef struct {
  union {
    uint32_t val;
  } inst;
} riscv64_ISADecodeInfo;

typedef __GUEST_ISA___CPU_state CPU_state;
typedef __GUEST_ISA___ISADecodeInfo ISADecodeInfo;

extern char isa_logo[];
void init_isa();

extern CPU_state cpu;
void isa_reg_display();
word_t isa_reg_str2val(const char *name, _Bool *success);

struct Decode;
int isa_exec_once(struct Decode *s);

enum { MMU_DIRECT, MMU_TRANSLATE, MMU_FAIL };
enum { MEM_TYPE_IFETCH, MEM_TYPE_READ, MEM_TYPE_WRITE };
enum { MEM_RET_OK, MEM_RET_FAIL, MEM_RET_CROSS_PAGE };

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type);

vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);

word_t isa_query_intr();

_Bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
void isa_difftest_attach();
void cpu_exec(uint64_t n);

void set_nemu_state(int state, vaddr_t pc, int halt_ret);
void invalid_inst(vaddr_t thispc);

typedef int Function() __attribute__((deprecated));
typedef void VFunction() __attribute__((deprecated));
typedef char *CPFunction() __attribute__((deprecated));
typedef char **CPPFunction() __attribute__((deprecated));
typedef int rl_command_func_t(int, int);

typedef char *rl_compentry_func_t(const char *, int);
typedef char **rl_completion_func_t(const char *, int, int);

typedef char *rl_quote_func_t(char *, int, char *);
typedef char *rl_dequote_func_t(char *, int);

typedef int rl_compignore_func_t(char **);

typedef void rl_compdisp_func_t(char **, int, int);

typedef int rl_hook_func_t(void);

typedef int rl_getc_func_t(FILE *);

typedef int rl_linebuf_func_t(char *, int);

typedef int rl_intfunc_t(int);

typedef int rl_icpfunc_t(char *);
typedef int rl_icppfunc_t(char **);

typedef void rl_voidfunc_t(void);
typedef void rl_vintfunc_t(int);
typedef void rl_vcpfunc_t(char *);
typedef void rl_vcppfunc_t(char **);

typedef char *rl_cpvfunc_t(void);
typedef char *rl_cpifunc_t(int);
typedef char *rl_cpcpfunc_t(char *);
typedef char *rl_cpcppfunc_t(char **);

enum {
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_tolower_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern const __int32_t **__ctype_toupper_loc(void)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int isalnum(int) __attribute__((__nothrow__, __leaf__));
extern int isalpha(int) __attribute__((__nothrow__, __leaf__));
extern int iscntrl(int) __attribute__((__nothrow__, __leaf__));
extern int isdigit(int) __attribute__((__nothrow__, __leaf__));
extern int islower(int) __attribute__((__nothrow__, __leaf__));
extern int isgraph(int) __attribute__((__nothrow__, __leaf__));
extern int isprint(int) __attribute__((__nothrow__, __leaf__));
extern int ispunct(int) __attribute__((__nothrow__, __leaf__));
extern int isspace(int) __attribute__((__nothrow__, __leaf__));
extern int isupper(int) __attribute__((__nothrow__, __leaf__));
extern int isxdigit(int) __attribute__((__nothrow__, __leaf__));

extern int tolower(int __c) __attribute__((__nothrow__, __leaf__));

extern int toupper(int __c) __attribute__((__nothrow__, __leaf__));

extern int isblank(int) __attribute__((__nothrow__, __leaf__));
extern int isascii(int __c) __attribute__((__nothrow__, __leaf__));

extern int toascii(int __c) __attribute__((__nothrow__, __leaf__));

extern int _toupper(int) __attribute__((__nothrow__, __leaf__));
extern int _tolower(int) __attribute__((__nothrow__, __leaf__));
extern int isalnum_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isalpha_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int iscntrl_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int islower_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isgraph_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isprint_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int ispunct_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isspace_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isupper_l(int, locale_t) __attribute__((__nothrow__, __leaf__));
extern int isxdigit_l(int, locale_t) __attribute__((__nothrow__, __leaf__));

extern int isblank_l(int, locale_t) __attribute__((__nothrow__, __leaf__));

extern int __tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int tolower_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

extern int __toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));
extern int toupper_l(int __c, locale_t __l)
    __attribute__((__nothrow__, __leaf__));

typedef struct _keymap_entry {
  char type;
  rl_command_func_t *function;
} KEYMAP_ENTRY;

typedef KEYMAP_ENTRY KEYMAP_ENTRY_ARRAY[257];
typedef KEYMAP_ENTRY *Keymap;

extern KEYMAP_ENTRY_ARRAY emacs_standard_keymap, emacs_meta_keymap,
    emacs_ctlx_keymap;
extern KEYMAP_ENTRY_ARRAY vi_insertion_keymap, vi_movement_keymap;

extern Keymap rl_make_bare_keymap(void);

extern Keymap rl_copy_keymap(Keymap);

extern Keymap rl_make_keymap(void);

extern void rl_discard_keymap(Keymap);

extern Keymap rl_get_keymap_by_name(const char *);

extern Keymap rl_get_keymap(void);

extern void rl_set_keymap(Keymap);

extern int rl_set_keymap_name(const char *, Keymap);
typedef char *tilde_hook_func_t(char *);

extern tilde_hook_func_t *tilde_expansion_preexpansion_hook;

extern tilde_hook_func_t *tilde_expansion_failure_hook;

extern char **tilde_additional_prefixes;

extern char **tilde_additional_suffixes;

extern char *tilde_expand(const char *);

extern char *tilde_expand_word(const char *);

extern char *tilde_find_word(const char *, int, int *);
enum undo_code { UNDO_DELETE, UNDO_INSERT, UNDO_BEGIN, UNDO_END };

typedef struct undo_list {
  struct undo_list *next;
  int start, end;
  char *text;
  enum undo_code what;
} UNDO_LIST;

extern UNDO_LIST *rl_undo_list;

typedef struct _funmap {
  const char *name;
  rl_command_func_t *function;
} FUNMAP;

extern FUNMAP **funmap;
extern int rl_digit_argument(int, int);
extern int rl_universal_argument(int, int);

extern int rl_forward_byte(int, int);
extern int rl_forward_char(int, int);
extern int rl_forward(int, int);
extern int rl_backward_byte(int, int);
extern int rl_backward_char(int, int);
extern int rl_backward(int, int);
extern int rl_beg_of_line(int, int);
extern int rl_end_of_line(int, int);
extern int rl_forward_word(int, int);
extern int rl_backward_word(int, int);
extern int rl_refresh_line(int, int);
extern int rl_clear_screen(int, int);
extern int rl_clear_display(int, int);
extern int rl_skip_csi_sequence(int, int);
extern int rl_arrow_keys(int, int);

extern int rl_previous_screen_line(int, int);
extern int rl_next_screen_line(int, int);

extern int rl_insert(int, int);
extern int rl_quoted_insert(int, int);
extern int rl_tab_insert(int, int);
extern int rl_newline(int, int);
extern int rl_do_lowercase_version(int, int);
extern int rl_rubout(int, int);
extern int rl_delete(int, int);
extern int rl_rubout_or_delete(int, int);
extern int rl_delete_horizontal_space(int, int);
extern int rl_delete_or_show_completions(int, int);
extern int rl_insert_comment(int, int);

extern int rl_upcase_word(int, int);
extern int rl_downcase_word(int, int);
extern int rl_capitalize_word(int, int);

extern int rl_transpose_words(int, int);
extern int rl_transpose_chars(int, int);

extern int rl_char_search(int, int);
extern int rl_backward_char_search(int, int);

extern int rl_beginning_of_history(int, int);
extern int rl_end_of_history(int, int);
extern int rl_get_next_history(int, int);
extern int rl_get_previous_history(int, int);
extern int rl_operate_and_get_next(int, int);

extern int rl_set_mark(int, int);
extern int rl_exchange_point_and_mark(int, int);

extern int rl_vi_editing_mode(int, int);
extern int rl_emacs_editing_mode(int, int);

extern int rl_overwrite_mode(int, int);

extern int rl_re_read_init_file(int, int);
extern int rl_dump_functions(int, int);
extern int rl_dump_macros(int, int);
extern int rl_dump_variables(int, int);

extern int rl_complete(int, int);
extern int rl_possible_completions(int, int);
extern int rl_insert_completions(int, int);
extern int rl_old_menu_complete(int, int);
extern int rl_menu_complete(int, int);
extern int rl_backward_menu_complete(int, int);

extern int rl_kill_word(int, int);
extern int rl_backward_kill_word(int, int);
extern int rl_kill_line(int, int);
extern int rl_backward_kill_line(int, int);
extern int rl_kill_full_line(int, int);
extern int rl_unix_word_rubout(int, int);
extern int rl_unix_filename_rubout(int, int);
extern int rl_unix_line_discard(int, int);
extern int rl_copy_region_to_kill(int, int);
extern int rl_kill_region(int, int);
extern int rl_copy_forward_word(int, int);
extern int rl_copy_backward_word(int, int);
extern int rl_yank(int, int);
extern int rl_yank_pop(int, int);
extern int rl_yank_nth_arg(int, int);
extern int rl_yank_last_arg(int, int);
extern int rl_bracketed_paste_begin(int, int);

extern int rl_reverse_search_history(int, int);
extern int rl_forward_search_history(int, int);

extern int rl_start_kbd_macro(int, int);
extern int rl_end_kbd_macro(int, int);
extern int rl_call_last_kbd_macro(int, int);
extern int rl_print_last_kbd_macro(int, int);

extern int rl_revert_line(int, int);
extern int rl_undo_command(int, int);

extern int rl_tilde_expand(int, int);

extern int rl_restart_output(int, int);
extern int rl_stop_output(int, int);

extern int rl_abort(int, int);
extern int rl_tty_status(int, int);

extern int rl_history_search_forward(int, int);
extern int rl_history_search_backward(int, int);
extern int rl_history_substr_search_forward(int, int);
extern int rl_history_substr_search_backward(int, int);
extern int rl_noninc_forward_search(int, int);
extern int rl_noninc_reverse_search(int, int);
extern int rl_noninc_forward_search_again(int, int);
extern int rl_noninc_reverse_search_again(int, int);

extern int rl_insert_close(int, int);

extern void rl_callback_handler_install(const char *, rl_vcpfunc_t *);
extern void rl_callback_read_char(void);
extern void rl_callback_handler_remove(void);
extern void rl_callback_sigcleanup(void);

extern int rl_vi_redo(int, int);
extern int rl_vi_undo(int, int);
extern int rl_vi_yank_arg(int, int);
extern int rl_vi_fetch_history(int, int);
extern int rl_vi_search_again(int, int);
extern int rl_vi_search(int, int);
extern int rl_vi_complete(int, int);
extern int rl_vi_tilde_expand(int, int);
extern int rl_vi_prev_word(int, int);
extern int rl_vi_next_word(int, int);
extern int rl_vi_end_word(int, int);
extern int rl_vi_insert_beg(int, int);
extern int rl_vi_append_mode(int, int);
extern int rl_vi_append_eol(int, int);
extern int rl_vi_eof_maybe(int, int);
extern int rl_vi_insertion_mode(int, int);
extern int rl_vi_insert_mode(int, int);
extern int rl_vi_movement_mode(int, int);
extern int rl_vi_arg_digit(int, int);
extern int rl_vi_change_case(int, int);
extern int rl_vi_put(int, int);
extern int rl_vi_column(int, int);
extern int rl_vi_delete_to(int, int);
extern int rl_vi_change_to(int, int);
extern int rl_vi_yank_to(int, int);
extern int rl_vi_yank_pop(int, int);
extern int rl_vi_rubout(int, int);
extern int rl_vi_delete(int, int);
extern int rl_vi_back_to_indent(int, int);
extern int rl_vi_unix_word_rubout(int, int);
extern int rl_vi_first_print(int, int);
extern int rl_vi_char_search(int, int);
extern int rl_vi_match(int, int);
extern int rl_vi_change_char(int, int);
extern int rl_vi_subst(int, int);
extern int rl_vi_overstrike(int, int);
extern int rl_vi_overstrike_delete(int, int);
extern int rl_vi_replace(int, int);
extern int rl_vi_set_mark(int, int);
extern int rl_vi_goto_mark(int, int);

extern int rl_vi_check(void);
extern int rl_vi_domove(int, int *);
extern int rl_vi_bracktype(int);

extern void rl_vi_start_inserting(int, int, int);

extern int rl_vi_fWord(int, int);
extern int rl_vi_bWord(int, int);
extern int rl_vi_eWord(int, int);
extern int rl_vi_fword(int, int);
extern int rl_vi_bword(int, int);
extern int rl_vi_eword(int, int);
extern char *readline(const char *);

extern int rl_set_prompt(const char *);
extern int rl_expand_prompt(char *);

extern int rl_initialize(void);

extern int rl_discard_argument(void);

extern int rl_add_defun(const char *, rl_command_func_t *, int);
extern int rl_bind_key(int, rl_command_func_t *);
extern int rl_bind_key_in_map(int, rl_command_func_t *, Keymap);
extern int rl_unbind_key(int);
extern int rl_unbind_key_in_map(int, Keymap);
extern int rl_bind_key_if_unbound(int, rl_command_func_t *);
extern int rl_bind_key_if_unbound_in_map(int, rl_command_func_t *, Keymap);
extern int rl_unbind_function_in_map(rl_command_func_t *, Keymap);
extern int rl_unbind_command_in_map(const char *, Keymap);
extern int rl_bind_keyseq(const char *, rl_command_func_t *);
extern int rl_bind_keyseq_in_map(const char *, rl_command_func_t *, Keymap);
extern int rl_bind_keyseq_if_unbound(const char *, rl_command_func_t *);
extern int rl_bind_keyseq_if_unbound_in_map(const char *, rl_command_func_t *,
                                            Keymap);
extern int rl_generic_bind(int, const char *, char *, Keymap);

extern char *rl_variable_value(const char *);
extern int rl_variable_bind(const char *, const char *);

extern int rl_set_key(const char *, rl_command_func_t *, Keymap);

extern int rl_macro_bind(const char *, const char *, Keymap);

extern int rl_translate_keyseq(const char *, char *, int *);
extern char *rl_untranslate_keyseq(int);

extern rl_command_func_t *rl_named_function(const char *);
extern rl_command_func_t *rl_function_of_keyseq(const char *, Keymap, int *);
extern rl_command_func_t *rl_function_of_keyseq_len(const char *, size_t,
                                                    Keymap, int *);

extern void rl_list_funmap_names(void);
extern char **rl_invoking_keyseqs_in_map(rl_command_func_t *, Keymap);
extern char **rl_invoking_keyseqs(rl_command_func_t *);

extern void rl_function_dumper(int);
extern void rl_macro_dumper(int);
extern void rl_variable_dumper(int);

extern int rl_read_init_file(const char *);
extern int rl_parse_and_bind(char *);

extern Keymap rl_make_bare_keymap(void);
extern int rl_empty_keymap(Keymap);
extern Keymap rl_copy_keymap(Keymap);
extern Keymap rl_make_keymap(void);
extern void rl_discard_keymap(Keymap);
extern void rl_free_keymap(Keymap);

extern Keymap rl_get_keymap_by_name(const char *);
extern char *rl_get_keymap_name(Keymap);
extern void rl_set_keymap(Keymap);
extern Keymap rl_get_keymap(void);

extern int rl_set_keymap_name(const char *, Keymap);

extern void rl_set_keymap_from_edit_mode(void);
extern char *rl_get_keymap_name_from_edit_mode(void);

extern int rl_add_funmap_entry(const char *, rl_command_func_t *);
extern const char **rl_funmap_names(void);

extern void rl_initialize_funmap(void);

extern void rl_push_macro_input(char *);

extern void rl_add_undo(enum undo_code, int, int, char *);
extern void rl_free_undo_list(void);
extern int rl_do_undo(void);
extern int rl_begin_undo_group(void);
extern int rl_end_undo_group(void);
extern int rl_modifying(int, int);

extern void rl_redisplay(void);
extern int rl_on_new_line(void);
extern int rl_on_new_line_with_prompt(void);
extern int rl_forced_update_display(void);
extern int rl_clear_visible_line(void);
extern int rl_clear_message(void);
extern int rl_reset_line_state(void);
extern int rl_crlf(void);

extern void rl_keep_mark_active(void);

extern void rl_activate_mark(void);
extern void rl_deactivate_mark(void);
extern int rl_mark_active_p(void);

extern int rl_message();

extern int rl_show_char(int);

extern int rl_character_len(int, int);
extern void rl_redraw_prompt_last_line(void);

extern void rl_save_prompt(void);
extern void rl_restore_prompt(void);

extern void rl_replace_line(const char *, int);
extern int rl_insert_text(const char *);
extern int rl_delete_text(int, int);
extern int rl_kill_text(int, int);
extern char *rl_copy_text(int, int);

extern void rl_prep_terminal(int);
extern void rl_deprep_terminal(void);
extern void rl_tty_set_default_bindings(Keymap);
extern void rl_tty_unset_default_bindings(Keymap);

extern int rl_tty_set_echoing(int);
extern int rl_reset_terminal(const char *);
extern void rl_resize_terminal(void);
extern void rl_set_screen_size(int, int);
extern void rl_get_screen_size(int *, int *);
extern void rl_reset_screen_size(void);

extern char *rl_get_termcap(const char *);

extern int rl_stuff_char(int);
extern int rl_execute_next(int);
extern int rl_clear_pending_input(void);
extern int rl_read_key(void);
extern int rl_getc(FILE *);
extern int rl_set_keyboard_input_timeout(int);

extern void rl_extend_line_buffer(int);
extern int rl_ding(void);
extern int rl_alphabetic(int);
extern void rl_free(void *);

extern int rl_set_signals(void);
extern int rl_clear_signals(void);
extern void rl_cleanup_after_signal(void);
extern void rl_reset_after_signal(void);
extern void rl_free_line_state(void);

extern int rl_pending_signal(void);
extern void rl_check_signals(void);

extern void rl_echo_signal_char(int);

extern int rl_set_paren_blink_timeout(int);

extern void rl_clear_history(void);

extern int rl_maybe_save_line(void);
extern int rl_maybe_unsave_line(void);
extern int rl_maybe_replace_line(void);

extern int rl_complete_internal(int);
extern void rl_display_match_list(char **, int, int);

extern char **rl_completion_matches(const char *, rl_compentry_func_t *);
extern char *rl_username_completion_function(const char *, int);
extern char *rl_filename_completion_function(const char *, int);

extern int rl_completion_mode(rl_command_func_t *);
extern const char *rl_library_version;
extern int rl_readline_version;

extern int rl_gnu_readline_p;

extern unsigned long rl_readline_state;

extern int rl_editing_mode;

extern int rl_insert_mode;

extern const char *rl_readline_name;

extern char *rl_prompt;

extern char *rl_display_prompt;

extern char *rl_line_buffer;

extern int rl_point;
extern int rl_end;

extern int rl_mark;

extern int rl_done;

extern int rl_pending_input;

extern int rl_dispatching;

extern int rl_explicit_arg;

extern int rl_numeric_arg;

extern rl_command_func_t *rl_last_func;

extern const char *rl_terminal_name;

extern FILE *rl_instream;
extern FILE *rl_outstream;

extern int rl_prefer_env_winsize;

extern rl_hook_func_t *rl_startup_hook;

extern rl_hook_func_t *rl_pre_input_hook;

extern rl_hook_func_t *rl_event_hook;

extern rl_hook_func_t *rl_signal_event_hook;

extern rl_hook_func_t *rl_input_available_hook;

extern rl_getc_func_t *rl_getc_function;

extern rl_voidfunc_t *rl_redisplay_function;

extern rl_vintfunc_t *rl_prep_term_function;
extern rl_voidfunc_t *rl_deprep_term_function;

extern Keymap rl_executing_keymap;
extern Keymap rl_binding_keymap;

extern int rl_executing_key;
extern char *rl_executing_keyseq;
extern int rl_key_sequence_length;

extern int rl_erase_empty_line;

extern int rl_already_prompted;

extern int rl_num_chars_to_read;

extern char *rl_executing_macro;

extern int rl_catch_signals;

extern int rl_catch_sigwinch;

extern int rl_change_environment;

extern rl_compentry_func_t *rl_completion_entry_function;

extern rl_compentry_func_t *rl_menu_completion_entry_function;

extern rl_compignore_func_t *rl_ignore_some_completions_function;
extern rl_completion_func_t *rl_attempted_completion_function;

extern const char *rl_basic_word_break_characters;

extern char *rl_completer_word_break_characters;

extern rl_cpvfunc_t *rl_completion_word_break_hook;

extern const char *rl_completer_quote_characters;

extern const char *rl_basic_quote_characters;

extern const char *rl_filename_quote_characters;

extern const char *rl_special_prefixes;
extern rl_icppfunc_t *rl_directory_completion_hook;
extern rl_icppfunc_t *rl_directory_rewrite_hook;

extern rl_icppfunc_t *rl_filename_stat_hook;
extern rl_dequote_func_t *rl_filename_rewrite_hook;
extern rl_compdisp_func_t *rl_completion_display_matches_hook;

extern int rl_filename_completion_desired;

extern int rl_filename_quoting_desired;

extern rl_quote_func_t *rl_filename_quoting_function;

extern rl_dequote_func_t *rl_filename_dequoting_function;

extern rl_linebuf_func_t *rl_char_is_quoted_p;

extern int rl_attempted_completion_over;

extern int rl_completion_type;

extern int rl_completion_invoking_key;

extern int rl_completion_query_items;

extern int rl_completion_append_character;

extern int rl_completion_suppress_append;

extern int rl_completion_quote_character;

extern int rl_completion_found_quote;

extern int rl_completion_suppress_quote;

extern int rl_sort_completion_matches;
extern int rl_completion_mark_symlink_dirs;

extern int rl_ignore_completion_duplicates;

extern int rl_inhibit_completion;

extern int rl_persistent_signal_handlers;
struct readline_state {
  int point;
  int end;
  int mark;
  int buflen;
  char *buffer;
  UNDO_LIST *ul;
  char *prompt;

  int rlstate;
  int done;
  Keymap kmap;

  rl_command_func_t *lastfunc;
  int insmode;
  int edmode;
  char *kseq;
  int kseqlen;

  int pendingin;
  FILE *inf;
  FILE *outf;
  char *macro;

  int catchsigs;
  int catchsigwinch;

  rl_compentry_func_t *entryfunc;
  rl_compentry_func_t *menuentryfunc;
  rl_compignore_func_t *ignorefunc;
  rl_completion_func_t *attemptfunc;
  char *wordbreakchars;

  char reserved[64];
};

extern int rl_save_state(struct readline_state *);
extern int rl_restore_state(struct readline_state *);

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;

  long int tm_gmtoff;
  const char *tm_zone;
};

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;

extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));

extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));

extern double difftime(time_t __time1, time_t __time0)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize,
                       const char *__restrict __format,
                       const struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize,
                         const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));

extern struct tm *localtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer,
                           struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));

extern struct tm *localtime_r(const time_t *__restrict __timer,
                              struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));

extern char *ctime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));

extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;

extern char *tzname[2];

extern void tzset(void) __attribute__((__nothrow__, __leaf__));

extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));

extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time,
                     struct timespec *__remaining);

extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));

extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));

extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
                           const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));

extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timer_delete(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));

extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));

extern int timespec_get(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

typedef void *histdata_t;

typedef struct _hist_entry {
  char *line;
  char *timestamp;
  histdata_t data;
} HIST_ENTRY;

typedef struct _hist_state {
  HIST_ENTRY **entries;
  int offset;
  int length;
  int size;
  int flags;
} HISTORY_STATE;
extern void using_history(void);

extern HISTORY_STATE *history_get_history_state(void);

extern void history_set_history_state(HISTORY_STATE *);

extern void add_history(const char *);

extern void add_history_time(const char *);

extern HIST_ENTRY *remove_history(int);

extern HIST_ENTRY **remove_history_range(int, int);

extern HIST_ENTRY *alloc_history_entry(char *, char *);

extern HIST_ENTRY *copy_history_entry(HIST_ENTRY *);

extern histdata_t free_history_entry(HIST_ENTRY *);

extern HIST_ENTRY *replace_history_entry(int, const char *, histdata_t);

extern void clear_history(void);

extern void stifle_history(int);

extern int unstifle_history(void);

extern int history_is_stifled(void);

extern HIST_ENTRY **history_list(void);

extern int where_history(void);

extern HIST_ENTRY *current_history(void);

extern HIST_ENTRY *history_get(int);

extern time_t history_get_time(HIST_ENTRY *);

extern int history_total_bytes(void);

extern int history_set_pos(int);

extern HIST_ENTRY *previous_history(void);

extern HIST_ENTRY *next_history(void);
extern int history_search(const char *, int);

extern int history_search_prefix(const char *, int);

extern int history_search_pos(const char *, int, int);

extern int read_history(const char *);

extern int read_history_range(const char *, int, int);

extern int write_history(const char *);

extern int append_history(int, const char *);

extern int history_truncate_file(const char *, int);
extern int history_expand(char *, char **);

extern char *history_arg_extract(int, int, const char *);

extern char *get_history_event(const char *, int *, int);

extern char **history_tokenize(const char *);

extern int history_base;
extern int history_length;
extern int history_max_entries;
extern int history_offset;

extern int history_lines_read_from_file;
extern int history_lines_written_to_file;

extern char history_expansion_char;
extern char history_subst_char;
extern char *history_word_delimiters;
extern char history_comment_char;
extern char *history_no_expand_chars;
extern char *history_search_delimiter_chars;

extern int history_quotes_inhibit_expansion;
extern int history_quoting_state;

extern int history_write_timestamps;

extern int history_multiline_entries;
extern int history_file_version;

extern int max_input_history;

extern rl_linebuf_func_t *history_inhibit_expansion_function;

uint8_t *guest_to_host(paddr_t paddr);

paddr_t host_to_guest(uint8_t *haddr);

static inline _Bool in_pmem(paddr_t addr) {
  return addr - 0x80000000 < 0x8000000;
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);
typedef sword_t expr_t;

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  char e[256];
  expr_t val;
} WP;

expr_t expr(char *e, _Bool *success);
WP *new_wp();
void free_wp(WP *wp);
WP *get_wp_head();
void wp_display();

static int is_batch_mode = 0;

void init_regex();
void init_wp_pool();
extern void isa_reg_display();

static char *rl_gets() {
  static char *line_read = ((void *)0);

  if (line_read) {
    free(line_read);
    line_read = ((void *)0);
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) { return -1; }

static int cmd_si(char *args) {
  int steps = 1;
  if (args != ((void *)0)) {
    steps = atoi(args);
  }
  cpu_exec(steps);
  return 0;
}

static int cmd_info(char *args) {
  if (args == ((void *)0)) {
    printf("Usage: info <r|w>. r --> register, w --> watch points.\n");
    return 0;
  }
  switch (args[0]) {
    case 'r':
      isa_reg_display();
      break;
    case 'w':
      wp_display();
      break;
  }
  return 0;
}

static int cmd_x(char *args) {
  char *length = strtok(args, " ");
  args = length + strlen(length) + 1;

  _Bool success;
  paddr_t paddr = expr(args, &success);
  if (!success) {
    printf(
        "\33[1;31m"
        "[%s:%d %s] "
        "\33[0m"
        "Invalid Expression!\n",
        "src/monitor/sdb/sdb.c", 88, __func__);
    return 0;
  }
  for (int i = 0; i < atoi(length); i++) {
    ((void)sizeof((((paddr + i >= (paddr_t)0x80000000 &&
                     paddr + i < (paddr_t)0x80000000 + 0x8000000)))
                      ? 1
                      : 0),
     __extension__({
       if (((paddr + i >= (paddr_t)0x80000000 &&
             paddr + i < (paddr_t)0x80000000 + 0x8000000)))
         ;
       else
         __assert_fail("PADDR_VALID(paddr + i)", "src/monitor/sdb/sdb.c", 92,
                       __extension__ __PRETTY_FUNCTION__);
     }));
    printf("%02x ", *guest_to_host(paddr + i));
  }
  printf("\n");
  return 0;
}

static int cmd_p(char *args) {
  _Bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    printf(
        "\33[1;31m"
        "[%s:%d %s] "
        "\33[0m"
        "Invalid Expression\n",
        "src/monitor/sdb/sdb.c", 103, __func__);
    return 0;
  }
  printf(
      "%ld"
      "\n",
      val);
  return 0;
}
static int cmd_px(char *args) {
  _Bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    printf(
        "\33[1;31m"
        "[%s:%d %s] "
        "\33[0m"
        "Invalid Expression\n",
        "src/monitor/sdb/sdb.c", 113, __func__);
    return 0;
  }
  printf("0x%lx\n", val);
  return 0;
}
static int cmd_w(char *args) {
  _Bool success;
  expr_t val = expr(args, &success);
  if (!success) {
    printf(
        "\33[1;31m"
        "[%s:%d %s] "
        "\33[0m"
        "Invalid Expression\n",
        "src/monitor/sdb/sdb.c", 123, __func__);
    return 0;
  }
  WP *new = new_wp();
  memcpy(new->e, args, strlen(args) + 1);
  new->val = val;
  return 0;
}
static int cmd_d(char *args) {
  int NO = atoi(args);

  ((void)sizeof((NO > 0 && NO <= 32) ? 1 : 0), __extension__({
     if (NO > 0 && NO <= 32)
       ;
     else
       __assert_fail("NO > 0 && NO <= 32", "src/monitor/sdb/sdb.c", 133,
                     __extension__ __PRETTY_FUNCTION__);
   }));
  WP *i;
  for (i = get_wp_head(); i; i = i->next) {
    if (NO == i->NO) {
      free_wp(i);
      break;
    }
  }
  if (!i) {
    printf(
        "\33[1;31m"
        "[%s:%d %s] "
        "\33[0m"
        "Watchpoint %d does not exist.\n",
        "src/monitor/sdb/sdb.c", 142, __func__, NO);
  }
  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "Usage: si [N]. Step N instruction, default 1. ", cmd_si},
    {"info", "Usage: info <r|w>. r --> register, w --> watch points. ",
     cmd_info},
    {"x", "Usage: x <number of bytes> <expression>. example: x 10 0x80000000 ",
     cmd_x},
    {"p", "Usage: p <expression>. example: p $s0 + 5 ", cmd_p},
    {"p/x", "Usage: p/x <expression>. example: p/x $s0 + 5 ", cmd_px},
    {"w", "Usage: w <expression>. example: w $s0 + 5 ", cmd_w},
    {"d", "Usage: d <watchpoint NO>. example: d 2", cmd_d},

};

static int cmd_help(char *args) {
  char *arg = strtok(((void *)0), " ");
  int i;

  if (arg == ((void *)0)) {
    for (i = 0; i < (int)(sizeof(cmd_table) / sizeof(cmd_table[0])); i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < (int)(sizeof(cmd_table) / sizeof(cmd_table[0])); i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() { is_batch_mode = 1; }

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(((void *)0));
    return;
  }

  for (char *str; (str = rl_gets()) != ((void *)0);) {
    char *str_end = str + strlen(str);

    char *cmd = strtok(str, " ");
    if (cmd == ((void *)0)) {
      continue;
    }

    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = ((void *)0);
    }

    int i;
    for (i = 0; i < (int)(sizeof(cmd_table) / sizeof(cmd_table[0])); i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          nemu_state.state = NEMU_QUIT;
          return;
        }
        break;
      }
    }

    if (i == (int)(sizeof(cmd_table) / sizeof(cmd_table[0]))) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb() {
  init_regex();

  init_wp_pool();
}
