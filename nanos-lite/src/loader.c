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

static uintptr_t loader(PCB *pcb, const char *filename) {
  uintptr_t ret = 0;
  int first = 1;

  uint32_t magic;
  ramdisk_read(&magic, 0, 4);
  assert(magic == 0x464c457f);

  Elf_Ehdr Ehdr;
  ramdisk_read(&Ehdr, 0, sizeof(Elf_Ehdr));

  Elf64_Shdr *Shdrs = malloc(sizeof(Elf64_Shdr) * Ehdr.e_shnum);
  ramdisk_read(Shdrs, Ehdr.e_shoff, sizeof(Elf64_Shdr) * Ehdr.e_shnum);

  Elf_Phdr *Phdrs = malloc(sizeof(Elf_Phdr) * Ehdr.e_phnum);
  ramdisk_read(Phdrs, Ehdr.e_phoff, sizeof(Elf_Phdr) * Ehdr.e_phnum);

  for (int i = 0; i < Ehdr.e_phnum; i++) {
    if (Phdrs[i].p_type != PT_LOAD) continue;
    // find the valid offset
    for (int j = 0; j < Ehdr.e_shnum; j++) {
      if (Shdrs[i].sh_offset >= Phdrs[i].p_offset && Shdrs[i].sh_type != SHT_NULL) {
        if (first) {
          first = 0;
          ret = Phdrs[i].p_paddr;
        }
        ramdisk_read((void*)Phdrs[i].p_paddr, Shdrs[i].sh_offset, Phdrs[i].p_filesz);
        memset((void*)(Phdrs[i].p_paddr + Phdrs[i].p_filesz), 0x00, Phdrs[i].p_memsz - Phdrs[i].p_filesz);
      }
    }
  }
  free(Phdrs);
  free(Shdrs);
  assert(ret != 0);
  return ret;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

