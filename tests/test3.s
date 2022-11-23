	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	ld	[%fp-12], %o0
	ld	[%fp-16], %o1
	call	.div
	nop
	ld	[%fp-20], %o1
	call	.mul
	nop
	add	%l1, %o0, %o0
	mov	%o0, %l0
	ret
	restore
	STACK_SPACE = -112
