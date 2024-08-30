%{
    #include<bits/stdc++.h>
    #include <fstream>

    using namespace std;
    
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    int nodes = 0;
    map<int, string> node_map;
    map<int, string> node_shape;
    vector<pair<int,string> > baap, betaa;
    extern stack<int> indent_cnt;    
    string s;
    extern char* yytext;
%}

%define parse.error verbose

%union {
    int num;
    char str[1000];
    struct {
        int n;
        char lex[1000];
    } tok;
}

/* Terminals */
%token<tok> INTEGER
%token<tok> FLOATNUMBER
%token<tok> NUMBER
%token<tok> STRING
%token<tok> SHORT_STRING
%token<tok> LONG_STRING
%token<tok> PLUS
%token<tok> MINUS       
%token<tok> MULTIPLY    
%token<tok> EXP       
%token<tok> SLASH
%token<tok> DOUBLESLASH
%token<tok> DIVIDE         
%token<tok> DIVIDEDIVIDE   
%token<tok> MOD          
%token<tok> AT       
%token<tok> RIGHTSHIFT
%token<tok> LEFTSHIFT
%token<tok> AMPERSAND
%token<tok> EQUAL       
%token<tok> NOTEQUAL       
%token<tok> GREATER        
%token<tok> LESS          
%token<tok> GREATEREQ     
%token<tok> LESSEQ        
%token<tok> BITOR         
%token<tok> BITXOR        
%token<tok> BITNOT     
%token<tok> ASSIGN    
%token<tok> PLUSEQUAL   
%token<tok> MINUSEQUAL
%token<tok> MULTIPLYEQUAL
%token<tok> DIVIDEEQUAL
%token<tok> PERCENTEQUAL
%token<tok> EXPONENTEQUAL
%token<tok> ANDEQUAL     
%token<tok> OREQUAL       
%token<tok> XOREQUAL
%token<tok> LEFTSHIFTEQUAL
%token<tok> RIGHTSHIFTEQUAL
%token<tok> COLONEQUAL
%token<tok> LEFTBRACKET  
%token<tok> RIGHTBRACKET
%token<tok> LEFTSQUAREBRACKET
%token<tok> RIGHTSQUAREBRACKET
%token<tok> LEFTCURLYBRACKET 
%token<tok> RIGHTCURLYBRACKET
%token<tok> COMMA         
%token<tok> COLON          
%token<tok> SEMICOLON         
%token<tok> DOT            
%token<tok> ARROW           
%token<tok> DIVIDEDIVIDEEQUAL
%token<tok> ATEQUAL
%token<tok> NAME_DUNDER
%token<tok> MAIN_DUNDER
%token<tok> INIT_DUNDER

%token<tok> SPECIAL_CHAR
%token<tok> UNDERSCORE
%token<tok> DOUBLE_QUOTE
%token<tok> SINGLE_QUOTE         
%token<tok> BACKSLASH               
%token<tok> SPACE                       

%token<tok> FALSE     
%token<tok> AWAIT     
%token<tok> ELSE   
%token<tok> IMPORT   
%token<tok> PASS     
%token<tok> NONE     
%token<tok> BREAK    
%token<tok> EXCEPT  
%token<tok> IN       
%token<tok> RAISE     
%token<tok> TRUE     
%token<tok> CLASS
%token<tok> FINALLY   
%token<tok> IS    
%token<tok> RETURN     
%token<tok> AND    
%token<tok> CONTINUE  
%token<tok> FOR      
%token<tok> LAMBDA  
%token<tok> TRY     
%token<tok> AS       
%token<tok> DEF            
%token<tok> FROM       
%token<tok> NONLOCAL  
%token<tok> WHILE    
%token<tok> ASSERT     
%token<tok> DEL          
%token<tok> GLOBAL       
%token<tok> NOT            
%token<tok> WITH 
%token<tok> ASYNC        
%token<tok> ELIF           
%token<tok> IF             
%token<tok> OR              
%token<tok> YIELD
%token<tok> NAME 
%token<tok> COMMENT

%token<tok> NEWLINE
%token<tok> INDENT
%token<tok> DEDENT
%token<tok> ELLIPSIS

/*Non terminals*/

