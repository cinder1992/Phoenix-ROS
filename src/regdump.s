.section .text
.global _asm_regdump
.type _asm_regdump, @function

_asm_regdump:
  push %ebp
  mov %esp, %ebp
  pushal
  pushfl
  call kprint_crashdump
  leave
  ret

.size _asm_regdump, . - _asm_regdump

