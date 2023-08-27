#include <proc.h>
#include <elf.h>
#include <fs.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_RISCV64__)
# define EXPECT_ISA EM_RISCV
#elif defined(__x86_64__)
# define EXPECT_ISA EM_X86_64 
#else
# error Unsupported ISA
#endif

static uintptr_t loader(PCB *pcb, const char *filename) {
  int fd = fs_open(filename, 0, 0);

  uintptr_t ret = 0;

  Elf_Ehdr Ehdr;
  fs_read(fd, &Ehdr, sizeof(Elf_Ehdr));
  assert(*(uint32_t *)Ehdr.e_ident == 0x464c457f);
  assert(Ehdr.e_machine == EXPECT_ISA);
  assert(Ehdr.e_type == ET_EXEC);
  ret = Ehdr.e_entry;

  Elf64_Shdr *Shdrs = malloc(sizeof(Elf64_Shdr) * Ehdr.e_shnum);
  fs_lseek(fd, Ehdr.e_shoff, SEEK_SET);
  fs_read(fd, Shdrs, sizeof(Elf64_Shdr) * Ehdr.e_shnum);

  Elf_Phdr *Phdrs = malloc(sizeof(Elf_Phdr) * Ehdr.e_phnum);
  fs_lseek(fd, Ehdr.e_phoff, SEEK_SET);
  fs_read(fd, Phdrs, sizeof(Elf64_Phdr) * Ehdr.e_phnum);

  // copy file into memory
  for (int i = 0; i < Ehdr.e_phnum; i++) {
    if (Phdrs[i].p_type != PT_LOAD) continue;
    fs_lseek(fd, Phdrs[i].p_offset, SEEK_SET);
    fs_read(fd, (void*)Phdrs[i].p_paddr, Phdrs[i].p_filesz);
    memset((void*)(Phdrs[i].p_paddr + Phdrs[i].p_filesz), 0x00, Phdrs[i].p_memsz - Phdrs[i].p_filesz);
  }

  free(Phdrs);
  free(Shdrs);
  fs_close(fd);
  return ret;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  printf("%s\n", filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

