#ifndef _MUTLIBOOT_H
#define _MULTIBOOT_H
#include <stdint.h>

/* Multiboot compliant structures */
typedef struct aout_symbol_table {
  uint32_t tabsize;
  uint32_t strsize;
  uint32_t addr;
  uint32_t reserved;
} aout_symbol_table_t;

typedef struct elf_section_header_table {
  uint32_t num;
  uint32_t size;
  uint32_t addr;
  uint32_t shndx;
} elf_section_header_table_t;

typedef struct multiboot_info {
  uint32_t flags;
  uint32_t mem_lower;
  uint32_t mem_upper;
  uint32_t boot_device;
  uint32_t cmdline;
  uint32_t mods_count;
  uint32_t mods_addr;
  union {
    aout_symbol_table_t aout_sym;
    elf_section_header_table_t elf_sec;
  } u;
  uint32_t mmap_length;
  uint32_t mmap_addr;
} multiboot_info_t;

typedef struct mmap {
  uint32_t size;
  uint32_t base_addr_low;
  uint32_t base_addr_high;
  uint32_t length_low;
  uint32_t length_high;
  uint32_t type;
} mmap_t;

#endif
