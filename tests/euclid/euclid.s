	.global printf
	.global scanf
	.global gcd
C0001:	.asciz	"%d %d"
C0002:	.asciz	"Greatest common divisor of %d and %d is %d.\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	1, %o0
	sub	%g0, %o0, %o0
	st	%o0, [%fp-12]
	mov	200, %o0
	st	%o0, [%fp-4]
	mov	300, %o0
	st	%o0, [%fp-8]
	ba	L0002
	nop
L0001:
	ld	[%fp-4], %o0
	mov	0, %o1
	cmp	%o0, %o1
	ble	L0003
	clr	%o0
	mov	1, %o0
L0003:
	tst	%o0
	be	L0004
	clr	%o0
	ld	[%fp-8], %o0
	mov	0, %o1
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
	tst	%o0
	be	L0006
	nop
	set	C0002, %o0
	ld	[%fp-4], %o1
	ld	[%fp-8], %o2
	st	%o1, [%fp-4]
	st	%o2, [%fp-8]
	ld	[%fp-4], %o0
	ld	[%fp-8], %o1
	call	gcd
	nop
	st	%o0, [%fp-16]
	set	C0002, %o0
	ld	[%fp-4], %o1
	ld	[%fp-8], %o2
	ld	[%fp-16], %o3
	call	printf
	nop
L0006:
L0002:
	st	%o0, [%fp-20]
	set	C0001, %o0
	add	%fp, -4, %o1
	add	%fp, -8, %o2
	call	scanf
	nop
	ld	[%fp-12], %o1
	cmp	%o0, %o1
	be	L0007
	clr	%o0
	mov	1, %o0
L0007:
	tst	%o0
	bne	L0001
	nop
	ret
	restore
	STACK_SPACE = -112
