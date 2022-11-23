	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	ld	[%fp-8], %o0
	ld	[%fp-12], %o1
	ld	[%fp-16], %o2
	ld	[%fp-20], %o3
	ld	[%fp-24], %o4
	ld	[%fp-28], %o5
	add	%o4, %o5, %o4
	add	%o3, %o4, %o3
	add	%o2, %o3, %o2
	add	%o1, %o2, %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-4]
	ld	[%fp-8], %o0
	ld	[%fp-12], %o1
	ld	[%fp-16], %o2
	ld	[%fp-20], %o3
	ld	[%fp-24], %o4
	ld	[%fp-28], %o5
	st	%o0, [%fp-8]
	st	%o1, [%fp-12]
	st	%o2, [%fp-16]
	st	%o3, [%fp-20]
	st	%o4, [%fp-24]
	st	%o5, [%fp-28]
	ld	[%fp-32], %o0
	ld	[%fp-36], %o1
	add	%o0, %o1, %o0
	ld	[%fp-28], %o1
	add	%o1, %o0, %o0
	ld	[%fp-24], %o1
	add	%o1, %o0, %o0
	ld	[%fp-20], %o1
	add	%o1, %o0, %o0
	ld	[%fp-16], %o1
	add	%o1, %o0, %o0
	ld	[%fp-12], %o1
	add	%o1, %o0, %o0
	ld	[%fp-8], %o1
	add	%o1, %o0, %o0
	st	%o0, [%fp-4]
	ret
	restore
	STACK_SPACE = -128
