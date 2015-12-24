# Declare multiboot constants
# TODO: Change to Multiboot2 spec
.set ALIGN,   1<<0
.set MEMINFO, 1<<1
.set FLAGS,   ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

#Declare the multiboot section
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

#Declare a 16k initial stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384
stack_top:

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

