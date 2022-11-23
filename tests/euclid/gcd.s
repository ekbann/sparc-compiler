	.global printf
	.align	4
	.global	gcd
gcd:	save	%sp, STACK_SPACE, %sp
	ba	L0002
	nop
L0001:
	cmp	%i0, %i1
	bge	L0003
	clr	%o0
	mov	1, %o0
L0003:
	tst	%o0
	be	L0004
	nop
	st	%i0, [%fp-4]
	mov	%i1, %i0
	ld	[%fp-4], %o0
	mov	%o0, %i1
L0004:
	sub	%i0, %i1, %o0
	mov	%o0, %i0
L0002:
	mov	0, %o1
	cmp	%i0, %o1
	ble	L0005
	clr	%o1
	mov	1, %o1
L0005:
	tst	%o1
	bne	L0001
	nop
	ret
	restore	%g0, %i1, %o0
	STACK_SPACE = -96
