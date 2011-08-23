	.file	"zero.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0,	%eax
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"TCC 0.0.1"
	.section	.note.GNU-stack,"",@progbits
