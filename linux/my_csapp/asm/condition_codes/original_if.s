absdiff:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	.L2
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	jmp	.L3
.L2:
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
.L3:
	popl	%ebp
	ret
