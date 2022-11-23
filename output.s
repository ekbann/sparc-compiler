	.global printf
C0001:	.asciz	"a=%d, b=%d\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	0, %o0
	st	%o0, [%fp-4]
	mov	0, %o0
	st	%o0, [%fp-8]
	mov	1, %o0
	st	%o0, [%fp-12]
	mov	2, %o0
	st	%o0, [%fp-16]
	set	C0001, %o0
	ld	[%fp-16], %o1
	ld	[%fp-12], %o2
	call	printf
	nop
	mov	3, %o0
	st	%o0, [%fp-20]
	set	C0001, %o0
	ld	[%fp-4], %o1
	ld	[%fp-20], %o2
	call	printf
	nop
	set	C0001, %o0
	ld	[%fp-4], %o1
	ld	[%fp-12], %o2
	call	printf
	nop
	set	C0001, %o0
	ld	[%fp-4], %o1
	ld	[%fp-8], %o2
	call	printf
	nop
	ret
	restore
	STACK_SPACE = -112
