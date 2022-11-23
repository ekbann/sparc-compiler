	.global printf
C0001:	.asciz	"a[0] = %d\n"
C0002:	.asciz	"a[1] = %d\n"
C0003:	.asciz	"a[2] = %d\n"
C0004:	.asciz	"a[3] = %d\n"
C0005:	.asciz	"a[4] = %d\n"
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	mov	1, %o0
	mov	0, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	st	%o0, [%fp+%o1]
	mov	2, %o0
	mov	1, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	st	%o0, [%fp+%o1]
	mov	3, %o0
	mov	2, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	st	%o0, [%fp+%o1]
	mov	4, %o0
	mov	3, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	st	%o0, [%fp+%o1]
	mov	5, %o0
	mov	4, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	st	%o0, [%fp+%o1]
	set	C0001, %o0
	mov	0, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	ld	[%fp+%o1], %o1
	call	printf
	nop
	set	C0002, %o0
	mov	1, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	ld	[%fp+%o1], %o1
	call	printf
	nop
	set	C0003, %o0
	mov	2, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	ld	[%fp+%o1], %o1
	call	printf
	nop
	set	C0004, %o0
	mov	3, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	ld	[%fp+%o1], %o1
	call	printf
	nop
	set	C0005, %o0
	mov	4, %o1
	sll	%o1, 2, %o1
	add	-20, %o1, %o1
	ld	[%fp+%o1], %o1
	call	printf
	nop
	ret
	restore
	STACK_SPACE = -112