%type<num> module
%type<num> file_input
%type<num> funcdef
%type<num> parameters
%type<num> typedargslist
%type<num> argument1
%type<num> tfpdef
%type<num> stmt
%type<num> simple_stmt
%type<num> small_stmt_help
%type<num> small_stmt
%type<num> expr_stmt
%type<num> assign_help
%type<num> augassign
%type<num> flow_stmt
%type<num> break_stmt
%type<num> continue_stmt
%type<num> return_stmt
%type<num> global_stmt
%type<num> assert_stmt
%type<num> compound_stmt
%type<num> if_stmt
%type<num> if_stmt_help
%type<num> while_stmt
%type<num> for_stmt
%type<num> suite
%type<num> stmt_help
%type<num> test
%type<num> or_test
%type<num> and_test
%type<num> not_test
%type<num> comparison
%type<num> comp_op
%type<num> expr
%type<num> xor_expr
%type<num> and_expr
%type<num> shift_expr
%type<num> arith_expr
%type<num> term
%type<num> factor
%type<num> power
%type<num> atom_expr
%type<num> atom
%type<num> string_help
%type<num> trailer
%type<num> exprlist
%type<num> exprlist_help
%type<num> testlist
%type<num> testlist_list
%type<num> classdef
%type<num> arglist
%type<num> arglist_help
%type<num> func_body_suite
%type<num> argument
%type<num> comp_for
%type<num> comp_if
%type<num> comp_iter

/*rules */
%start module

%%

module: file_input {
    $$ = nodes++;
    node_map[$$] = "INPUT";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
}

file_input : file_input NEWLINE {
    $$ = $1;
}
| file_input stmt {
    $$ = nodes++;
    node_map[$$] = "Statements";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}
| NEWLINE {
    
}
| stmt {
    $$ = $1;
}
;

funcdef: DEF NAME parameters ARROW test COLON func_body_suite {
    $$ = nodes++;
    node_map[$$] = "funcdef";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(def)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

    ($4).n = nodes++;
    node_map[($4).n] = "DELIMITER(->)";
    node_shape[($4).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($4).n,node_map[($4).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5,node_map[$5]));

    ($6).n = nodes++;
    node_map[($6).n] = "DELIMITER(:)";
    node_shape[($6).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($6).n,node_map[($6).n]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($7,node_map[$7]));
}
| DEF NAME parameters COLON func_body_suite {
    $$ = nodes++;
    node_map[$$] = "funcdef";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(def)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

    ($4).n = nodes++;
    node_map[($4).n] = "DELIMITER(:)";
    node_shape[($4).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($4).n,node_map[($4).n]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5,node_map[$5]));

}
;

parameters: LEFTBRACKET typedargslist RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "parameters";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));
      
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));  
    
    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER())";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
}
| LEFTBRACKET RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "parameters";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));
    
    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER())";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}

typedargslist : argument1 {
    $$ = $1;
}
| typedargslist COMMA argument1 {

    $$ = nodes++;
    node_map[$$] = "typedargslist";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

}

argument1 : tfpdef {
    $$ = $1;
}
| tfpdef ASSIGN test {
    
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(=)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

tfpdef: NAME {

    ($1).n = nodes++;
    string s = "NAME (" + string(($1).lex) + ")";
    node_map[($1).n] = s;
    node_shape[($1).n] = "box";
    $$ = ($1).n;

}
| NAME COLON test {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    string s = "NAME (" + string(($1).lex) + ")";
    node_map[($1).n] = s;
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(:)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

stmt: simple_stmt {
    $$ = $1;
}
| compound_stmt {
    $$ = $1;;
}
;


simple_stmt : small_stmt_help SEMICOLON NEWLINE {
    $$ = nodes++;
    node_map[$$] = "stmt";
    node_shape[$$] = "oval";
    

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(;)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n, node_map[($2).n]));

}
| small_stmt_help NEWLINE {
    $$ = $1;
}

small_stmt_help : small_stmt {
    $$ = $1;
}
| small_stmt_help SEMICOLON small_stmt {
    $$ = nodes++;
    node_map[$$] = "stmt_block";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(;)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}
               
small_stmt: expr_stmt {
    $$ = $1;
}
| flow_stmt {
    $$ = $1;
}
| global_stmt {
    $$ = $1;
}
| assert_stmt {
    $$ = $1;
}

expr_stmt: testlist COLON test {
    $$ = nodes++;
    node_map[$$] = "expr_stmt";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(:)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}
