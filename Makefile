objects = CC.tab.o lex.yy.o support.o code.o 


clean:
	rm CC.tab.c
	rm CC.tab.h
	rm lex.yy.c
	rm *.o
	rm CC