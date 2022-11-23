	.common ary, 40, 4
	.align	4
	.global	sort
sort:	save	%sp, STACK_SPACE, %sp
	mov	%i0, %o0
	mov	2, %o1
	call	.div
	nop
	st	%o0, [%fp-4]
	ba	L0002
	nop
L0001:
	ld	[%fp-4], %o0
	st	%o0, [%fp-8]
	ba	L0004
	nop
L0003:
	ld	[%fp-8], %o0
	ld	[%fp-4], %o1
	sub	%o0, %o1, %o0
	st	%o0, [%fp-12]
	ba	L0006
	nop
L0005:
	ld	[%fp-12], %o0
	sll	%o0, 2, %o0
	set	ary, %o1
	add	%o1, %o0, %o0
	ld	[%o0], %o0
	st	%o0, [%fp-16]
	ld	[%fp-12], %o0
	ld	[%fp-4], %o1
	add	%o0, %o1, %o0
	sll	%o0, 2, %o0
	set	ary, %o1
	add	%o1, %o0, %o0
	ld	[%o0], %o0
	ld	[%fp-12], %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	ld	[%fp-16], %o0
	ld	[%fp-12], %o1
	ld	[%fp-4], %o2
	add	%o1, %o2, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	ld	[%fp-12], %o0
	ld	[%fp-4], %o1
	sub	%o0, %o1, %o0
	st	%o0, [%fp-12]
L0006:
	ld	[%fp-12], %o1
	mov	0, %o2
	cmp	%o1, %o2
	bl	L0007
	clr	%o1
	mov	1, %o1
L0007:
	tst	%o1
	be	L0008
	clr	%o1
	ld	[%fp-12], %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	ld	[%o1], %o1
	ld	[%fp-12], %o2
	ld	[%fp-4], %o3
	add	%o2, %o3, %o2
	sll	%o2, 2, %o2
	set	ary, %o3
	add	%o3, %o2, %o2
	ld	[%o2], %o2
	cmp	%o1, %o2
	ble	L0009
	clr	%o1
	mov	1, %o1
L0009:
	tst	%o1
	be	L0008
	clr	%o1
	mov	1, %o1
L0008:
	tst	%o1
	bne	L0005
	nop
	ld	[%fp-8], %o0
	ld	[%fp-8], %o0
	inc	%o0
	st	%o0, [%fp-8]
L0004:
	ld	[%fp-8], %o0
	cmp	%o0, %i0
	bge	L0010
	clr	%o0
	mov	1, %o0
L0010:
	tst	%o0
	bne	L0003
	nop
	ld	[%fp-4], %o0
	mov	2, %o1
	call	.div
	nop
	st	%o0, [%fp-4]
L0002:
	ld	[%fp-4], %o1
	mov	0, %o2
	cmp	%o1, %o2
	ble	L0011
	clr	%o1
	mov	1, %o1
L0011:
	tst	%o1
	bne	L0001
	nop
	ret
	restore
	STACK_SPACE = -112
