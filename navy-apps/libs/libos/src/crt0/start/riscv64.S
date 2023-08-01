.globl  _start
.type _start, @function
_start:
  move s0, zero
  jal call_main