| testlist COLON test ASSIGN testlist 
{
    $$ = nodes++;
    node_map[$$] = "expr_stmt";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(:)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

    ($4).n = nodes++;
    node_map[($4).n] = "OPERATOR(=)";
    node_shape[($4).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($4).n,node_map[($4).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5,node_map[$5]));
    
}
| testlist augassign testlist {
    $$ = $2;
    node_map[$$] = node_map[$2];
    node_shape[$$] = node_shape[$2];
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
    
}
| testlist {
    $$ = $1;
}
| testlist ASSIGN assign_help {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(=)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

assign_help : testlist  {
    $$ = $1;
} 
| testlist ASSIGN assign_help {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(=)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

augassign: PLUSEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(+=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
    
}
| MINUSEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(-=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| MULTIPLYEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(*=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| ATEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMTER(@=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| DIVIDEEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(/=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
    
}
| PERCENTEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(%=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| ANDEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(&=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| OREQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(|=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| XOREQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(^=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| LEFTSHIFTEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(<<=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;

}
| RIGHTSHIFTEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(>>=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;

}
| EXPONENTEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(**=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| DIVIDEDIVIDEEQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(//=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}


flow_stmt: break_stmt {
    $$ = $1;
}
| continue_stmt {
    $$ = $1;
}
| return_stmt {
    $$ = $1;
}

break_stmt: BREAK {

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(break)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;

}

continue_stmt: CONTINUE {

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(continue)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}

return_stmt: RETURN testlist {
    $$ = nodes++;
    node_map[$$] = "return_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(return)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n])); 
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}
| RETURN {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(return)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}

global_stmt: GLOBAL NAME {
    $$ = nodes++;
    node_map[$$] = "global_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(global)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
|  global_stmt COMMA NAME {
     $$ = nodes++;
    node_map[$$] = "global_stmt";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1,node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n, node_map[($2).n]));
    
    ($3).n = nodes++;
    string s = "NAME (" + string(($3).lex) + ")";
    node_map[($3).n] = s;
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

}


assert_stmt: ASSERT test COMMA test {
    $$ = nodes++;
    node_map[$$] = "assert_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(assert)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(,)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4,node_map[$4]));

}
| ASSERT test {
    $$ = nodes++;
    node_map[$$] = "assert_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(assert)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}

compound_stmt: if_stmt {
    $$ = $1;
}
| while_stmt {
    $$ = $1;
}
| for_stmt {
    $$ = $1;
}
| funcdef {
    $$ = $1;
}
| classdef {
    $$ = $1;
}


if_stmt: IF test COLON suite if_stmt_help ELSE COLON suite {
    $$ = nodes++;
    node_map[$$] = "if_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(if)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5, node_map[$5]));

    ($6).n = nodes++;
    node_map[($6).n] = "KEYWORD(else)";
    node_shape[($6).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($6).n, node_map[($6).n]));
    
    ($7).n = nodes++;
    node_map[($7).n] = "DELIMITER(:)";
    node_shape[($7).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($7).n, node_map[($7).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($8, node_map[$8]));

}
| IF test COLON suite if_stmt_help{
    $$ = nodes++;
    node_map[$$] = "if_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(if)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5, node_map[$5]));
}
| IF test COLON suite ELSE COLON suite {
     $$ = nodes++;
    node_map[$$] = "if_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(if)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

    ($5).n = nodes++;
    node_map[($5).n] = "KEYWORD(else)";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n, node_map[($5).n]));
    
    ($6).n = nodes++;
    node_map[($6).n] = "DELIMITER(:)";
    node_shape[($6).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($6).n, node_map[($6).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($7, node_map[$7]));

}
| IF test COLON suite {
    $$ = nodes++;
    node_map[$$] = "if_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(if)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
}
if_stmt_help : ELIF test COLON suite {
    $$ = nodes++;
    node_map[$$] = "elif_block";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(elif)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

}
| ELIF test COLON suite if_stmt_help {
    $$ = nodes++;
    node_map[$$] = "elif_block";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(elif)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5, node_map[$5]));
    
}

while_stmt: WHILE test COLON suite {
    $$ = nodes++;
    node_map[$$] = "while_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(while)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
    
    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
}
| WHILE test COLON suite ELSE COLON suite{
    $$ = nodes++;
    node_map[$$] = "while_stmt";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(while)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

    ($5).n = nodes++;
    node_map[($5).n] = "KEYWORD(else)";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n, node_map[($5).n]));    
    
    ($6).n = nodes++;
    node_map[($6).n] = "DELIMITER(:)";
    node_shape[($6).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($6).n, node_map[($6).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($7, node_map[$7]));
    
    
}

for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite {
    $$ = nodes++;
    node_map[$$] = "for_stmt";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(for)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
    
    ($3).n = nodes++;
    node_map[($3).n] = "KEYWORD(in)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
        
    ($5).n = nodes++;
    node_map[($5).n] = "DELIMITER(:)";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n, node_map[($5).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($6, node_map[$6]));

    ($7).n = nodes++;
    node_map[($7).n] = "KEYWORD(else)";
    node_shape[($7).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($7).n, node_map[($7).n]));
    
    ($8).n = nodes++;
    node_map[($8).n] = "DELIMITER(:)";
    node_shape[($8).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($8).n, node_map[($8).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($9, node_map[$9]));

}
| FOR exprlist IN testlist COLON suite {
    $$ = nodes++;
    node_map[$$] = "for_stmt";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(for)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
    
    ($3).n = nodes++;
    node_map[($3).n] = "KEYWORD(in)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n, node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
        
    ($5).n = nodes++;
    node_map[($5).n] = "DELIMITER(:)";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n, node_map[($5).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($6, node_map[$6]));

}

suite: simple_stmt {
    $$ = $1;
}

| NEWLINE INDENT stmt_help DEDENT {
    $$ = $3;
}

stmt_help: stmt {
    $$ = $1;
}
| stmt stmt_help {
    $$ = nodes++;
    node_map[$$] = "stmt_block";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

}

test : or_test {
    $$ = $1;
}
| or_test IF or_test ELSE test {

    $$ = nodes++;
    node_map[$$] = "test";
    node_shape[$$] = "oval";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "KEYWORD(if)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

    ($4).n = nodes++;
    node_map[($4).n] = "KEYWORD(else)";
    node_shape[($4).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($4).n,node_map[($4).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5,node_map[$5]));
};

or_test : and_test {
    $$ = $1;
}
| or_test OR and_test {
    $$ = nodes++;
    node_map[$$] = "or_test";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "KEYWORD(or)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}


and_test : not_test {
    $$ = $1;
}

| and_test AND not_test {
    $$ = nodes++;
    node_map[$$] = "and_test";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "KEYWORD(and)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

not_test : NOT not_test {
    $$ = nodes++;
    node_map[$$] = "not_test";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(not)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}

| comparison {
    $$ = $1;
}

comparison : expr {
    $$ = $1;
}

| comparison comp_op expr {
    $$ = $2;
    node_map[$$] = node_map[$2];
    node_shape[$$] = node_shape[$2];
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1,node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

comp_op : EQUAL {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| LESS {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(<)";
    node_shape[($1).n] = "box";
    $$=($1).n;
}
|GREATER {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(>)";
    node_shape[($1).n] = "box";
    $$=($1).n;
}
|GREATEREQ {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(>=)";
    node_shape[($1).n] = "box";
    $$=($1).n;
}
|LESSEQ {

    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(<=)";
    node_shape[($1).n] = "box";
    $$=($1).n;
}
|NOTEQUAL {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(!=)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
|IS {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(is)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
|IS NOT {
    $$ = nodes++;
    node_map[$$] = "comp_op";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(is)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "KEYWORD(not)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n, node_map[($2).n]));
}
|IN {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(in)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| NOT IN {
    $$ = nodes++;
    node_map[$$] = "comp_op";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(not)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n, node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "KEYWORD(in)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n, node_map[($2).n]));
}

expr : xor_expr {
    $$ = $1;
}

| expr BITOR xor_expr {

    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(|)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

xor_expr: and_expr {
    $$ = $1;
}

| xor_expr BITXOR and_expr {

    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(^)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

and_expr : shift_expr {
    $$ = $1;
}

| and_expr AMPERSAND shift_expr {
   
    

    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(&)";
    node_shape[($2).n] = "box";
    
    $$ = ($2).n;    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}


shift_expr : arith_expr {
    $$=$1;
}

| shift_expr LEFTSHIFT arith_expr {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(<<)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

| shift_expr RIGHTSHIFT arith_expr {

    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(>>)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}


arith_expr: term {
    $$=$1;
}

| arith_expr PLUS term {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(+)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}
| arith_expr MINUS term {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(-)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}

term : factor {
    $$=$1;
}

| term MULTIPLY factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(*)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}
| term AT factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(@)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
    
}
| term DIVIDE factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(/)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

}
| term MOD factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(%)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

}
| term DIVIDEDIVIDE factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(//)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));

}

factor : power {
    $$ = $1;
}

| PLUS factor {
    ($1).n = nodes++;
    node_map[($1).n] = "OPEARTOR(+)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}
| MINUS factor {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(-)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}
| BITNOT factor {
    ($1).n = nodes++;
    node_map[($1).n] = "OPERATOR(~)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2,node_map[$2]));
}

power : atom_expr {
    $$=$1;
}

| atom_expr EXP factor {
    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(**)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3,node_map[$3]));
}


atom_expr: atom {
    $$=$1;
}

| atom_expr trailer 
{
    $$ = nodes++;
    node_map[$$] = "atom_expr";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
}
;

atom : LEFTBRACKET testlist RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER())";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

}
| LEFTBRACKET RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));


    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER())";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
| LEFTSQUAREBRACKET testlist RIGHTSQUAREBRACKET {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER([)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(])";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
}
| LEFTSQUAREBRACKET RIGHTSQUAREBRACKET {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER([)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(])";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
| LEFTCURLYBRACKET RIGHTCURLYBRACKET {
    $$ = nodes++;
    node_map[$$] = "atom";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER({)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(})";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
| NAME {

    ($1).n = nodes++;
    string s = "NAME (" + string(($1).lex) + ")";
    node_map[($1).n] = s;
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}

| NUMBER {
    
    ($1).n = nodes++;
    string s = "NUMBER (" + string(($1).lex) + ")";
    node_map[($1).n] = s;
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| string_help {
    $$ = $1;
}

| NONE {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(None)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| TRUE {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(True)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}
| FALSE {
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(False)";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}

string_help : string_help STRING {
    $$ = nodes++;
    node_map[$$] = "string_help";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1,node_map[$1]));

    ($2).n = nodes++;
    s = string(($2).lex);
    node_map[($2).n] = "STRING(" + s + ")";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
| STRING {
    ($1).n = nodes++;
    s = string(($1).lex);
    node_map[($1).n] = "STRING(" + s + ")";
    node_shape[($1).n] = "box";
    $$ = ($1).n;
}

trailer: LEFTBRACKET RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "trailer";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER())";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
    
}
| LEFTBRACKET arglist RIGHTBRACKET {
    $$ = nodes++;
    node_map[$$] = "trailer";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(()";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER())";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
    
}
| LEFTSQUAREBRACKET test RIGHTSQUAREBRACKET {
    $$ = nodes++;
    node_map[$$] = "trailer";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER([)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(])";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
    
}
| DOT NAME {
    $$ = nodes++;
    node_map[$$] = "trailer";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "DELIMITER(.)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}

exprlist: exprlist_help {
    $$=$1;
}
|exprlist_help COMMA {
    $$ = nodes++;
    node_map[$$] = "exprlist";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}

exprlist_help: expr{
    $$=$1;
}
| exprlist_help COMMA expr {
    $$ = nodes++;
    node_map[$$] = "exprlist";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3, node_map[$3]));
}


testlist: testlist_list COMMA {
    $$ = nodes++;
    node_map[$$] = "testlist";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    
    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
}
| testlist_list {
    $$ = $1;    
}

testlist_list: test  {
    $$=$1;
}       

| testlist_list COMMA test {
    $$ = nodes++;
    node_map[$$] = "testlist_list";
    node_shape[$$] = "oval";

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3, node_map[$3]));
    
}        
            


classdef: CLASS NAME COLON suite {
    $$ = nodes++;
    node_map[$$] = "classdef";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(class)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(:)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
}
| CLASS NAME LEFTBRACKET RIGHTBRACKET COLON suite {
    $$ = nodes++;
    node_map[$$] = "classdef";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(class)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(()";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

    ($4).n = nodes++;
    node_map[($4).n] = "DELIMITER())";
    node_shape[($4).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

    ($5).n = nodes++;
    node_map[($5).n] = "DELIMITER(:)";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n,node_map[($5).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($6, node_map[$6]));
}
| CLASS NAME LEFTBRACKET arglist RIGHTBRACKET COLON suite {

    $$ = nodes++;
    node_map[$$] = "classdef";
    node_shape[$$] = "oval";
    
    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(class)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));
    
    ($2).n = nodes++;
    string s = "NAME (" + string(($2).lex) + ")";
    node_map[($2).n] = s;
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$]));betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    ($3).n = nodes++;
    node_map[($3).n] = "DELIMITER(()";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

    ($5).n = nodes++;
    node_map[($5).n] = "DELIMITER())";
    node_shape[($5).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($5).n,node_map[($5).n]));

    ($6).n = nodes++;
    node_map[($6).n] = "DELIMITER(:)";
    node_shape[($6).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($6).n,node_map[($6).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($7, node_map[$7]));
    
}

arglist: arglist_help {
    $$ = $1;
}
| arglist_help COMMA {
    $$ = nodes++;
    node_map[$$] = "arglist";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));


}

arglist_help: argument {
    $$ = $1;
}
| arglist_help COMMA argument {
    $$ = nodes++;
    node_map[$$] = "arglist";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));

    ($2).n = nodes++;
    node_map[($2).n] = "DELIMITER(,)";
    node_shape[($2).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($2).n,node_map[($2).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3, node_map[$3]));
}

