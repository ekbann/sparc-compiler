	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	5, %o0
	st	%o0, [%fp-4]
	mov	2, %o0
	st	%o0, [%fp-8]
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	call	.mul
	nop
	ld	[%fp-8], %o1
	add	%o0, %o1, %o0
	tst	%o0
	be	L0001
	nop
	mov	1, %o0
	st	%o0, [%fp-12]
	mov	2, %o0
	st	%o0, [%fp-16]
	st	%o0, [%fp-20]
	ba	L0002
	nop
L0001:
	mov	3, %o0
	st	%o0, [%fp-12]
	mov	4, %o0
	st	%o0, [%fp-16]
L0002:
	ret
	restore
	STACK_SPACE = -112
