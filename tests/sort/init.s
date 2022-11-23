	.common ary, 40, 4
	.align	4
	.global	init
init:	save	%sp, STACK_SPACE, %sp
	mov	1, %o0
	mov	0, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	5, %o0
	mov	1, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	6, %o0
	mov	2, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	4, %o0
	mov	3, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	7, %o0
	mov	4, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	8, %o0
	mov	5, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	9, %o0
	mov	6, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	0, %o0
	mov	7, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	2, %o0
	mov	8, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	mov	3, %o0
	mov	9, %o1
	sll	%o1, 2, %o1
	set	ary, %o2
	add	%o2, %o1, %o1
	st	%o0, [%o1]
	ret
	restore
	STACK_SPACE = -96