func_body_suite: simple_stmt {
    $$ = $1;
}
| NEWLINE INDENT stmt_help DEDENT {
    $$ = $3;
}

/*
argument: ( test [comp_for] |
            test ':=' test |
            test '=' test |
            '**' test |
            '*' test )

comp_iter: comp_for | comp_if
sync_comp_for: 'for' exprlist 'in' or_test [comp_iter]
comp_for: [ASYNC] sync_comp_for
comp_if: 'if' test_nocond [comp_iter]
*/
argument: test {

    $$ = $1;
}

| test ASSIGN test {

    ($2).n = nodes++;
    node_map[($2).n] = "OPERATOR(=)";
    node_shape[($2).n] = "box";
    $$ = ($2).n;
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3, node_map[$3]));
}
| test comp_for {
    $$ = nodes++;
    node_map[$$] = "arglist";
    node_shape[$$] = "oval";
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($1, node_map[$1]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
}

comp_iter: comp_for {
 $$ = $1;
}
| comp_if {
    $$ = $1;
}

comp_for: FOR exprlist IN or_test {
    $$ = nodes++;
    node_map[$$] = "comp_for";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(For)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "KEYWORD(In)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));

}
| FOR exprlist IN or_test comp_iter {
    $$ = nodes++;
    node_map[$$] = "comp_for";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(For)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

    ($3).n = nodes++;
    node_map[($3).n] = "KEYWORD(In)";
    node_shape[($3).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($3).n,node_map[($3).n]));
    
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($4, node_map[$4]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($5, node_map[$5]));
}

