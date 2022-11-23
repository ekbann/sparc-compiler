	.global printf
	.global putchar
	.common ary, 40, 4
C0001:	.asciz	"%4d"
	.align	4
	.global	dump_array
dump_array:	save	%sp, STACK_SPACE, %sp
	mov	0, %o0
	st	%o0, [%fp-4]
	ba	L0002
	nop
L0001:
	set	C0001, %o0
	ld	[%fp-4], %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	ld	[%o1], %o1
	call	printf
	nop
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
	mov	10, %o0
	call	putchar
	nop
	ret
	restore
	STACK_SPACE = -96
