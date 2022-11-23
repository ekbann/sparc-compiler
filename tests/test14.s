	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	3, %o0
	mov	3, %o0
	sub	%g0, %o0, %o0
	ld	[%fp-4], %o0
	mov	3, %o1
	add	%o0, %o1, %o0
	ld	[%fp-4], %o0
	st	%o0, [%fp-4]
	mov	3, %o0
	ld	[%fp-8], %o1
	call	.mul
	nop
	ld	[%fp-4], %o1
	add	%o1, %o0, %o0
	mov	4, %o1
	sub	%o0, %o1, %o0
	ld	[%fp-4], %o0
	mov	3, %o1
	add	%o0, %o1, %o0
	ld	[%fp-8], %o1
	mov	4, %o2
	sub	%o1, %o2, %o1
	call	.div
	nop
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	cmp	%o0, %o1
	ble	L0001
	clr	%o0
	mov	1, %o0
L0001:
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	mov	4, %o2
	add	%o1, %o2, %o1
	cmp	%o0, %o1
	bg	L0002
	clr	%o0
	mov	1, %o0
L0002:
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	cmp	%o0, %o1
	bge	L0003
	clr	%o0
	mov	1, %o0
L0003:
	tst	%o0
	be	L0004
	clr	%o0
	ld	[%fp-12], %o0
	mov	4, %o1
	cmp	%o0, %o1
	ble	L0005
	clr	%o0
	mov	1, %o0
L0005:
	tst	%o0
	be	L0004
	clr	%o0
	mov	1, %o0
L0004:
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	cmp	%o0, %o1
	bge	L0006
	clr	%o0
	mov	1, %o0
L0006:
	tst	%o0
	be	L0007
	clr	%o0
	ld	[%fp-12], %o0
	mov	4, %o1
	cmp	%o0, %o1
	ble	L0008
	clr	%o0
	mov	1, %o0
L0008:
	tst	%o0
	be	L0007
	clr	%o0
	mov	1, %o0
L0007:
	tst	%o0
	bne	L0009
	mov	1, %o0
	ld	[%fp-4], %o0
	mov	3, %o1
	cmp	%o0, %o1
	bne	L0010
	clr	%o0
	mov	1, %o0
L0010:
	tst	%o0
	bne	L0009
	mov	1, %o0
	clr	%o0
L0009:
	ld	[%fp-8], %o0
	mov	3, %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-4]
	ld	[%fp-12], %o0
	mov	2, %o1
	sub	%o0, %o1, %o0
	st	%o0, [%fp-8]
	st	%o0, [%fp-4]
L0011:
	ld	[%fp-8], %o0
	mov	3, %o0
	tst	%o0
	bne	L0011
	nop
	ba	L0013
	nop
L0012:
	ld	[%fp-8], %o0
	ld	[%fp-8], %o0
	dec	%o0
	st	%o0, [%fp-8]
	ld	[%fp-12], %o0
	inc	%o0
	st	%o0, [%fp-12]
L0013:
	ld	[%fp-4], %o1
	mov	4, %o2
	cmp	%o1, %o2
	be	L0014
	clr	%o1
	mov	1, %o1
L0014:
	tst	%o1
	bne	L0012
	nop
	mov	3, %o0
	st	%o0, [%fp-4]
	ba	L0016
	nop
L0015:
	ld	[%fp-8], %o0
	mov	3, %o1
	call	.rem
	nop
	st	%o0, [%fp-4]
	ld	[%fp-4], %o0
	ld	[%fp-4], %o0
	dec	%o0
	st	%o0, [%fp-4]
L0016:
	ld	[%fp-4], %o0
	mov	20, %o1
	cmp	%o0, %o1
	bge	L0017
	clr	%o0
	mov	1, %o0
L0017:
	tst	%o0
	bne	L0015
	nop
	tst	%g0
	be	L0018
	nop
	mov	3, %o0
	mov	4, %o1
	call	.mul
	nop
	st	%o0, [%fp-4]
L0018:
	ld	[%fp-8], %o0
	tst	%o0
	be	L0019
	nop
	ld	[%fp-4], %o0
	st	%o0, [%fp-16]
	ba	L0020
	nop
L0019:
	ld	[%fp-4], %o0
L0020:
	ld	[%fp-4], %o0
	dec	%o0
	st	%o0, [%fp-4]
	ld	[%fp-12], %o0
	st	%o0, [%fp-12]
	mov	3, %o0
	mov	4, %o1
	call	.mul
	nop
	ld	[%fp-12], %o1
	sub	%o1, %o0, %o0
	ret
	restore	%g0, %o0, %o0
	STACK_SPACE = -112
