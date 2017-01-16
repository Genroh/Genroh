	.file	"add5.c"
	.text
	.globl	add5
	.type	add5, @function
add5:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$5, %eax
	popl	%ebp
	ret
	.size	add5, .-add5
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-11)"
	.section	.note.GNU-stack,"",@progbits
