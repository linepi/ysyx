#include <elf.h>
#include <common.h>
#include <sdb.h>

FILE *elf_fp = NULL;
struct elfinfo_t elfinfo = {};

#ifdef CONFIG_FTRACE
struct func_t *functbl = NULL;
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
    fseek(elf_fp, 0, SEEK_SET);
    if (fread(&elfinfo.Ehdr, sizeof(Elf64_Ehdr), 1, elf_fp) != 1) {
      Error("Error read Ehdr");
      return;
    }
    fseek(elf_fp, elfinfo.Ehdr.e_shoff, SEEK_SET);
    // malloc space for Shdr
    elfinfo.Shdr = (Elf64_Shdr *)wmalloc(sizeof(Elf64_Shdr) * elfinfo.Ehdr.e_shnum);
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
    elfinfo.Sym = (Elf64_Sym *)wmalloc(sizeof(Elf64_Sym) * elfinfo.nr_sym);
    if (!elfinfo.Sym) {
      Error("Error malloc sym");
      return;
    }
    if (fread(elfinfo.Sym, sizeof(Elf64_Sym), elfinfo.nr_sym, elf_fp) != elfinfo.nr_sym) {
      Error("Error read sym");
      return;
    }
    /* end of elfinfo making */
    IFDEF(CONFIG_FTRACE, make_functbl());
    // for (int i = 0; !functbl[i].end; i++) {
    //   printf("func addr 0x%016lx, func name %s\n", functbl[i].addr, functbl[i].name);
    // }
  }
  else { 
    Log("No elf file specified");
  }
}

void make_functbl() {
  int func_cnt = 0;
  int idx = 0;
  for (size_t i = 0; i < elfinfo.nr_sym; i++) {
    if (ELF64_ST_TYPE(elfinfo.Sym[i].st_info) == STT_FUNC) func_cnt++;
  }
  functbl = (struct func_t*)wmalloc(sizeof(struct func_t) * (func_cnt + 1));
  assert(functbl != NULL);
  for (size_t i = 0; i < elfinfo.nr_sym; i++) {
    if (ELF64_ST_TYPE(elfinfo.Sym[i].st_info) == STT_FUNC) {
      int j = 0;
      char c;
      functbl[idx].addr = elfinfo.Sym[i].st_value;
      fseek(elf_fp, elfinfo.Shdr_strtab->sh_offset + elfinfo.Sym[i].st_name, SEEK_SET); 
      while ((c = fgetc(elf_fp)) != '\0') {
        functbl[idx].name[j++] = c;
      }
      functbl[idx].name[j] = '\0';
      functbl[idx].end = false;
      idx++;
    }
  }
  functbl[idx].end = true;
}