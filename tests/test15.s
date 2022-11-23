	.global bas
	.global baa
	.align	4
	.global	foo
foo:	save	%sp, STACK_SPACE, %sp
	add	%fp, -20, %o0
	mov	4, %o1
	sll	%o1, 2, %o1
	add	%o0, %o1, %o0
	st	%o0, [%fp-40]
	st	%g0, [%fp-4]
	st	%g0, [%fp-14]
	st	%g0, [%fp-20]
	ld	[%fp-36], %o0
	ld	[%fp-12], %o1
	add	%o0, %o1, %o0
	ld	[%fp+%o0], %o0
	st	%o0, [%fp-4]
	st	%g0, [%fp-4]
	st	%g0, [%fp-20]
	ret
	restore	%g0, %g0, %o0
	STACK_SPACE = -136
