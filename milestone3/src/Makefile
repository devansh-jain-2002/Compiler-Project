all : parser_exec

parser_exec: lex.yy.c parser.tab.c helper.hpp
	g++ -std=c++17 lex.yy.c parser.tab.c -o milestone3

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d -t -v parser.y

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h milestone3 parser.output *.csv *.txt *.o *.3ac *.s
