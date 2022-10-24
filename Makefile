all:
	bison -d CC.y
	gcc -g CC.tab.c -c
	flex CC.l
	gcc -g lex.yy.c -c
	gcc -g support.c -c 2> support.log
	gcc -g code.c -c 2> code.log
	gcc -g CC.tab.o lex.yy.o support.o code.o -o CC -lfl

clean:
	rm CC.tab.c
	rm CC.tab.h
	rm lex.yy.c
	rm *.o
	rm *.log
	rm CC