comp_if: IF or_test {
    $$ = nodes++;
    node_map[$$] = "comp_if";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(For)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));

}
| IF or_test comp_iter {
    $$ = nodes++;
    node_map[$$] = "comp_if";
    node_shape[$$] = "oval";

    ($1).n = nodes++;
    node_map[($1).n] = "KEYWORD(If)";
    node_shape[($1).n] = "box";
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair(($1).n,node_map[($1).n]));

    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($2, node_map[$2]));
    baap.push_back(make_pair($$,node_map[$$])); betaa.push_back(make_pair($3, node_map[$3]));
}


%%
void yyerror(const char *s)
{
    cout<< "Error found at line number: "<< yylineno<< " " << "at token " << yytext << " " << s << endl;
 
    exit(1);
}

int main(int argc, char **argv)
{
  string executible_name(argv[0]);
  argc--, argv++;
  if(argc != 2) {
    cerr << executible_name << ": Error: provide arguments correctly\n";
    exit(1);
  }
  char *input_filename = argv[0];
  int verbose = atoi(argv[1]);
  if(verbose) yydebug = 1;
  yyin = fopen(input_filename, "r");
  if(yyin == NULL) {
    cerr << executible_name << ": Error: Input file " << input_filename << " not found.\n";
    exit(1);
  }

  indent_cnt.push(0);


  yyparse();
  ofstream fout("AST.dot");
  fout<<"digraph G {"<<endl;
  fout<<"node [ordering=out]\n";
  for(auto it : node_map){
    string s;
    for (auto x : it.second) {
        if (x == '\"'){
            s += "\\";
            s += "\"";
        }
        else {
            s += x;
        }
    }
    fout<<it.first<<" [label=\"" << s << "\" ,shape= " << node_shape[it.first] << " ]" << endl;
    
  }
  for(int i=0; i<nodes - 1; ++i){
    fout<<baap[i].first<<" -> "<<betaa[i].first<<endl;
  }
  fout<<"}"<<endl;
  return 0;
}



