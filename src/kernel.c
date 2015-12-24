#include <vga.h>
#include <stddef.h>
#include <stdint.h>
#include <multiboot.h>

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
  char buf[16];
  term_putstr("CRASH CONDITION DETECTED!\n\n");
  term_putstr("EAX: 0x"); term_putstr(k_l2h(EAX, buf)); term_putstr("  EBX: 0x"); term_putstr(k_l2h(EBX, buf));
  term_putstr("  ECX: 0x"); term_putstr(k_l2h(ECX, buf)); term_putstr("  EDX: 0x"); term_putstr(k_l2h(EDX, buf)); term_putchar('\n');
  term_putstr("ESP: 0x"); term_putstr(k_l2h(ESP, buf)); term_putstr("  EBP: 0x"); term_putstr(k_l2h(EBP, buf));
  term_putstr("  ESI: 0x"); term_putstr(k_l2h(ESI, buf)); term_putstr("  EDI: 0x"); term_putstr(k_l2h(EDI, buf)); term_putchar('\n');
  term_putstr("EFLAGS: 0x"); term_putstr(k_l2h(EFLAGS, buf)); term_putchar('\n');
}

char* k_l2h(unsigned long val, char* buf) {
  unsigned long tempval;
  tempval = val;
  const char* lookup = "0123456789ABCDEF";
  for( size_t i = 0; i < 8; i++ ) {
    buf[i] = lookup[ (tempval & 0xF0000000) >> 28 ];
    buf[i+1] = '\0';
    tempval = tempval << 4;
  }
  return buf;
}

void kernel_init(multiboot_info_t* mboot, unsigned long magic) {
  term_init();
  char buf[16];
  if(magic != 0x2BADB002) {
    term_putstr("There was a bootloader error, please reboot using GRUB\n"); //magical debug code!
    term_putstr("Expected: 0x2BADB002, Got: 0x"); term_putstr(k_l2h(magic, buf));
    return;
  }

  term_putstr("Hello, kernel!\n");
  term_putstr("I'm a new line!\n");
  _asm_regdump();
  term_putstr("\nThat was a test crash, Everything looks good!\n");
}
