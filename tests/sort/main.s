	.global printf
	.global putchar
	.global init
	.global dump_array
	.global sort
	.common ary, 40, 4
	.align	4
	.global	main
main:	save	%sp, STACK_SPACE, %sp
	call	init
	nop
	call	dump_array
	nop
	mov	10, %o0
	call	sort
	nop
	call	dump_array
	nop
	mov	0, %o0
	ret
	restore	%g0, %o0, %o0
	STACK_SPACE = -104
