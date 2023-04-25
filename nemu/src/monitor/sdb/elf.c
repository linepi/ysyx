#include <elf.h>
#include <common.h>
#include <sdb.h>

FILE *elf_fp = NULL;
struct elfinfo_t elfinfo = {};

#ifdef CONFIG_FTRACE
struct functbl_t functbl = {};
#endif

// the function will modify file offset 
bool is_elf(FILE *e) {
  if (!e) return false;
  Elf64_Ehdr Ehdr;
  fseek(e, 0, SEEK_SET);
  if (fread(&Ehdr, sizeof(Elf64_Ehdr), 1, e) != 1) {
    Error("Error read Ehdr\n");
    return false;
  }
  return Ehdr.e_ident[0] == 0x7f &&
         Ehdr.e_ident[1] == 0x45 &&
         Ehdr.e_ident[2] == 0x4c &&
         Ehdr.e_ident[3] == 0x46;
}

void init_elf(const char *elf_file) {
  if (!elf_file) return;
  elf_fp = fopen(elf_file, "rb");;
  if (elf_fp && is_elf(elf_fp)) {
    Log("Elf is specified with %s", elf_file); 
    /* make elfinfo */
    if (fread(&elfinfo.Ehdr, sizeof(Elf64_Ehdr), 1, elf_fp) != 1) {
      Error("Error read Ehdr");
      return;
    }
    fseek(elf_fp, elfinfo.Ehdr.e_shoff, SEEK_SET);
    // malloc space for Shdr
    elfinfo.Shdr = (Elf64_Shdr *)malloc(sizeof(Elf64_Shdr) * elfinfo.Ehdr.e_shnum);
    if (!elfinfo.Shdr) {
      Error("Error malloc shdr");
      return;
    }
    if (fread(elfinfo.Shdr, sizeof(Elf64_Shdr), elfinfo.Ehdr.e_shnum, elf_fp) != elfinfo.Ehdr.e_shnum) {
      Error("Error read Shdr");
      return;
    }
    // get section header of shstrtab
    elfinfo.Shdr_shstrtab = &elfinfo.Shdr[elfinfo.Ehdr.e_shstrndx];
    // find section header of symtab and strtab in all section headers
    for (size_t i = 0; i < elfinfo.Ehdr.e_shnum; i++){
      if (elfinfo.Shdr[i].sh_type == SHT_SYMTAB) {
        elfinfo.Shdr_symtab = &elfinfo.Shdr[i];
        break;
      }
    }
    for (size_t i = 0; i < elfinfo.Ehdr.e_shnum; i++){
      if (elfinfo.Shdr[i].sh_type == SHT_STRTAB) {
        elfinfo.Shdr_strtab = &elfinfo.Shdr[i];
        break;
      }
    }
    assert(elfinfo.Shdr_symtab && elfinfo.Shdr_shstrtab && elfinfo.Shdr_strtab);
    elfinfo.nr_sym = elfinfo.Shdr_symtab->sh_size / elfinfo.Shdr_symtab->sh_entsize;
    fseek(elf_fp, elfinfo.Shdr_symtab->sh_offset, SEEK_SET);
    // malloc space for sym
    elfinfo.Sym = (Elf64_Sym *)malloc(sizeof(Elf64_Sym) * elfinfo.nr_sym);
    if (!elfinfo.Sym) {
      Error("Error malloc sym");
      return;
    }
    if (fread(elfinfo.Sym, sizeof(Elf64_Sym), elfinfo.nr_sym, elf_fp) != elfinfo.nr_sym) {
      Error("Error read sym");
      return;
    }

    fseek(elf_fp, elfinfo.Shdr_strtab->sh_offset, SEEK_SET);
    for (int i = 0; i < elfinfo.nr_sym; i++) {
      printf("%d: 0x%016lx, name = %d, related string: ", i, elfinfo.Sym[i].st_value, elfinfo.Sym[i].st_name);
      // go to place where the name is located
      fseek(elf_fp, elfinfo.Sym[i].st_name + elfinfo.Shdr_strtab->sh_offset, SEEK_SET); 
      char c;
      while ((c = fgetc(elf_fp)) != 0) {
        putchar(c);
      }
      printf("\n");
    }
  }
  else { 
    Log("No elf file specified");
  }
}



static void test() {
  FILE *e = fopen("/home/w/dev/ysyx-workbench/am-kernels/tests/cpu-tests/build/string-riscv64-nemu.elf", "rb");;
  Elf64_Ehdr Ehdr;
  fread(&Ehdr, sizeof(Elf64_Ehdr), 1, e);
  is_elf(e);

  // go to the section headers' location
  Elf64_Shdr Shdr[Ehdr.e_shnum];
  fseek(e, Ehdr.e_shoff, SEEK_SET);
  // read section headers
  fread(Shdr, sizeof(Elf64_Shdr), Ehdr.e_shnum, e);
  // get section header of shstrtab
  Elf64_Shdr *Shdr_shstrtab = &Shdr[Ehdr.e_shstrndx];
  // go to the shstrtab location
  fseek(e, Shdr_shstrtab->sh_offset, SEEK_SET);
  // print the content of shstrtab
  for (size_t i = 0; i < Shdr_shstrtab->sh_size; i++)
    printf("%c", fgetc(e));

  // find section header of symtab and strtab in all section headers
  Elf64_Shdr *Shdr_symtab;
  for (size_t i = 0; i < Ehdr.e_shnum; i++){
    if (Shdr[i].sh_type == SHT_SYMTAB) {
      Shdr_symtab = &Shdr[i];
      break;
    }
  }
  Elf64_Shdr *Shdr_strtab;
  for (size_t i = 0; i < Ehdr.e_shnum; i++){
    if (Shdr[i].sh_type == SHT_STRTAB) {
      Shdr_strtab = &Shdr[i];
      break;
    }
  }
  // go to the symtab location and read
  size_t nr_sym = Shdr_symtab->sh_size / Shdr_symtab->sh_entsize;
  Elf64_Sym Sym[nr_sym];
  fseek(e, Shdr_symtab->sh_offset, SEEK_SET);
  fread(Sym, sizeof(Elf64_Sym), nr_sym, e);
  // then go to strtab location
  fseek(e, Shdr_strtab->sh_offset, SEEK_SET);
  for (int i = 0; i < nr_sym; i++) {
    printf("%d: 0x%016lx, name = %d, related string: ", i, Sym[i].st_value, Sym[i].st_name);
    // go to place where the name is located
    fseek(e, Sym[i].st_name + Shdr_strtab->sh_offset, SEEK_SET); 
    char c;
    while ((c = fgetc(e)) != 0) {
      putchar(c);
    }
    printf("\n");
  }

  fclose(e);
}