%{
#include<bits/stdc++.h>
using namespace std;
stack<int> indent_cnt;
int ns = 0;
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
FLOATNUMBER    {POINTFLOAT}|{EXPONENTFLOAT}

NUMBER         {INTEGER}|{FLOATNUMBER}

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
PERCENTEQUAL    "%="
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
    strcpy(yylval.tok.lex, yytext); 
    return RIGHTBRACKET;
}
<implicit2>{NL} {
}

<implicit2>{RIGHTSQUAREBRACKET} {
    BEGIN(INITIAL);
    strcpy(yylval.tok.lex, yytext); 
    return RIGHTSQUAREBRACKET;
}

{UNDERSCORE} {

    strcpy(yylval.tok.lex, yytext); 
    return UNDERSCORE;
}  

{NUMBER} {
    strcpy(yylval.tok.lex, yytext); 
    return NUMBER;
}

{PLUS} {
    ////cout<<"PLUS\n";
    strcpy(yylval.tok.lex, yytext); 
    return PLUS;
}
{MINUS} {
    ////cout<<"MINUS\n";
    strcpy(yylval.tok.lex, yytext); 
   return MINUS;
}           
{MULTIPLY} {
    ////cout<<"MULTIPLY\n";
    strcpy(yylval.tok.lex, yytext); 
    return MULTIPLY;
}       
{EXP} {
    ////cout<<"EXP\n";
    strcpy(yylval.tok.lex, yytext); 
    return EXP;
}        
{DIVIDE} {
    ////cout<<"DIVIDE\n";
    strcpy(yylval.tok.lex, yytext); 
   return DIVIDE;
}          
{DIVIDEDIVIDE} {
   // //cout<<"DIVIDEDIVIDE\n";
   strcpy(yylval.tok.lex, yytext); 
   return DIVIDEDIVIDE;
}    
{MOD} {
    ////cout<<"MOD\n";
    strcpy(yylval.tok.lex, yytext); 
   return MOD;
}             
{AT} {
    //cout<<"AT\n";
    strcpy(yylval.tok.lex, yytext); 
   return AT;
}              
{RIGHTSHIFT} {
    ////cout<< "RIGHTSHIFT\n";
    strcpy(yylval.tok.lex, yytext); 
   return RIGHTSHIFT;
}      
{LEFTSHIFT} {
    ////cout<<"LEFTSHIFT\n";
    strcpy(yylval.tok.lex, yytext); 
   return LEFTSHIFT;
}       
{AMPERSAND} {
    ////cout<< "AMPERSAND\n";
    strcpy(yylval.tok.lex, yytext); 
   return AMPERSAND;
}       
{EQUAL} {
    //cout<<"EQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return EQUAL;
}           
{NOTEQUAL} {
    ////cout<<"NOTEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return NOTEQUAL;
}        
{GREATER} {
    ///cout<<"GREATER\n";
    strcpy(yylval.tok.lex, yytext); 
   return GREATER;
}         
{LESS} {
    //cout<<"LESS\n";
    strcpy(yylval.tok.lex, yytext); 
   return LESS;
}            
{GREATEREQ} {
    //cout<<"GREATEREQ\n";
    strcpy(yylval.tok.lex, yytext); 
   return GREATEREQ;
}       
{LESSEQ} {
    //cout<<"LESSEQ\n";
    strcpy(yylval.tok.lex, yytext); 
   return LESSEQ;
}          
{BITOR} {
    //cout<<"BITOR\n";
    strcpy(yylval.tok.lex, yytext); 
   return BITOR;
}           
{BITXOR} {
    //cout<<"BITXOR\n";
    strcpy(yylval.tok.lex, yytext); 
   return BITXOR;
}          
{BITNOT} {
    //cout<<"BITNOT\n";
    strcpy(yylval.tok.lex, yytext); 
   return BITNOT;
}          
{ASSIGN} {
    //cout<<"ASSIGN\n";
    strcpy(yylval.tok.lex, yytext); 
   return ASSIGN;
}          
{PLUSEQUAL} {
    //cout<<"PLUSEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return PLUSEQUAL;
}       
{MINUSEQUAL} {
    //cout<<"MINUSEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return MINUSEQUAL;
}      
{MULTIPLYEQUAL} {
    //cout<<"MULTIPLYEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return MULTIPLYEQUAL;
}  
{DIVIDEEQUAL} {
    //cout<<"DIVIDEEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return DIVIDEEQUAL;
}    
{PERCENTEQUAL} {
    //cout<<"PERCENTEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return PERCENTEQUAL;
}   
{EXPONENTEQUAL} {
    //cout<<"EXPONENTEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return EXPONENTEQUAL;
}  
{ANDEQUAL} {
    //cout<<"ANDEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return ANDEQUAL;
}       
{OREQUAL} {
    //cout<<"OREQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return OREQUAL;
}         
{XOREQUAL} {
    //cout<<"XOREQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return XOREQUAL;
}        
{LEFTSHIFTEQUAL} {
    //cout<<"LEFTSHIFTEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return LEFTSHIFTEQUAL;
} 
{RIGHTSHIFTEQUAL} {
    //cout<<"RIGHTSHIFTEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return RIGHTSHIFTEQUAL;
} 
{COLONEQUAL} {
    //cout<<"COLONEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return COLONEQUAL;
}
{LEFTBRACKET} {
    //cout<<"LEFTBRACKET\n";
    strcpy(yylval.tok.lex, yytext); 
    BEGIN(implicit1);
   return LEFTBRACKET;
}        
{RIGHTBRACKET} {
    //cout<<"RIGHTBRACKET\n";
    strcpy(yylval.tok.lex, yytext); 
   return RIGHTBRACKET;
}       
{LEFTSQUAREBRACKET} {
    //cout<<"LEFTSQUAREBRACKET\n";
    strcpy(yylval.tok.lex, yytext); 
    BEGIN(implicit2);
   return LEFTSQUAREBRACKET;
}  
{RIGHTSQUAREBRACKET} {
    //cout<<"RIGHTSQUAREBRACKET\n";
    strcpy(yylval.tok.lex, yytext); 
   return RIGHTSQUAREBRACKET;
} 
{LEFTCURLYBRACKET} {
    //cout<<"LEFTCURLYBRACKET\n"; 
    strcpy(yylval.tok.lex, yytext); 
   return LEFTCURLYBRACKET; 
}   
{RIGHTCURLYBRACKET} {
    //cout<<"RIGHTCURLYBRACKET\n";
    strcpy(yylval.tok.lex, yytext);  
   return RIGHTCURLYBRACKET; 
}  
{COMMA} {
    //cout<<"COMMA\n";
    strcpy(yylval.tok.lex, yytext); 
   return COMMA;
}              
{COLON} {
    //cout<<"COLON\n";
    strcpy(yylval.tok.lex, yytext); 
   return COLON;
}              
{SEMICOLON} {
    //cout<<"SEMICOLON\n"; 
    strcpy(yylval.tok.lex, yytext); 
   return SEMICOLON;
}          
{DOT} {
        //cout<<"DOT\n";
        strcpy(yylval.tok.lex, yytext); 
       return DOT;
}                
{ARROW} {
    //cout<<"ARROW\n";
    strcpy(yylval.tok.lex, yytext); 
   return ARROW;
}              
{DIVIDEDIVIDEEQUAL} {
    //cout<<"DIVIDEDIVIDEEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return DIVIDEDIVIDEEQUAL;
}  
{ATEQUAL} {
    //cout<<"ATEQUAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return ATEQUAL;
}

