%{
#include<bits/stdc++.h>
using namespace std;
stack<int> indent_cnt;
int ns = 0;
#include "helper.hpp"
#include "parser.tab.h"
int eof = 0;
%}

%option yylineno
NL          "\n"
WS          [\t ]+

/*INTEGER*/
DIGIT          [0-9]
BINDIGIT       [0-1]
OCTDIGIT       [0-7]
HEXDIGIT       {DIGIT}|[a-fA-F]

DECINTEGER     [1-9]([_]?{DIGIT})*|0([_]?[0])*
BININTEGER     0[bB]([_]?{BINDIGIT})+
OCTINTEGER     0[oO]([_]?{OCTDIGIT})+
HEXINTEGER     0[Xx]([_]?{HEXDIGIT})+
INTEGER        {DECINTEGER}|{BININTEGER}|{OCTINTEGER}|{HEXINTEGER}

/* FLOAT */
DIGITPART      {DIGIT}([_]?{DIGIT})*
FRACTION       "."{DIGITPART}
EXPONENT       [eE]([+-]?){DIGITPART}
POINTFLOAT     {DIGITPART}?({FRACTION}|({DIGITPART})".")
EXPONENTFLOAT  ({DIGITPART}|{POINTFLOAT}){EXPONENT}
FLOAT          {POINTFLOAT}|{EXPONENTFLOAT}


