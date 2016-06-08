.include "multiboot_header.s"
.include "bootstrap_stack.s"

#Declare our code segment and entry vector
.section .text
.global _start
.type _start, @function

_start:
  movl $stack_top, %esp #Set up the stack we created earlier
  pushl $0
  popf  #clear the flag register

  pushl %eax
  pushl %ebx  #Push the multiboot info and checksum to the stack
  call kernel_init  #Call the C-code for our kernel with the stack parameters.

  cli #Jump into an inifinite loop should our kernel_main return
  hlt
.Lhang:
  jmp .Lhang

.size _start, . - _start #Set the size of the symbol.

