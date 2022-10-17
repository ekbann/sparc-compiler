all:
	bison -d CC.y
	flex CC.l
	gcc -g lex.yy.c -c
	gcc -g support.c -c 2>log


clean:
	rm CC.tab.c
	rm CC.tab.h
	rm lex.yy.c
	rm *.o
	rm CC