	.global printf
C0001:	.asciz	"i = %d\n"
C0002:	.asciz	"a[2*i] = i+4*i-i = %d\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	2, %o0
	st	%o0, [%fp-4]
	ld	[%fp-4], %o0
	st	%o0, [%fp-4]
	mov	4, %o0
	ld	[%fp-4], %o1
	call	.mul
	nop
	ld	[%fp-4], %o1
	add	%o1, %o0, %o0
	ld	[%fp-4], %o1
	sub	%o0, %o1, %o0
	st	%o0, [%fp-28]
	mov	2, %o0
	ld	[%fp-4], %o1
	call	.mul
	nop
	sll	%o0, 2, %o0
	add	-24, %o0, %o0
	ld	[%fp-28], %o1
	st	%o1, [%fp+%o0]
	set	C0001, %o0
	ld	[%fp-4], %o1
	call	printf
	nop
	set	C0002, %o0
	mov	2, %o0
	ld	[%fp-4], %o1
	call	.mul
	nop
	sll	%o0, 2, %o0
	add	-24, %o0, %o0
	ld	[%fp+%o0], %o0
	st	%o0, [%fp-32]
	set	C0002, %o0
	ld	[%fp-32], %o1
	call	printf
	nop
	ret
	restore
	STACK_SPACE = -128
