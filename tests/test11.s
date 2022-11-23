	.global printf
C0001:	.asciz	"%d\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	10, %o0
	st	%o0, [%fp-4]
	ba	L0002
	nop
L0001:
	set	C0001, %o0
	ld	[%fp-4], %o1
	call	printf
	nop
	ld	[%fp-4], %o0
	ld	[%fp-4], %o0
	dec	%o0
	st	%o0, [%fp-4]
L0002:
	ld	[%fp-4], %o0
	mov	0, %o1
	cmp	%o0, %o1
	ble	L0003
	clr	%o0
	mov	1, %o0
L0003:
	tst	%o0
	bne	L0001
	nop
	ret
	restore
	STACK_SPACE = -96
