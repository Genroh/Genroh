.data
L_fmt:
    .ascii  "%x\n\0"
.text
.globl main
main:
    pushl %ebp
    movl  %esp, %ebp
    subl  $8, %esp
    movl  $57, %ebx
    movl  $1234, %eax
    movl  $0, %edx
    negl  %eax
    negl  %edx
    cdq
    idivl %ebx
    pushl %eax
    pushl $L_fmt
    call  printf
    addl  $8, %esp
    leave
    ret
