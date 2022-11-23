	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	ld	[%fp-12], %o0
	tst	%o0
	be	L0001
	nop
	ld	[%fp-4], %o0
	ld	[%fp-12], %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-4]
	st	%o0, [%fp-16]
	ba	L0002
	nop
L0001:
	ld	[%fp-4], %o0
	st	%o0, [%fp-8]
L0002:
	ret
	restore
	STACK_SPACE = -112
