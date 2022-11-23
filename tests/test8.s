	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	1, %o0
	st	%o0, [%fp-4]
	ld	[%fp-4], %o0
	mov	7, %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-8]
	ld	[%fp-4], %o0
	inc	%o0
	st	%o0, [%fp-4]
	inc	%l0
	ld	[%fp-4], %o0
	mov	7, %o1
	call	.div
	nop
	sub	%l0, %o0, %o0
	st	%o0, [%fp-8]
	ld	[%fp-4], %o0
	inc	%o0
	st	%o0, [%fp-4]
	ret
	restore
	STACK_SPACE = -104
