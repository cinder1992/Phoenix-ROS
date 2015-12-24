#include <vga.h>
#include <stddef.h>
#include <stdint.h>
#include <multiboot.h>

void kernel_init(multiboot_info_t* mboot, unsigned long magic) {
  term_init();

  if(magic != 0x2BADB002) {
    term_putstr("There was a bootloader error, please reboot using GRUB");
    return;
  }

  term_putstr("Hello, kernel!");
}