/* STRING */
STRING                      {SHORT_STRING}|{LONG_STRING}
SHORT_STRING                ([\"]([a-zA-Z]|"\\\n"|{DIGIT}|{CHARACTER_SET}|[\']|[\\][\"])*[\"])|([\']([a-zA-Z]|"\\\n"|{DIGIT}|{CHARACTER_SET}|[\"]|[\\][\'])*[\'])
LONG_STRING                 ([\"][\"][\"]([a-zA-Z]|{DIGIT}|{CHARACTER_SET}|[\\][\"]|[\\][\']|[\']|[\"][^\"]|[\"][\"][^\"]|[\n])*[\"][\"][\"])|([\'][\'][\']([a-zA-Z]|{DIGIT}|{CHARACTER_SET}|[\\][\']|[\\][\"]|[\"]|[\'][^\']|[\'][\'][^\']|[\n])*[\'][\'][\'])
INVALID_STRING              ([\"][^\"])|([\'][^\'])

/* Operators */
PLUS            "+"
MINUS           "-"
MULTIPLY        "*"
EXP             "**"
DIVIDE          "/"
DIVIDEDIVIDE    "//"
MOD             "%"
AT              "@"
RIGHTSHIFT      ">>"
LEFTSHIFT       "<<"
AMPERSAND       "&"
EQUAL           "=="
NOTEQUAL        "!="
GREATER         ">"
LESS            "<"
GREATEREQ       ">="
LESSEQ          "<="
BITOR           "|"
BITXOR          "^"
BITNOT          "~"
ASSIGN          "="
PLUSEQUAL       "+="
MINUSEQUAL      "-="
MULTIPLYEQUAL   "*="
DIVIDEEQUAL     "/="
MODEQUAL    "%="
EXPONENTEQUAL   "**="
ANDEQUAL        "&="
OREQUAL          "|="
XOREQUAL         "^="
LEFTSHIFTEQUAL  "<<="
RIGHTSHIFTEQUAL ">>="
COLONEQUAL      ":="
ELLIPSIS        "..."

/* DELIMITER */

LEFTBRACKET         "("
RIGHTBRACKET        ")"
LEFTSQUAREBRACKET   "["
RIGHTSQUAREBRACKET  "]"
LEFTCURLYBRACKET    "{"
RIGHTCURLYBRACKET   "}"
COMMA               ","
COLON               ":"
SEMICOLON           ";"
DOT                 "."
ARROW               "->"
DIVIDEDIVIDEEQUAL   "//="
ATEQUAL             "@="

/* DUNDERS */                       
NAME_DUNDER                 "__name__"
MAIN_DUNDER                 "__main__"
INIT_DUNDER                 "__init__"

/* HELPER */            
UNDERSCORE                  [\_]
DOUBLE_QUOTE                [\"] 
SINGLE_QUOTE                [\']
BACKSLASH                   \\
SPACE                       [ ]

/*KEYWORDS*/
PRINT     "print"
FALSE      "False"
AWAIT      "await"
ELSE       "else"
IMPORT     "import"
PASS       "pass"
NONE       "None"
BREAK      "break"
EXCEPT     "except"
IN         "in"
RAISE      "raise"
TRUE       "True"
CLASS      "class"
FINALLY    "finally"
IS         "is"
RETURN     "return"
AND        "and"
CONTINUE   "continue"
FOR        "for"
LAMBDA     "lambda"
TRY        "try"
AS         "as"         
DEF        "def"        
FROM       "from"       
NONLOCAL   "nonlocal"   
WHILE      "while"
ASSERT     "assert"     
DEL        "del"        
GLOBAL     "global"     
NOT        "not"        
WITH       "with"
ASYNC      "async"      
ELIF       "elif"       
IF         "if"         
OR         "or"         
YIELD      "yield"
RANGE      "range"

/* Bool */
BOOL   {TRUE}|{FALSE}

/* IDENTIFIERS */

NAME [a-zA-Z_]([a-zA-Z0-9_]*)

COMMENT     "#"([^\n\r])*[\n]

CHARACTER_SET          {AT}|{DIVIDE}|{BITOR}|{PLUS}|{MINUS}|{LEFTSQUAREBRACKET}|{RIGHTSQUAREBRACKET}|{LESS}|{GREATER}|{BITXOR}|{AMPERSAND}|{MOD}|{BITNOT}|{UNDERSCORE}|"\\"|"!"|" "|{LEFTBRACKET}|{RIGHTBRACKET}|{SEMICOLON}|{COLON}|{EQUAL}|{COMMA}|{DOT}|{MULTIPLY}     

%x	indent_state
%s	implicit1
%s  implicit2

%%
<<EOF>> {
    if(eof == 0){
        unput('\n');
        eof = 1;
    }
    else{
        yyterminate();
    }
}
<indent_state>. {
	unput(yytext[0]);
	if(ns > indent_cnt.top()){
		indent_cnt.push(ns);
		BEGIN(INITIAL);
        return INDENT;
	}
	else if(ns == indent_cnt.top()){
		BEGIN(INITIAL);
	}
	else{
		indent_cnt.pop();
        if (ns > indent_cnt.top()) {
            cout << "Indentation error at line number " << yylineno << "\n";
        }
        return DEDENT;
	}
}

<implicit1>{NL} {
}

<implicit1>{RIGHTBRACKET} {
    BEGIN(INITIAL);
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return RIGHTBRACKET;
}
<implicit2>{NL} {
}

<implicit2>{RIGHTSQUAREBRACKET} {
    BEGIN(INITIAL);
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return RIGHTSQUAREBRACKET;
}

{RANGE} {
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return RANGE;
}
{PRINT} {
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return PRINT;
}

{UNDERSCORE} {

    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return UNDERSCORE;
}  

{INTEGER} {
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return INTEGER;
}

{FLOAT} {
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return FLOAT;
}

{PLUS} {
    ////cout<<"PLUS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return PLUS;
}
{MINUS} {
    ////cout<<"MINUS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return MINUS;
}           
{MULTIPLY} {
    ////cout<<"MULTIPLY\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return MULTIPLY;
}       
{EXP} {
    ////cout<<"EXP\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return EXP;
}        
{DIVIDE} {
    ////cout<<"DIVIDE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return DIVIDE;
}          
{DIVIDEDIVIDE} {
   // //cout<<"DIVIDEDIVIDE\n";
   yylval.lex = string(yytext); 
   yylval.lineno = yylineno;
   return DIVIDEDIVIDE;
}    
{MOD} {
    ////cout<<"MOD\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return MOD;
}             
{AT} {
    //cout<<"AT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return AT;
}              
{RIGHTSHIFT} {
    ////cout<< "RIGHTSHIFT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RIGHTSHIFT;
}      
{LEFTSHIFT} {
    ////cout<<"LEFTSHIFT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LEFTSHIFT;
}       
{AMPERSAND} {
    ////cout<< "AMPERSAND\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return AMPERSAND;
}       
{EQUAL} {
    //cout<<"EQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return EQUAL;
}           
{NOTEQUAL} {
    ////cout<<"NOTEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NOTEQUAL;
}        
{GREATER} {
    ///cout<<"GREATER\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return GREATER;
}         
{LESS} {
    //cout<<"LESS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LESS;
}            
{GREATEREQ} {
    //cout<<"GREATEREQ\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return GREATEREQ;
}       
{LESSEQ} {
    //cout<<"LESSEQ\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LESSEQ;
}          
{BITOR} {
    //cout<<"BITOR\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return BITOR;
}           
{BITXOR} {
    //cout<<"BITXOR\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return BITXOR;
}          
{BITNOT} {
    //cout<<"BITNOT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return BITNOT;
}          
{ASSIGN} {
    //cout<<"ASSIGN\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ASSIGN;
}          
{PLUSEQUAL} {
    //cout<<"PLUSEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return PLUSEQUAL;
}       
{MINUSEQUAL} {
    //cout<<"MINUSEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return MINUSEQUAL;
}      
{MULTIPLYEQUAL} {
    //cout<<"MULTIPLYEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return MULTIPLYEQUAL;
}  
{DIVIDEEQUAL} {
    //cout<<"DIVIDEEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return DIVIDEEQUAL;
}    
{MODEQUAL} {
    //cout<<"MODEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return MODEQUAL;
}   
{EXPONENTEQUAL} {
    //cout<<"EXPONENTEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return EXPONENTEQUAL;
}  
{ANDEQUAL} {
    //cout<<"ANDEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ANDEQUAL;
}       
{OREQUAL} {
    //cout<<"OREQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return OREQUAL;
}         
{XOREQUAL} {
    //cout<<"XOREQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return XOREQUAL;
}        
{LEFTSHIFTEQUAL} {
    //cout<<"LEFTSHIFTEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LEFTSHIFTEQUAL;
} 
{RIGHTSHIFTEQUAL} {
    //cout<<"RIGHTSHIFTEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RIGHTSHIFTEQUAL;
} 
{COLONEQUAL} {
    //cout<<"COLONEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return COLONEQUAL;
}
{LEFTBRACKET} {
    //cout<<"LEFTBRACKET\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    BEGIN(implicit1);
   return LEFTBRACKET;
}        
{RIGHTBRACKET} {
    //cout<<"RIGHTBRACKET\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RIGHTBRACKET;
}       
{LEFTSQUAREBRACKET} {
    //cout<<"LEFTSQUAREBRACKET\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    BEGIN(implicit2);
   return LEFTSQUAREBRACKET;
}  
{RIGHTSQUAREBRACKET} {
    //cout<<"RIGHTSQUAREBRACKET\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RIGHTSQUAREBRACKET;
} 
{LEFTCURLYBRACKET} {
    //cout<<"LEFTCURLYBRACKET\n"; 
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LEFTCURLYBRACKET; 
}   
{RIGHTCURLYBRACKET} {
    //cout<<"RIGHTCURLYBRACKET\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RIGHTCURLYBRACKET; 
}  
{COMMA} {
    //cout<<"COMMA\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return COMMA;
}              
{COLON} {
    //cout<<"COLON\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return COLON;
}              
{SEMICOLON} {
    //cout<<"SEMICOLON\n"; 
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return SEMICOLON;
}          
{DOT} {
        //cout<<"DOT\n";
        yylval.lex = string(yytext); 
        yylval.lineno = yylineno;
       return DOT;
}                
{ARROW} {
    //cout<<"ARROW\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ARROW;
}              
{DIVIDEDIVIDEEQUAL} {
    //cout<<"DIVIDEDIVIDEEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return DIVIDEDIVIDEEQUAL;
}  
{ATEQUAL} {
    //cout<<"ATEQUAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ATEQUAL;
}

{NAME_DUNDER} {
    //cout <<"NAME_DUNDER\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NAME;
}              
{MAIN_DUNDER} {
    //cout <<"MAIN_DUNDER\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NAME;
}            
{INIT_DUNDER} {
    //cout <<"INIT_DUNDER\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NAME;
}         
{BACKSLASH} {
    //cout <<"BACKSLASH\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return BACKSLASH;
}                                  
{FALSE} {
    //cout <<"FALSE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return FALSE;
}      
{AWAIT} {
    // cout <<"AWAIT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return AWAIT;
}      
{ELSE} {
    // cout <<"ELSE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ELSE;
}     
{IMPORT} {
   // cout <<"IMPORT\n";
   return IMPORT;
}    
{PASS} {
    // cout <<"PASS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return PASS;
}       
{NONE} {
   // cout <<"NONE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NONE;
}       
{BREAK} {
    // cout <<"BREAK\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return BREAK;
}      
{EXCEPT} {
    // cout <<"EXCEPT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return EXCEPT;
}     
{IN} {
    // cout <<"IN\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return IN;
}         
{RAISE} {
    // cout <<"RAISE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return RAISE;
}      
{TRUE} {
    //cout<<"TRUE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return TRUE;
}       
{CLASS} {
    //cout<<"CLASS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return CLASS;
}     
{FINALLY} {
    //cout<<"FINALLY\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return FINALLY;
}    
{IS} {
    //cout<<"IS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return IS;
}

{RETURN} {
    //cout<< "RETURN\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
    return RETURN;
}     
{AND} {
    //cout<<"AND\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return AND;
}       
{CONTINUE} {
    //cout <<"CONTINUE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return CONTINUE;
}   
{FOR} {
    //cout <<"FOR\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return FOR;
}       
{LAMBDA} {
    //cout <<"LAMBDA\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return LAMBDA;
}    
{TRY} {
    //cout <<"TRY\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return TRY;
}       
{AS} {
    //cout <<"AS\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return AS;
}        
{DEF} {
    //cout <<"DEF\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return DEF;
}              
{FROM} {
    // cout <<"FROM\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return FROM;
}            
{NONLOCAL} {
    // cout <<"NONLOCAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NONLOCAL;
}     
{WHILE} {
    // cout <<"WHILE\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return WHILE;
}     
{ASSERT} {
    // cout <<"ASSERT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ASSERT;
}        
{DEL} {
    // cout <<"DEL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return DEL;
}             
{GLOBAL} {
    // cout <<"GLOBAL\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return GLOBAL;
}        
{NOT} {
    // cout <<"NOT\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NOT;
}               
{WITH} {
    // cout <<"WITH\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return WITH;
}      
{ASYNC} {
    // cout <<"ASYNC\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ASYNC;
}           
{ELIF} {
    // cout <<"ELIF\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return ELIF;
}             
{IF} {
    // cout <<"IF\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return IF;
}                 
{OR} {
    // cout <<"OR\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return OR;
}                 
{YIELD} {
    // cout <<"YIELD\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return YIELD;
}
{NAME} {
    //cout << "NAME\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return NAME;
}

{STRING} {
    //cout<<"STRING\n";
    yylval.lex = string(yytext); 
    yylval.lineno = yylineno;
   return STRING;
}

{SPACE} {
    // cout << "SPACE\n";
    //strcpy(yylval.tok.lex, yytext); 
}
{COMMENT} {

}

{NL} {
    char ch = yyinput();
    ns = 0;
	while(ch ==' ' || ch == '\n'){
		if(ch == '\n'){
                        ns = 0;
                }
		if(ch == ' ') ns++;
		ch = yyinput();
	}

	unput(ch);
    BEGIN(indent_state);
    return NEWLINE;
}

{BACKSLASH}{NL} {
}

. {
    if(yytext[0]!=0) {
    cerr << "Invalid character " << int(yytext[0]) << " at line number " << yylineno << "\n";
    exit(1);
    }
}

%%
int yywrap(){
   return 1;
}
