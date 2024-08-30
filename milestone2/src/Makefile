all : parser_exec

parser_exec: lex.yy.c parser.tab.c helper.hpp
	g++ lex.yy.c parser.tab.c -o parser_exec

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d -t -v parser.y

clean: 
	rm -f lex.yy.c parser.tab.c parser.tab.h parser_exec parser.output  *.csv *.txt 
