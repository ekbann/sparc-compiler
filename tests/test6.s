	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	cmp	%o0, %o1
	bge	L0001
	clr	%o0
	mov	1, %o0
L0001:
	tst	%o0
	be	L0002
	clr	%o0
	ld	[%fp-8], %o0
	tst	%o0
	be	L0002
	clr	%o0
	mov	1, %o0
L0002:
	tst	%o0
	be	L0003
	nop
	ld	[%fp-4], %o0
	st	%o0, [%fp-4]
	ld	[%fp-8], %o0
	mov	3, %o1
	call	.mul
	nop
	ld	[%fp-12], %o1
	call	.div
	nop
	ld	[%fp-4], %o1
	add	%o1, %o0, %o0
	st	%o0, [%fp-4]
	st	%o0, [%fp-16]
	ba	L0004
	nop
L0003:
	ld	[%fp-8], %o0
	sub	%g0, %o0, %o0
	tst	%o0
	bne	L0005
	mov	1, %o0
	ld	[%fp-12], %o0
	tst	%o0
	bne	L0005
	mov	1, %o0
	clr	%o0
L0005:
	st	%o0, [%fp-4]
L0004:
	ret
	restore
	STACK_SPACE = -112