{NAME_DUNDER} {
    //cout <<"NAME_DUNDER\n";
    strcpy(yylval.tok.lex, yytext); 
   return NAME;
}              
{MAIN_DUNDER} {
    //cout <<"MAIN_DUNDER\n";
    strcpy(yylval.tok.lex, yytext); 
   return NAME;
}            
{INIT_DUNDER} {
    //cout <<"INIT_DUNDER\n";
    strcpy(yylval.tok.lex, yytext); 
   return NAME;
}         
{BACKSLASH} {
    //cout <<"BACKSLASH\n";
    strcpy(yylval.tok.lex, yytext); 
   return BACKSLASH;
}                                  
{FALSE} {
    //cout <<"FALSE\n";
    strcpy(yylval.tok.lex, yytext); 
   return FALSE;
}      
{AWAIT} {
    // cout <<"AWAIT\n";
    strcpy(yylval.tok.lex, yytext); 
   return AWAIT;
}      
{ELSE} {
    // cout <<"ELSE\n";
    strcpy(yylval.tok.lex, yytext); 
   return ELSE;
}     
{IMPORT} {
   // cout <<"IMPORT\n";
   strcpy(yylval.tok.lex, yytext); 
   return IMPORT;
}    
{PASS} {
    // cout <<"PASS\n";
    strcpy(yylval.tok.lex, yytext); 
   return PASS;
}       
{NONE} {
   // cout <<"NONE\n";
   strcpy(yylval.tok.lex, yytext); 
   return NONE;
}       
{BREAK} {
    // cout <<"BREAK\n";
    strcpy(yylval.tok.lex, yytext); 
   return BREAK;
}      
{EXCEPT} {
    // cout <<"EXCEPT\n";
    strcpy(yylval.tok.lex, yytext); 
   return EXCEPT;
}     
{IN} {
    // cout <<"IN\n";
    strcpy(yylval.tok.lex, yytext); 
   return IN;
}         
{RAISE} {
    // cout <<"RAISE\n";
    strcpy(yylval.tok.lex, yytext); 
   return RAISE;
}      
{TRUE} {
    //cout<<"TRUE\n";
    strcpy(yylval.tok.lex, yytext); 
   return TRUE;
}       
{CLASS} {
    //cout<<"CLASS\n";
    strcpy(yylval.tok.lex, yytext); 
   return CLASS;
}     
{FINALLY} {
    //cout<<"FINALLY\n";
    strcpy(yylval.tok.lex, yytext); 
   return FINALLY;
}    
{IS} {
    //cout<<"IS\n";
    strcpy(yylval.tok.lex, yytext); 
   return IS;
}

