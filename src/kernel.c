//#include <vga.h>
#include <stddef.h>
#include <stdint.h>
#include "multiboot.h"
#include "arch/x86/serial.h"
#include <stdio.h>

FILE sP; //serial filepointer
FILE* s = &sP;

char* k_l2h(unsigned long, char*);
void _asm_regdump();

void kprint_crashdump( //I wish I could make this smaller
    unsigned long EFLAGS,
    unsigned long EDI,
    unsigned long ESI,
    unsigned long EBP,
    unsigned long ESP,
    unsigned long EBX,
    unsigned long EDX,
    unsigned long ECX,
    unsigned long EAX) {
  fprintf(s, "CRASH CONDITION DETECTED!\n\n"); //TODO: change this to stderr once it's implemented
  fprintf(s, "EAX: 0x%08x  EBX: 0x%08x  ", EAX, EBX);
  fprintf(s, "ECX: 0x%08x  EDX: 0x%08x\n", ECX, EDX);
  fprintf(s, "ESP: 0x%08x  EBP: 0x%08x  ", ESP, EBP);
  fprintf(s, "ESI: 0x%08x  EDI: 0x%08x\n", ESI, EDI);
  fprintf(s, "EFLAGS: 0x%08x\n", EFLAGS);
}

void kernel_init(multiboot_info_t* mboot, unsigned long magic) {
  s = fopen_serial(s);

  if(magic != 0x2BADB002) {
    fprintf(s, "There was a bootloader error, please reboot using GRUB\n"); //magical debug code!
    fprintf(s, "Expected: 0x2BADB002, Got: 0x%08x\n", magic);
    return;
  }

  fprintf(s, "Hello, kernel!\n");
  fprintf(s, "I'm a new line!\n");
  _asm_regdump();
  fprintf(s, "\nThat was a test crash, Everything looks good!\n");
}
