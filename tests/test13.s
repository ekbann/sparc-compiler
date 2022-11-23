	.global printf
	.common ary, 40, 4
C0001:	.asciz	"ary[%d] = %d\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	0, %o0
	st	%o0, [%fp-4]
	ba	L0002
	nop
L0001:
	ld	[%fp-4], %o0
	mov	1, %o1
	add	%o0, %o1, %o0
	ld	[%fp-4], %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	ld	[%fp-4], %o0
	ld	[%fp-4], %o0
	inc	%o0
	st	%o0, [%fp-4]
L0002:
	ld	[%fp-4], %o0
	mov	10, %o1
	cmp	%o0, %o1
	bge	L0003
	clr	%o0
	mov	1, %o0
L0003:
	tst	%o0
	bne	L0001
	nop
	mov	0, %o0
	st	%o0, [%fp-4]
	ba	L0005
	nop
L0004:
	set	C0001, %o0
	ld	[%fp-4], %o1
	ld	[%fp-4], %o2
	sll	%o2, 2, %o2
	set	ary, %o3
	add	%o3, %o2, %o2
	ld	[%o2], %o2
	call	printf
	nop
	ld	[%fp-4], %o0
	ld	[%fp-4], %o0
	inc	%o0
	st	%o0, [%fp-4]
L0005:
	ld	[%fp-4], %o0
	mov	10, %o1
	cmp	%o0, %o1
	bge	L0006
	clr	%o0
	mov	1, %o0
L0006:
	tst	%o0
	bne	L0004
	nop
	ret
	restore
	STACK_SPACE = -96