{RETURN} {
    //cout<< "RETURN\n";
    strcpy(yylval.tok.lex, yytext); 
    return RETURN;
}     
{AND} {
    //cout<<"AND\n";
    strcpy(yylval.tok.lex, yytext); 
   return AND;
}       
{CONTINUE} {
    //cout <<"CONTINUE\n";
    strcpy(yylval.tok.lex, yytext); 
   return CONTINUE;
}   
{FOR} {
    //cout <<"FOR\n";
    strcpy(yylval.tok.lex, yytext); 
   return FOR;
}       
{LAMBDA} {
    //cout <<"LAMBDA\n";
    strcpy(yylval.tok.lex, yytext); 
   return LAMBDA;
}    
{TRY} {
    //cout <<"TRY\n";
    strcpy(yylval.tok.lex, yytext); 
   return TRY;
}       
{AS} {
    //cout <<"AS\n";
    strcpy(yylval.tok.lex, yytext); 
   return AS;
}        
{DEF} {
    //cout <<"DEF\n";
    strcpy(yylval.tok.lex, yytext); 
   return DEF;
}              
{FROM} {
    // cout <<"FROM\n";
    strcpy(yylval.tok.lex, yytext); 
   return FROM;
}            
{NONLOCAL} {
    // cout <<"NONLOCAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return NONLOCAL;
}     
{WHILE} {
    // cout <<"WHILE\n";
    strcpy(yylval.tok.lex, yytext); 
   return WHILE;
}     
{ASSERT} {
    // cout <<"ASSERT\n";
    strcpy(yylval.tok.lex, yytext); 
   return ASSERT;
}        
{DEL} {
    // cout <<"DEL\n";
    strcpy(yylval.tok.lex, yytext); 
   return DEL;
}             
{GLOBAL} {
    // cout <<"GLOBAL\n";
    strcpy(yylval.tok.lex, yytext); 
   return GLOBAL;
}        
{NOT} {
    // cout <<"NOT\n";
    strcpy(yylval.tok.lex, yytext); 
   return NOT;
}               
{WITH} {
    // cout <<"WITH\n";
    strcpy(yylval.tok.lex, yytext); 
   return WITH;
}      
{ASYNC} {
    // cout <<"ASYNC\n";
    strcpy(yylval.tok.lex, yytext); 
   return ASYNC;
}           
{ELIF} {
    // cout <<"ELIF\n";
    strcpy(yylval.tok.lex, yytext); 
   return ELIF;
}             
{IF} {
    // cout <<"IF\n";
    strcpy(yylval.tok.lex, yytext); 
   return IF;
}                 
{OR} {
    // cout <<"OR\n";
    strcpy(yylval.tok.lex, yytext); 
   return OR;
}                 
{YIELD} {
    // cout <<"YIELD\n";
    strcpy(yylval.tok.lex, yytext); 
   return YIELD;
}
{NAME} {
    //cout << "NAME\n";
    strcpy(yylval.tok.lex, yytext); 
   return NAME;
}

{STRING} {
    //cout<<"STRING\n";
    strcpy(yylval.tok.lex, yytext); 
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

//


