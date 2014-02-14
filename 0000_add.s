	.file	"0000_add.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d %d"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4016, %rsp
	leaq	-4016(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, -4004(%rbp)
	jmp	.L2
.L3:
	leaq	-4008(%rbp), %rdx
	leaq	-4012(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-4012(%rbp), %edx
	movl	-4008(%rbp), %eax
	addl	%eax, %edx
	movl	-4004(%rbp), %eax
	cltq
	movl	%edx, -4000(%rbp,%rax,4)
	addl	$1, -4004(%rbp)
.L2:
	movl	-4016(%rbp), %eax
	cmpl	%eax, -4004(%rbp)
	jl	.L3
	movl	$0, -4004(%rbp)
	jmp	.L4
.L5:
	movl	-4004(%rbp), %eax
	cltq
	movl	-4000(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4004(%rbp)
.L4:
	movl	-4016(%rbp), %eax
	cmpl	%eax, -4004(%rbp)
	jl	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
