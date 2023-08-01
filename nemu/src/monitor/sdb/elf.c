#include <sdb.h>

FILE *image_elf_fp;
FILE *user_elf_fp;
struct func_t *functbl;
static struct elfinfo_t *image_elfinfo;
static struct elfinfo_t *user_elfinfo;

// the function will modify file offset 
static bool is_elf(FILE *e) {
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

static struct elfinfo_t *_init_elf(const char *elf_file, bool user) {
  if (!elf_file) {
    Log("No elf file specified");
    return NULL;
  }
  FILE *elf_fp = fopen(elf_file, "rb");
  if (elf_fp && is_elf(elf_fp)) {
    if (user) user_elf_fp = elf_fp;
    else image_elf_fp = elf_fp;

    struct elfinfo_t *elfinfo = wmalloc(sizeof(struct elfinfo_t));
    Log("Elf is specified with %s", elf_file); 
    /* make elfinfo */
    fseek(elf_fp, 0, SEEK_SET);
    if (fread(&elfinfo->Ehdr, sizeof(Elf64_Ehdr), 1, elf_fp) != 1) {
      Error("Error read Ehdr");
      return NULL;
    }
    fseek(elf_fp, elfinfo->Ehdr.e_shoff, SEEK_SET);
    // malloc space for Shdr
    elfinfo->Shdr = (Elf64_Shdr *)wmalloc(sizeof(Elf64_Shdr) * elfinfo->Ehdr.e_shnum);
    if (!elfinfo->Shdr) {
      Error("Error malloc shdr");
      return NULL;
    }
    if (fread(elfinfo->Shdr, sizeof(Elf64_Shdr), elfinfo->Ehdr.e_shnum, elf_fp) != elfinfo->Ehdr.e_shnum) {
      Error("Error read Shdr");
      return NULL;
    }
    // get section header of shstrtab
    elfinfo->Shdr_shstrtab = &elfinfo->Shdr[elfinfo->Ehdr.e_shstrndx];
    // find section header of symtab and strtab in all section headers
    for (size_t i = 0; i < elfinfo->Ehdr.e_shnum; i++){
      if (elfinfo->Shdr[i].sh_type == SHT_SYMTAB) {
        elfinfo->Shdr_symtab = &elfinfo->Shdr[i];
        break;
      }
    }
    for (size_t i = 0; i < elfinfo->Ehdr.e_shnum; i++){
      if (elfinfo->Shdr[i].sh_type == SHT_STRTAB) {
        elfinfo->Shdr_strtab = &elfinfo->Shdr[i];
        break;
      }
    }
    assert(elfinfo->Shdr_symtab && elfinfo->Shdr_shstrtab && elfinfo->Shdr_strtab);
    elfinfo->nr_sym = elfinfo->Shdr_symtab->sh_size / elfinfo->Shdr_symtab->sh_entsize;
    fseek(elf_fp, elfinfo->Shdr_symtab->sh_offset, SEEK_SET);
    // malloc space for sym
    elfinfo->Sym = (Elf64_Sym *)wmalloc(sizeof(Elf64_Sym) * elfinfo->nr_sym);
    if (!elfinfo->Sym) {
      Error("Error malloc sym");
      return NULL;
    }
    if (fread(elfinfo->Sym, sizeof(Elf64_Sym), elfinfo->nr_sym, elf_fp) != elfinfo->nr_sym) {
      Error("Error read sym");
      return NULL;
    }
    return elfinfo;
  } else { 
    Log("Elf file open failed or invalid elf file: %s\n", elf_file);
    return NULL;
  }
}

void init_elf(const char *image_elf_file, const char *user_elf_file) {
  image_elfinfo = _init_elf(image_elf_file, false);
  user_elfinfo = _init_elf(user_elf_file, true);

  int func_cnt = 0;
  if (image_elfinfo) {
    for (size_t i = 0; i < image_elfinfo->nr_sym; i++) {
      if (ELF64_ST_TYPE(image_elfinfo->Sym[i].st_info) == STT_FUNC) func_cnt++;
    }
  }
  if (user_elfinfo) {
    for (size_t i = 0; i < user_elfinfo->nr_sym; i++) {
      if (ELF64_ST_TYPE(user_elfinfo->Sym[i].st_info) == STT_FUNC) func_cnt++;
    }
  }
  functbl = (struct func_t*)wmalloc(sizeof(struct func_t) * (func_cnt + 1));
  assert(functbl != NULL);

  if (image_elfinfo)
    build_functbl(image_elfinfo, false);
  if (user_elfinfo)
    build_functbl(user_elfinfo, true);
}
