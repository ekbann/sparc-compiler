UNAME := $(shell uname -s)

all:
	bison -d CC.y
	clang -g CC.tab.c -c 2> tab.log
	flex CC.l
	clang -g lex.yy.c -c 2> lex.log
	clang -g support.c -c 2> support.log
	clang -g code.c -c 2> code.log
ifeq ($(UNAME), Linux)
	clang -g CC.tab.o lex.yy.o support.o code.o -o CC -lfl
endif
ifeq ($(UNAME), Darwin)
	clang -g CC.tab.o lex.yy.o support.o code.o -o CC -ll
endif

clean:
	rm CC.tab.c
	rm CC.tab.h
	rm lex.yy.c
	rm *.o
	rm *.s
	rm *.log
	rm CC
