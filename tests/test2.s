	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	add	%o0, %o1, %o0
	ld	[%fp-12], %o1
	add	%o0, %o1, %o0
	ld	[%fp-16], %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-4]
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	add	%o0, %o1, %o0
	ld	[%fp-12], %o1
	ld	[%fp-16], %o2
	add	%o1, %o2, %o1
	call	.mul
	nop
	st	%o0, [%fp-4]
	ret
	restore
	STACK_SPACE = -112
