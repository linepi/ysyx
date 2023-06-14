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
  uintptr_t ret = 0;

  Elf_Ehdr Ehdr;
  ramdisk_read(&Ehdr, 0, sizeof(Elf_Ehdr));
  assert(*(uint32_t *)Ehdr.e_ident == 0x464c457f);
  assert(Ehdr.e_machine == EXPECT_ISA);
  assert(Ehdr.e_type == ET_EXEC);
  ret = Ehdr.e_entry;

  Elf64_Shdr *Shdrs = malloc(sizeof(Elf64_Shdr) * Ehdr.e_shnum);
  ramdisk_read(Shdrs, Ehdr.e_shoff, sizeof(Elf64_Shdr) * Ehdr.e_shnum);

  Elf_Phdr *Phdrs = malloc(sizeof(Elf_Phdr) * Ehdr.e_phnum);
  ramdisk_read(Phdrs, Ehdr.e_phoff, sizeof(Elf_Phdr) * Ehdr.e_phnum);

  // copy file into memory
  for (int i = 0; i < Ehdr.e_phnum; i++) {
    if (Phdrs[i].p_type != PT_LOAD) continue;
    ramdisk_read((void*)Phdrs[i].p_paddr, Phdrs[i].p_offset, Phdrs[i].p_filesz);
    memset((void*)(Phdrs[i].p_paddr + Phdrs[i].p_filesz), 0x00, Phdrs[i].p_memsz - Phdrs[i].p_filesz);
  }

  free(Phdrs);
  free(Shdrs);
  return ret;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

