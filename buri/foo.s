	.data
L_fmt:
	.ascii "%d\n\0"
	.text
	.global main
main:
	pushl %ebp
	movl  %esp, %ebp
	subl  $16, %esp
	movl  $0, -12(%ebp)
	movl  $0, -4(%ebp)
	movl  $0, %edx
	movl  $1, -8(%ebp)
	movl  -8(%ebp), %eax
	imull $10, %eax
	addl  $0, %eax
	movl  %eax, -8(%ebp)
	movl  -12(%ebp), %eax
	addl  -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  $2, -8(%ebp)
	movl  -12(%ebp), %eax
	imull -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  -4(%ebp), %eax
	addl  -12(%ebp), %eax
	movl  %eax, -4(%ebp)
	movl  $4, -8(%ebp)
	movl  $0, -12(%ebp)
	movl  -8(%ebp), %eax
	imull $10, %eax
	addl  $0, %eax
	movl  %eax, -8(%ebp)
	movl  -12(%ebp), %eax
	addl  -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  $4, -8(%ebp)
	movl  -12(%ebp), %eax
	cltd
	idivl -8(%ebp)
	movl  %eax, -12(%ebp)
	movl  -4(%ebp), %eax
	addl  -12(%ebp), %eax
	movl  %eax, -4(%ebp)
	movl  $1, -8(%ebp)
	movl  $0, -12(%ebp)
	movl  -8(%ebp), %eax
	imull $10, %eax
	addl  $5, %eax
	movl  %eax, -8(%ebp)
	movl  -12(%ebp), %eax
	addl  -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  $2, -8(%ebp)
	movl  -12(%ebp), %eax
	imull -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  $3, -8(%ebp)
	movl  -12(%ebp), %eax
	imull -8(%ebp), %eax
	movl  %eax, -12(%ebp)
	movl  -4(%ebp), %eax
	addl  -12(%ebp), %eax
	movl  %eax, -4(%ebp)
	movl  -4(%ebp), %eax
	movl  %eax, -12(%ebp)
	pushl -12(%ebp)
	pushl $L_fmt
	call  printf
	addl  $8, %esp
	leave
	ret
