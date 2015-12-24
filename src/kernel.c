#include <vga.h>
#include <stddef.h>
#include <stdint.h>
#include <multiboot.h>

void kernel_long_to_hex(unsigned long val, char* buf) {
  unsigned long tempval;
  tempval = val;
  const char* lookup = "0123456789ABCDEF";
  for( size_t i = 0; i < 8; i++ ) {
    buf[i] = lookup[ (tempval & 0xF0000000) >> 28 ];
    buf[i+1] = '\0';
    tempval = tempval << 4;
  }
}

void kernel_init(multiboot_info_t* mboot, unsigned long magic) {
  term_init();
  char buf[16];
  if(magic != 0x2BADB002) {
    term_putstr("There was a bootloader error, please reboot using GRUB"); //magical debug code!
    term_x = 0;
    term_y = 1; //dirty hack because /n isn't supported yet.
    term_putstr("Expected: 0x2BADB002, Got: 0x");
    kernel_long_to_hex(magic, buf);
    term_putstr(buf);
    term_x = 0; term_y++;
    term_putstr("Magic value: 0x"); kernel_long_to_hex(magic, buf); term_putstr(buf);
    term_x = 0; term_y++;
    term_putstr("infopointer: 0x"); kernel_long_to_hex((unsigned long)mboot, buf); term_putstr(buf);
    return;
  }

  term_putstr("Hello, kernel!");
}
