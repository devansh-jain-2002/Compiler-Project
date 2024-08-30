%{
    #include "helper.hpp"
    #include<bits/stdc++.h>
    using namespace std;
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    int nodes = 0;
    map<int, string> node_map;
    map<int, string> node_shape;
    map<string, ST*> cls_ST;
    vector<pair<int,string> > baap, betaa;
    extern stack<int> indent_cnt;    
    string s;
    extern char* yytext;
    Type None_type = {"None",0};
    Type Int_type = {"int",0};
    Type Bool_type = {"bool",0};
    Type Float_type = {"float",0};
    Type Str_type = {"str",0};
    stack <string> s_label;
    stack <string> e_label;
    ST* CurrST;
    int offset = 0;
    string res;
%}

%define parse.error verbose

%define api.value.type { struct semantic_value_type }

/* Terminals */

%token INTEGER
%token FLOAT
%token STRING
%token SHORT_STRING
%token LONG_STRING
%token PLUS
%token MINUS       
%token MULTIPLY    
%token EXP       
%token SLASH
%token DOUBLESLASH
%token DIVIDE         
%token DIVIDEDIVIDE   
%token MOD          
%token AT       
%token RIGHTSHIFT
%token LEFTSHIFT
%token AMPERSAND
%token EQUAL       
%token NOTEQUAL       
%token GREATER        
%token LESS          
%token GREATEREQ
%token LESSEQ        
%token BITOR         
%token BITXOR        
%token BITNOT     
%token ASSIGN    
%token PLUSEQUAL   
%token MINUSEQUAL
%token MULTIPLYEQUAL
%token DIVIDEEQUAL
%token MODEQUAL
%token EXPONENTEQUAL
%token ANDEQUAL     
%token OREQUAL       
%token XOREQUAL
%token LEFTSHIFTEQUAL
%token RIGHTSHIFTEQUAL
%token COLONEQUAL
%token LEFTBRACKET  
%token RIGHTBRACKET
%token LEFTSQUAREBRACKET
%token RIGHTSQUAREBRACKET
%token LEFTCURLYBRACKET 
%token RIGHTCURLYBRACKET
%token COMMA         
%token COLON          
%token SEMICOLON         
%token DOT            
%token ARROW           
%token DIVIDEDIVIDEEQUAL
%token ATEQUAL
%token NAME_DUNDER
%token MAIN_DUNDER
%token INIT_DUNDER
%token SPECIAL_CHAR
%token UNDERSCORE
%token DOUBLE_QUOTE
%token SINGLE_QUOTE         
%token BACKSLASH               
%token SPACE  
%token FALSE     
%token AWAIT     
%token ELSE   
%token IMPORT   
%token PASS     
%token NONE     
%token BREAK    
%token EXCEPT  
%token IN       
%token RAISE     
%token TRUE     
%token CLASS
%token FINALLY   
%token RANGE
%token IS    
%token RETURN     
%token AND    
%token CONTINUE  
%token FOR      
%token LAMBDA  
%token TRY     
%token AS       
%token DEF            
%token FROM       
%token NONLOCAL  
%token WHILE    
%token ASSERT     
%token DEL          
%token GLOBAL       
%token NOT            
%token WITH 
%token ASYNC        
%token ELIF           
%token IF             
%token OR              
%token YIELD
%token NAME 
%token COMMENT
%token NEWLINE
%token INDENT
%token DEDENT
%token ELLIPSIS
%token PRINT


%type module
%type file_input
%type funcdef
%type parameters
%type typedargslist
%type argument1
%type tfpdef
%type stmt
%type simple_stmt
%type small_stmt_help
%type small_stmt
%type expr_stmt
%type augassign
%type flow_stmt
%type break_stmt
%type continue_stmt
%type return_stmt
%type global_stmt
%type assert_stmt
%type compound_stmt
%type if_stmt
%type if_stmt_help
%type while_stmt
%type for_stmt
%type suite
%type stmt_help
%type test
%type and_test
%type not_test
%type comparison
%type comp_op
%type expr
%type xor_expr
%type and_expr
%type shift_expr
%type arith_expr
%type term
%type factor
%type power
%type atom_expr
%type atom
// %type exprlist
// %type exprlist_help
%type testlist
%type testlist_list
%type classdef
%type arglist
%type arglist_help
%type argument
// %type comp_for
// %type comp_if
// %type comp_iter
%type type_name
%type func_action
%type lvalue
%type dummy_if
%type dummy_elif
%type loop_action
%type ranges
%type print_stmt
%type dot_trailer
%type call_trailer
%type index_trailer

/*rules */
%start module

%%

module: file_input {
    res += ($1)._3AC;
}

file_input : file_input NEWLINE {
    $$ = $1;
}
| file_input stmt {
    ($$)._3AC = ($1)._3AC + ($2)._3AC;
}
| NEWLINE {
    
}
| stmt {
    $$ = $1;
}
;

func_action : {
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = FUNCTION_ST;
    CurrST = newST;
}



funcdef: DEF NAME func_action parameters ARROW type_name {
    CurrST->return_type = ($6).type;
    ST* parentST = CurrST->parentST;
    auto fun = new Function;
    fun->return_type = ($6).type;
    fun->args = ($4).args;
    fun->funcST = CurrST;
    auto entry = new STEntry;
    if(parentST->type == CLASS_ST){
        entry->lex = CurrST->current_Class->name + "." + ($2).lex;
    }
    else{
        entry->lex = ($2).lex;
    }
    entry->func = fun;
    entry->lineno = ($1).lineno;
    entry->func = fun;
    entry->lineno = ($1).lineno;
    parentST->insert(($2).lex, entry);

} COLON suite
{
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    string lex;
    if(CurrST->type == CLASS_ST){
        // cout << "Class function" << endl;
        lex = CurrST->current_Class->name + "." + ($2).lex;
    }
    else{
        lex = ($2).lex;
    }
    ($$)._3AC = "@beginfunc " + lex + ":\n" + "ra = popparam\n" + ($4)._3AC + ($9)._3AC + "goto ra\n" "@endfunc\n";

}
| DEF NAME func_action parameters COLON {
    CurrST->return_type = None_type;
    ST* parentST = CurrST->parentST;
    auto fun = new Function;
    fun->return_type = None_type;
    fun->args = ($4).args;
    fun->funcST = CurrST;
    auto entry = new STEntry;
    if(parentST->type == CLASS_ST){
        entry->lex = CurrST->current_Class->name + "." + ($2).lex;
    }
    else{
        entry->lex = ($2).lex;
    }
    entry->func = fun;
    entry->lineno = ($1).lineno;
    entry->func = fun;
    entry->lineno = ($1).lineno;
    parentST->insert(($2).lex, entry);

} suite{
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    string lex;
    if(CurrST->type == CLASS_ST){
        // cout << "Class function" << endl;
        lex = CurrST->current_Class->name + "." + ($2).lex;
    }
    else{
        // cout << "Global function" << endl;
        lex = ($2).lex;
    }
    ($$)._3AC = "@beginfunc " + lex + ":\n" + "ra = popparam\n"+ ($4)._3AC +  ($7)._3AC  + "goto ra\n"  + "@endfunc\n";
}
;

parameters: LEFTBRACKET typedargslist RIGHTBRACKET {
    $$ = $2;
}
| LEFTBRACKET RIGHTBRACKET {
}

typedargslist : argument1 {
    $$ = $1;
    ($$).args.push_back(($1).type);
}
| typedargslist COMMA argument1 {
    $$ = $1;
    ($$).args.push_back(($3).type);
    $$._3AC = ($1)._3AC + ($3)._3AC;
}

argument1 : tfpdef {
    $$ = $1;
    $$._3AC = ($1).lex + " = popparam\n";
}
| tfpdef ASSIGN test {
    ($$).type = ($1).type;
    if(($1).type!=($3).type){
        cerr <<"Error! Types on both the sides of assignment do not match in Line number: "<<yylineno<<endl;;
        exit(1);
    }
    ($$)._3AC = ($3)._3AC + ($1).lex + " = " + ($3).lex + "\n";
}

tfpdef: NAME {
    if ($$.lex != "self"){
        cerr << "Error! Type of argument not defined at line no. " << yylineno << endl;
        exit(1);
    }
    if (CurrST->parentST->type != CLASS_ST){
        cerr << "Error! self expression used outside class in Line number: "<< yylineno << endl;
        exit(1);
    }
    auto curr = new STEntry;
    curr->lex = ($1).lex;
    curr->type = {CurrST->parentST->current_Class->name, 0};
    ($$).type = curr->type;
    curr->lineno = ($1).lineno;
    CurrST->insert(($1).lex, curr);
}
| NAME COLON type_name {
    auto curr = new STEntry;

    ($$).type = ($3).type;
    curr->lex = ($1).lex;
    curr->lineno = ($1).lineno;
    curr->type = ($3).type;
    CurrST->insert(($1).lex, curr);
}

stmt: simple_stmt {
    $$ = $1;
}
| compound_stmt {
    $$ = $1;
}
;


simple_stmt : small_stmt_help SEMICOLON NEWLINE {
    $$ = $1;
}
| small_stmt_help NEWLINE {
    $$ = $1;
}

small_stmt_help : small_stmt {
    $$ = $1;
}
| small_stmt_help SEMICOLON small_stmt {
    ($$)._3AC = ($1)._3AC + ($3)._3AC;
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
| print_stmt {
    $$ = $1;
}

print_stmt : PRINT LEFTBRACKET test RIGHTBRACKET {
    ($$)._3AC = ($3)._3AC;
    ($$)._3AC += "param " + ($3).lex + "\n";
    ($$)._3AC += "call print 1\n";
}

/*
a:int = 5
a:int
1,3 : int
*/

expr_stmt: lvalue COLON type_name {
    if (CurrST->type == FUNCTION_ST && CurrST->parentST->type == CLASS_ST && ($1).is_attr){
        auto entry = new STEntry;
        entry->lex = ($1).attr_name;
        entry->type = ($3).type;
        entry->lineno = ($2).lineno;
        CurrST->parentST->insert(($1).attr_name, entry);
    }
    else{
        auto entry = new STEntry;
        entry->lex = ($1).lex;
        entry->type = ($3).type;
        entry->lineno = ($2).lineno;
        ($$)._3AC += "stackpointer +xxx\n";
        CurrST->insert(($1).lex, entry);
    }
}
| lvalue COLON type_name ASSIGN test 
{
    if (($3).type != ($5).type){
        if (($3).type == Float_type && ($5).type == Int_type){
            ($5).type = Float_type;
        }
        else if (($3).type == Int_type && ($5).type == Float_type){
            ($5).type = Int_type;
        }
        else{
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << ($3).type.s << " Got: " << ($5).type.s << endl;
            exit(1);
        }
    }
    if (CurrST->type == FUNCTION_ST && CurrST->parentST->type == CLASS_ST && ($1).is_attr){
        auto entry = new STEntry;
        entry->lex = ($1).attr_name;
        entry->type = ($3).type;
        entry->lineno = ($2).lineno;
        CurrST->parentST->insert(($1).attr_name, entry);
        offset = CurrST->parentST->lookup(($1).attr_name)->offset;
        ($$)._3AC = ($5)._3AC + ($1).lex + "[" + to_string(offset) + "] = " + ($5).lex + "\n";
    }
    else{
        auto entry = new STEntry;
        entry->lex = ($1).lex;
        entry->type = ($3).type;
        entry->lineno = ($2).lineno;
        // cout << "Here inserting " << ($1).lex << " at line number: " << ($2).lineno << endl;
        ($$)._3AC += "stackpointer +xxx\n";
        CurrST->insert(($1).lex, entry);
        ($$)._3AC = ($5)._3AC + ($1).lex + " = " + ($5).lex + "\n";
    }
}
| atom_expr ASSIGN test {
    if (($1).is_assign == 0){
        cerr << "Error! Lvalue required in assignment at line number: " << yylineno << endl;
        exit(1);
    }
    if (!($1).is_attr && !($1).is_idx){ 
        auto entry = CurrST->lookup(($1).lex);
        if (entry->type != ($3).type){
            cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
            exit(1);
        }
    }
    ($$)._3AC = ($1)._3AC + ($3)._3AC + ($1).lex + " = " + ($3).lex + "\n";
}
| atom_expr augassign test {
    if (($1).is_assign == 0){
        cerr << "Error! Lvalue required in assignment at line number: " << yylineno << endl;
        exit(1);
    }
    Type t;
    if (!($1).is_attr){
        auto entry = CurrST->lookup(($1).lex);
        if (entry->type != ($3).type){
            // cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
            // exit(1);
            if (entry->type == Float_type && ($3).type == Int_type){
                ($3).type = Float_type;
            }
            if (entry->type != ($3).type){
                cerr << "Error! Type mismatch in Line number: " << yylineno << endl;
                exit(1);
            }
        }
        t = entry->type;
    }
    else {
        t = ($1).type;
    }
    if(($2).lex=="PLUSEQUAL" || ($2).lex=="MINUSEQUAL" || ($2).lex=="MULTIPLYEQUAL" ||  ($2).lex=="DIVIDEEQUAL" || ($2).lex=="MODEQUAL" ||  ($2).lex=="EXPONENTEQUAL" ){
        if(t != Int_type && t !=Float_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t == Float_type && ($3).type == Int_type){
            ($3).type = Float_type;
        }
        if (t != ($3).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        }
        ($$).type=t;
    }
    else if(($2).lex=="RIGHTSHIFTEQUAL" || ($2).lex=="LEFTSHIFTEQUAL" || ($2).lex=="ANDEQUAL" ||  ($2).lex=="OREQUAL" || ($2).lex=="XOREQUAL"){
        if(t != Int_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t != ($3).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        } 
        ($$).type=t;   
    }
    else if(($2).lex=="DIVIDEDIVIDEEQUAL"){
        if(t != Int_type && t !=Float_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (t != ($3).type){
            cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
            exit(1);
        }
        ($$).type=Int_type;        
    }
    
    string str = ($2).lex;
    str.pop_back();
    string tmpp = newTemp();
    ($$)._3AC = ($1)._3AC;
    ($$)._3AC = ($3)._3AC + tmpp + " = " + ($1).lex + " " + str + " " + ($3).lex + "\n";
    ($$)._3AC = ($$)._3AC + ($1).lex + " = " + tmpp + "\n";
}
| test {
    $$ = $1;
}


type_name : NAME { 
    if (sz.find(($1).lex) == sz.end())
    {
        cerr << "ERROR! Type not defined in line no. " << yylineno << endl;
        exit(1);
    }
    ($$).type.s = ($1).lex;
    ($$).type.is_list = false;
} 
| NAME LEFTSQUAREBRACKET NAME RIGHTSQUAREBRACKET {
    if(string(($1).lex) != "list") {
        cerr << "Error! syntax error in list declaration in Line number: " << yylineno << endl;
        exit(1);
        
    }
    if (sz.find(($3).lex)==sz.end()){
         cerr << "Error! Type not defined in line no. : " << yylineno << endl;
         exit(1);
    }
    ($$).type.s = ($3).lex;
    ($$).type.is_list = true;
}
| NONE {
    ($$).type = None_type;
}
augassign: PLUSEQUAL {
    ($$).lex = "+=";

}
| MINUSEQUAL {
    ($$).lex = "-=";

}
| MULTIPLYEQUAL {
    ($$).lex = "*=";
}
| DIVIDEEQUAL {
    ($$).lex = "/=";
}
| MODEQUAL {
    ($$).lex = "%=";
}
| ANDEQUAL {
    ($$).lex = "&=";
}
| OREQUAL {
    ($$).lex = "|=";
}
| XOREQUAL {
    ($$).lex = "^=";

}
| LEFTSHIFTEQUAL {
    ($$).lex = "<<=";

}
| RIGHTSHIFTEQUAL {
    ($$).lex = ">>=";
}
| EXPONENTEQUAL {
    ($$).lex = "**=";
}
| DIVIDEDIVIDEEQUAL {
    ($$).lex = "//=";
}


flow_stmt: break_stmt {
    $$=$1;
}
| continue_stmt {
    $$=$1;
}
| return_stmt {
    $$=$1;
}

break_stmt: BREAK {
    ($$)._3AC = "goto " + e_label.top() + "\n";
}

continue_stmt: CONTINUE {
    ($$)._3AC = "goto " + s_label.top() + "\n";
}

return_stmt: RETURN test {
    // should occur only in a function
    if(CurrST->type != FUNCTION_ST) {
        cerr << "Error! Return Statement can only occur within function at line no. "<<yylineno<<endl;
        exit(1);
    }
    // the type of test should match the function type
    if (($2).type != CurrST->return_type){
        // cout << "$2:" << ($2).type.s << ": " << CurrST->return_type.s << endl;
        cerr << "Error! Type mismatch in Return Statement at line no. "<<yylineno<<endl;
        exit(1);
    }
    $$._3AC = ($2)._3AC + "push " + ($2).lex + "\n";
}
| RETURN {
    if(CurrST->type != FUNCTION_ST) {
        cerr << "Error! Return Statement can only occur within function at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (CurrST->return_type != None_type){
        cout << "Error! No value recieved in Return Statement at line no. "<<yylineno<<endl;
        exit(1);
    }
}

global_stmt: GLOBAL NAME {
    is_global[($2).lex] = true;
}
|  global_stmt COMMA NAME {
    is_global[($3).lex] = true;
}


assert_stmt: ASSERT test COMMA test {

}
| ASSERT test {
}

compound_stmt: if_stmt {
    $$=$1;
}
| while_stmt {
    $$=$1;
}
| for_stmt {
    $$=$1;
}
| funcdef {
    // $$=$1;
    ($$)._3AC = "";
    res += ($1)._3AC;
}
| classdef {
    $$=$1;
}

dummy_if : IF test COLON {
    ($$).next = newLabel();
    ($$)._3AC = ($2)._3AC + "ifz " + ($2).lex + " goto " + ($$).next + "\n";
} 

if_stmt: dummy_if suite if_stmt_help_1 {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + "\n";
}

| dummy_if suite if_stmt_help {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + "\n";
}
| dummy_if suite ELSE COLON suite {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($5)._3AC + "@label " + s + "\n";
}
| dummy_if suite {
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "@label " + ($1).next + ":\n";
}

dummy_elif : ELIF test COLON {
    ($$).next = newLabel();
    ($$)._3AC = ($2)._3AC + "ifz " + ($2).lex + " goto " + ($$).next + "\n";
}

if_stmt_help : dummy_elif suite {
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "@label " + ($1).next + ":\n";
}
| dummy_elif suite if_stmt_help {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + ":\n";
}

if_stmt_help_1  : dummy_elif suite ELSE COLON suite {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($5)._3AC + "@label " + s + ":\n";
}
| dummy_elif suite if_stmt_help_1 {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + ":\n";
}

loop_action : {
    auto s = newLabel();
    auto e = newLabel();
    s_label.push(s);
    e_label.push(e);
}
while_stmt: WHILE test COLON loop_action suite {
    auto s = s_label.top();
    auto e = e_label.top();
    ($$)._3AC = "@label " + s + ":\n" + ($2)._3AC + "ifz " + ($2).lex + " goto " + e + ":\n" + ($5)._3AC + "goto " + s + "\n" + "@label " + e + ":\n";
    s_label.pop();
    e_label.pop();
}
| WHILE test COLON loop_action suite ELSE COLON suite{
    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    ($$)._3AC = "@label " + s + ":\n" + ($2)._3AC + "ifz " + ($2).lex + " goto " + e + "\n" + ($5)._3AC + "goto " + s + "\n" + "@label " + e + ":\n" + ($8)._3AC + "@label " + f + ":\n";
    s_label.pop();
    e_label.pop();
}

for_stmt: FOR NAME IN ranges COLON loop_action suite ELSE COLON suite {
    ($$)._3AC += ($4)._3AC;
    auto st = CurrST->lookup(($2).lex);
    ($$)._3AC += ($2).lex + " = " + ($4).rng_start + "\n";

    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    auto temp = newTemp();
    ($$)._3AC += "@label " + s + ":\n";
    ($$)._3AC += temp +  "=" + ($2).lex + " < " + ($4).rng_end + ":\n";
    auto temp2 = newTemp();
    string incr = temp2 + " = " + ($2).lex + "\n" + ($2).lex + " = " + temp2 + " + 1\n";
    ($$)._3AC += "@label " + s + ":\n" + "ifz " + temp + " goto " + e + "\n" + ($7)._3AC + incr + "goto " + s + "\n" + "@label " + e + ":\n" + ($10)._3AC + "@label " + f + ":\n";
    s_label.pop();
    e_label.pop();
}
| FOR NAME IN ranges COLON loop_action suite {
    ($$)._3AC += ($4)._3AC;
    auto st = CurrST->lookup(($2).lex);
    ($$)._3AC += ($2).lex + " = " + ($4).rng_start + "\n";
    auto s = s_label.top();
    auto e = e_label.top();
    auto temp = newTemp();
    ($$)._3AC += "@label " + s + ":\n";
    ($$)._3AC += temp +  " = " + ($2).lex + " < " + ($4).rng_end + "\n";
    auto temp2 = newTemp();
    string incr = temp2 + " = " + ($2).lex + "\n" + ($2).lex + " = " + temp2 + " + 1\n";
    ($$)._3AC += "ifz " + temp + " goto " + e + "\n" + ($7)._3AC + incr + "goto " + s + "\n" + "@label " + e + ":\n";
    s_label.pop();
    e_label.pop();
}

ranges : RANGE LEFTBRACKET test COMMA  test RIGHTBRACKET {
    ($$).rng_start = ($3).lex;
    ($$).rng_end = ($5).lex;
    ($$)._3AC = ($3)._3AC + ($5)._3AC;
}
| RANGE LEFTBRACKET test RIGHTBRACKET {
    ($$).rng_start = "0";
    ($$).rng_end = ($3).lex;
    ($$)._3AC = ($3)._3AC;
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
//     ($1).next = newLabel();
//     ($2).next = ()
    ($$)._3AC = ($1)._3AC + ($2)._3AC;
}

test : and_test {
    $$ = $1;
}
| test OR and_test {
    if (($1).type != Bool_type && ($1).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);    \
    }
    if (($3).type != Bool_type && ($3).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = Bool_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + ($$.lex + " = " + ($1).lex + " || " + ($3).lex + "\n");
}


and_test : not_test {
    $$ = $1;
}

| and_test AND not_test {
    if (($1).type != Bool_type && ($1).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Bool_type && ($3).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = Bool_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + ($$.lex + " = " + ($1).lex + " && " + ($3).lex + "\n");
}
/* B →!B1
 {B1.true = B.false;B1.false = B.true;B.code = B1.code;}
*/
not_test : NOT not_test {
    if (($2).type != Bool_type && ($2).type != Int_type){
        cerr << "Error! Type can only be integer or Boolean at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = Bool_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($2)._3AC + ($$.lex + " = " + "!" + ($2).lex + "\n");
}

| comparison {
    $$ = $1;
}

comparison : expr {
    $$ = $1;
}

| comparison comp_op expr {  
    bool string_comp = false;
    string_comp = ($1).type == Str_type || ($3).type == Str_type;
    if (!string_comp && ($1).type != Bool_type && ($1).type != Int_type && ($1).type != Float_type ){
        cerr << "Error! Type can only be integer, Boolean or Float at line no. " <<yylineno<<endl;
        exit(1);
    }
    if (!string_comp && ($3).type != Bool_type && ($3).type != Int_type  && ($3).type != Float_type){
        cerr << "Error! Type can only be integer, Boolean or Float at line no. " <<yylineno<<endl;
        exit(1);
    }
    
    ($$).type = Bool_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + ($$.lex + " = " + ($1).lex + " " + ($2).lex + " " + ($3).lex + "\n");
} 
comp_op : EQUAL {
    ($$).lex = "==";
}
| LESS {
    ($$).lex = "<";
}
| GREATER {
    ($$).lex = ">";
}
| GREATEREQ {
    ($$).lex = ">=";
}
| LESSEQ {
    ($$).lex = "<=";
}
| NOTEQUAL {
    ($$).lex = "!=";
}
| IS {
    ($$).lex = "is";

}
| IS NOT {
    ($$).lex = "is not";  // not defined anywhere
}
| IN {
    ($$).lex = "in";
}
| NOT IN {
    ($$).lex = "not in"; // not defined anywhere
}

expr : xor_expr {
    $$ = $1;
}

| expr BITOR xor_expr {
    //error expression
    if(($1).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }  
    ($$).type=($1).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " | " + ($3).lex + "\n");

}

xor_expr: and_expr {
    $$ = $1;
}

| xor_expr BITXOR and_expr {
    //error expression
    if(($1).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }  
    ($$).type=($1).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " ^ " + ($3).lex + "\n");

}

and_expr : shift_expr {
    $$ = $1;
}

| and_expr AMPERSAND shift_expr {
    //error expression
    if(($1).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type=($1).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " & " + ($3).lex + "\n");

}


shift_expr : arith_expr {
    $$ = $1;
}

| shift_expr LEFTSHIFT arith_expr {    
    if(($1).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type=($1).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " << " + ($3).lex + "\n");

}

| shift_expr RIGHTSHIFT arith_expr {
    //error statement
    if(($1).type != Int_type){
        cerr << "Error! Type can only be integer at line no." <<yylineno<<endl;
        exit(1);
    }
    if (($3).type != Int_type){
        cerr << "Error! Type can only be integer at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type=($1).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " >> " + ($3).lex + "\n");

}


arith_expr: term {
    $$ = $1;
}

| arith_expr PLUS term {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " + " + ($3).lex + "\n");
}
| arith_expr MINUS term {
    
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " - " + ($3).lex + "\n");
}

term : factor {
    $$=$1;
}

| term MULTIPLY factor {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " * " + ($3).lex + "\n");
}

| term DIVIDE factor {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " / " + ($3).lex + "\n");

}
| term MOD factor {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " \% " + ($3).lex + "\n"); //%%
}
| term DIVIDEDIVIDE factor {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = Int_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " // " + ($3).lex + "\n");

}

factor : power {
    $$=$1;
}

| PLUS factor {
    if(($2).type != Int_type && ($2).type !=Float_type && ($2).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if(($2).type==Bool_type){
        ($2).type==Int_type;  // Boolean Typecasting
    }
    ($$) = ($2);
}
| MINUS factor {
    if(($2).type != Int_type && ($2).type !=Float_type && ($2).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if(($2).type==Bool_type){
        ($2).type==Int_type;  // Boolean Typecasting
    }
    ($$).type =($2).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($2)._3AC + (($$).lex + " = " + " -" + ($2).lex + "\n");
}
| BITNOT factor {
    if(($2).type != Int_type && ($2).type !=Float_type && ($2).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if(($2).type==Bool_type){
        ($2).type==Int_type;  // Boolean Typecasting
    }
    ($$).type =($2).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($2)._3AC + (($$).lex + " = " + " ~" + ($2).lex + "\n");
}

power : atom_expr {
    $$=$1;   
}

| atom_expr EXP factor {
    if(($1).type==Float_type && ($3).type==Int_type){
        ($2).type=Float_type;
    }
    if(($2).type==Float_type && ($3).type==Int_type){
        ($1).type=Float_type;
    }
    if(($1).type != Int_type && ($1).type !=Float_type){
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch at line no. " <<yylineno<<endl;
        exit(1);
    }
    
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " ** " + ($3).lex + "\n");

}


atom_expr: atom {
    $$=$1;
}
| lvalue index_trailer // array_indexing
{
    if (!($1).is_attr){
        auto STEntry = CurrST->lookup(($1).lex);
        
        if (STEntry->type.is_list == 0){
            cerr << "Error! Only List Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (($2).type != Int_type){
            cerr << "Error! Only Integer Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        ($$).type = STEntry->type;
        ($$).type.is_list = 0;
        ($$).is_idx = 1;
        ($$).is_assign = 1;
        ($$)._3AC = ($2)._3AC;
        auto temp = newTemp();
        ($$)._3AC = temp + " = " + ($2).lex + " * " + to_string(sz[STEntry->type.s]) + "\n";
        ($$).lex = ($1).lex + "[" + temp + "]";
    }
    else {
        auto cls = cls_ST[CurrST->lookup(($1).lex)->type.s]->current_Class;
        auto attr = cls->classST->lookupClassAttr(($1).attr_name);
        if (attr->type.is_list == 0){
            cerr << "Error! Only List Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (($2).type != Int_type){
            cerr << "Error! Only Integer Type accepted in [] at line no. "<<yylineno<<endl;
            exit(1);
        }
        ($$).type = attr->type;
        ($$).type.is_list = 0;
        ($$).is_idx = 1;
        ($$).is_assign = 1;
        ($$)._3AC = ($2)._3AC;
        auto temp = newTemp();
        ($$)._3AC = temp + " = " + ($2).lex + " * " + to_string(sz[attr->type.s]) + "\n";
        auto temp2 = newTemp();
        ($$)._3AC += temp2 + " = " + ($1).lex + "[" + to_string(attr->offset) + "]\n";
        ($$).lex = temp2 + "[" + temp + "]";
    }
}
| lvalue // object attribute or variable name 
{
    ($$).is_assign = 1;
    if (($1).is_attr) {
        $$ = $1;
        // cout << "here\n";
        auto entry = CurrST->lookup(($1).lex);
        auto cls = cls_ST[entry->type.s]->current_Class;
        // cout << ($1).attr_name << "\n";
        auto attr = cls->classST->lookupClassAttr(($1).attr_name);
        ($$).type = attr->type;
        // cout << "here\n";
        ($$).lex = ($1).lex + "[" + to_string(attr->offset) + "]";
    }
    else {
        auto entry = CurrST->lookup(($1).lex);
        ($$).type = entry->type;
        ($$).func = entry->func;
        ($$).cls = entry->cls;
        ($$).lex = ($1).lex;
    }
}
| lvalue call_trailer // object method or function call // OR constructor
{
    if (($1).lex == "len"){
        if (($2).args_list.size() != 1){
            cerr << "Error! len() takes exactly 1 argument at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (($2).args_list[0].second.is_list == 0){
            cerr << "Error! Only List Type accepted in len() at line no. "<<yylineno<<endl;
            exit(1);
        }
        ($$).type = Int_type;
        ($$).lex = newTemp();
        ($$)._3AC += "param " + ($2).args_list[0].first + "\n";
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call len 1\n";
        ($$)._3AC += "stackpointer -yyy\n";
        ($$)._3AC += ($$.lex + " = " + "popparam\n");
    }
    else {
    auto entry = CurrST->lookup(($1).lex);
    if (($1).is_class) // its the class calling a method
    {
        auto cls = cls_ST[($1).lex]->current_Class;
        auto mthd = cls->classST->lookupClassAttr(($1).attr_name);
        if (mthd == NULL){
            cerr << "Error! Method not found at line no. "<<yylineno<<endl;
            exit(1);
        }
        if (mthd->func == NULL){
            cerr << "Error! Method not found at line no. "<<yylineno<<endl;
        }
        if (mthd->func->args.size() != ($2).args_list.size()){
            cerr << "Error! Number of arguments mismatch at line no. "<<yylineno<<endl;
            exit(1);
        }
        for (int i = 1; i < mthd->func->args.size(); i++){
            if (mthd->func->args[i] != ($2).args_list[i].second){
                cerr << "Error! Type mismatch at line no. "<<yylineno<<endl;
                exit(1);
            }
        }
        ($$).type = mthd->func->return_type;
        ($$)._3AC = ($2)._3AC;
        for (int i = ($2).args_list.size() - 1; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + mthd->lex + " " + to_string(($2).args_list.size()) + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        if (mthd->func->return_type != None_type){
            ($$).lex = newTemp();
            ($$)._3AC += ($$.lex + " = " + "popparam\n");
        }
    }
    else if (entry->cls){ // it's a constructor
        auto ctor = entry->cls->classST->lookup("__init__")->func;
        if (ctor->args.size() != ($2).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;
        } 
        for (int i = 0; i < ctor->args.size() - 1; i++){
            if (ctor->args[i+1] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
            }
        }
        ($$).type = {($1).lex,0};
        ($$)._3AC += "param " + to_string(entry->cls->classST->offset) + "\n";
        ($$)._3AC += "call memalloc 1\n";
        auto temp = newTemp();
        ($$)._3AC += "popparam " + temp + "\n"; 
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        ($$)._3AC += "param " + temp + "\n"; 
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + ($1).lex + ".__init__ " + to_string(ctor->args.size()) + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        ($$).lex = temp;
    }
    else if (($1).is_attr) {
        auto cls = CurrST->lookup(entry->type.s)->cls;
        auto mthd_S = cls->classST->lookupClassAttr(($1).attr_name);
        auto mthd = mthd_S->func;
        if (mthd->args.size() != ($2).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;;
        } 
        for (int i = 0; i < mthd->args.size() - 1; i++){
            if (mthd->args[i+1] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
            }
        }
        ($$).type = mthd->return_type;
        ($$)._3AC = ($2)._3AC;
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        ($$)._3AC += "param " + ($1).lex + "\n";
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + mthd_S->lex + " " + to_string(mthd->args.size()) + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        if (mthd->return_type != None_type){
                ($$).lex = newTemp();
                ($$)._3AC += ($$.lex + " = " + "popparam\n");
        }
    }
    else if (!($1).is_attr){
        if (entry->func == NULL){
            cerr << "Error! Function not found at line no. "<<yylineno<<endl;
            exit(1);
        }
        ($1).func = entry->func;
        if (($1).func){
            if (($2).trailer_type != FUNCTION_CALL){
                cout << "Error! Not a function call at line no:" << yylineno << endl;
            }
            if (($1).func->args.size() != ($2).args_list.size()){
                cout << "Error! number of arguments do not match at line no. "<< yylineno << endl;
            }
            for (int i = 0; i < ($1).func->args.size(); i++){
                if (($1).func->args[i] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
                }
            }
            ($$).type = ($1).func->return_type;
            ($$)._3AC = ($2)._3AC;
            for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
                ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
            }
            ($$)._3AC += "stackpointer +xxx\n";
            ($$)._3AC += "call " + ($1).lex + " " + to_string(($2).args_list.size()) + "\n";
            ($$)._3AC += "stackpointer -yyy\n";
            if (($1).func->return_type != None_type){
                ($$).lex = newTemp();
                ($$)._3AC += ($$.lex + " = " + "popparam\n");
            }
        }
    }
    }
}

lvalue : NAME {
    $$ = $1;
    // cout << "Here again\n";
}
| NAME dot_trailer {
    $$.is_attr = true;
    $$.attr_name = ($2).lex;
    $$.is_assign = 1;
    if (($1).lex != "self"){
        auto entry = CurrST->lookup(($1).lex);
        // cout << "Here\n";
        Class *cls;
        if (entry->cls){ // its a class name using a method outside
            ($$).is_class = true;
            cls = entry->cls;
        }
        else {
            cls = CurrST->lookup(entry->type.s)->cls;
        }
        // cout << "Here\n";
        // auto attr = cls->classST->lookup(($2).lex);
        // // cout << "Here\n";
        // if (attr == NULL){
        //     cerr << "Error! Attribute / Method not found at line no. "<<yylineno<<endl;
        //     exit(1);
        // }

        auto attr = cls->classST->lookupClassAttr(($2).lex);

        ($$).type = attr->type;
        ($$).is_attr = true;
        ($$).attr_name = ($2).lex;
        ($$).lex = ($1).lex;
    }
}

atom : LEFTBRACKET test RIGHTBRACKET {
    $$ = $2;
}
| LEFTSQUAREBRACKET testlist RIGHTSQUAREBRACKET {
    if (($2).type.is_list){
        cerr << "Error in list declaration at line no. "<<yylineno<<endl;
    }
    ($$).type = ($2).type;
    ($$).type.is_list = true;
    ($$)._3AC = ($2)._3AC;
    auto temp = newTemp();
    ($$)._3AC += temp + " = " + to_string(($2).args_list.size()) + " * " + to_string(sz[($2).type.s]) + "\n";
    ($$)._3AC += "param " + temp + "\n";
    ($$)._3AC += "call memalloc 1\n";
    auto temp2 = newTemp();
    ($$)._3AC += "popparam " + temp2 + "\n";
    for (int i = 0; i < ($2).args_list.size(); i++){
        ($$)._3AC += temp2 + "[" + to_string(sz[($2).type.s]*i) + "]" + " = " + ($2).args_list[i].first + "\n";
    }
    ($$).lex = temp2;
    ($$).sz = ($2).args_list.size();
}

| LEFTSQUAREBRACKET RIGHTSQUAREBRACKET {
    ($$).type.is_list = 1;
}
| INTEGER {
    // auto temp = newTemp();
    // ($$).type= Int_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    ($$).type= Int_type;
    ($$).lex = ($1).lex;
}
| FLOAT {
    // auto temp = newTemp();
    // ($$).type= Float_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    ($$).type= Float_type;
    ($$).lex = ($1).lex;
}
| STRING {
    // auto temp = newTemp();
    // ($$).type= Str_type;
    // ($$).lex = temp;
    // ($$)._3AC = temp + " = " + ($1).lex + "\n";
    ($$).type= Str_type;
    ($$).lex = ($1).lex;
}

| NONE {
    ($$).type = None_type;
}
| TRUE {
    ($$).type= Bool_type;
    ($$).lex = "1";
}
| FALSE {
    ($$).type = Bool_type;
    ($$).lex = "0";
    // ($$)._3AC = "goto " + ($$).false;
}

call_trailer: LEFTBRACKET RIGHTBRACKET {
    ($$).trailer_type = FUNCTION_CALL;
    ($$).sz = 0;
}
| LEFTBRACKET arglist RIGHTBRACKET {
    $$ = $2;
    ($$).trailer_type = FUNCTION_CALL;
}

index_trailer : LEFTSQUAREBRACKET test RIGHTSQUAREBRACKET {
    $$ = $2;
    $$.trailer_type = LIST_ACCESS;
    if (($2).type != Int_type){
        cerr << "Error! Only Integer Type acceped in [] at line no. "<<yylineno<<endl;
        exit(1);
    }
    
}

dot_trailer : DOT NAME {
    $$ = $2;
}

// exprlist: exprlist_help {
//     $$=$1;
// }
// | exprlist_help COMMA {
// }

// exprlist_help: expr{
//     $$ = $1;
 
// }
// | exprlist_help COMMA expr {
      
    
// }


testlist: testlist_list COMMA {
    $$ = $1;
}
| testlist_list {    
    $$ = $1;
}

testlist_list: test  {
    $$ = $1;
    ($$).args_list.push_back({($1).lex, ($1).type});
}       

| testlist_list COMMA test {
    if (($1).type != ($3).type){
        cerr << "Error! Type mismatch at line no: "<<yylineno<<"\n";
    }
    ($$)._3AC = ($1)._3AC + ($3)._3AC;
    ($$).type = ($1).type;
    ($$).args_list.push_back({($3).lex, ($3).type});
}        
            
classdef: CLASS NAME COLON 
{
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = ($2).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[($2).lex] = CurrST;
} 
suite {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[($2).lex] = cls->classST->offset;
    cls->parent = NULL;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    entry->func = NULL;
    CurrST->insert(($2).lex, entry);
    ($$)._3AC = ($5)._3AC;

}
| CLASS NAME LEFTBRACKET RIGHTBRACKET COLON 
{
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = ($2).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[($2).lex] = CurrST;
} 
suite {
    ST* oldST = CurrST;
    CurrST = CurrST->parentST;
    auto cls = oldST->current_Class;
    cls->parent = NULL;
    cls->classST = oldST;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    CurrST->insert(($2).lex, entry);
}

| CLASS NAME LEFTBRACKET NAME {

    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = ($2).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[($2).lex] = CurrST;
    auto STentry = CurrST->lookup(($4).lex);
    CurrST->current_Class->parent = STentry->cls;
    CurrST->offset = STentry->cls->classST->offset;

} RIGHTBRACKET COLON suite {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[($2).lex] = cls->classST->offset;
    cls->parent = NULL;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    entry->func = NULL;
    CurrST->insert(($2).lex, entry);
    ($$)._3AC = ($8)._3AC;
}

arglist: arglist_help {
    $$ = $1;
}
| arglist_help COMMA {
   $$ = $1;
}

arglist_help: argument {
    $$ = $1;
    $$.args_list.push_back({($1).lex, ($1).type});
}
| arglist_help COMMA argument {
    $$ = $1;
    ($$).args_list.push_back({($3).lex, ($3).type});
    $$._3AC = ($1)._3AC + ($3)._3AC;
}

| NEWLINE INDENT stmt_help DEDENT {
    // cout << "Hello\n";
    // cout << ($3)._3AC;
    // cout << CurrST->type << endl;
    $$ = $3;
    // cout << "suite\n";
    // cout << ($$)._3AC;
    // cout << "end\n";
}

argument: test {
    $$ = $1;
}

// | test ASSIGN test {


// }
// | test comp_for {
    
// }

// comp_iter: comp_for {
//     $$=$1;
// }
// | comp_if {
//     $$ = $1;
// }

// comp_for: FOR exprlist IN test {
   

// }
// | FOR exprlist IN test comp_iter {
    
// }

// comp_if: IF test {
 

// }
// | IF test comp_iter {
    
// }


%%
void yyerror(const char *s)
{
    cout<< "Error found at line number: "<< yylineno<< " " << "at token " << yytext << " " << s << endl;
    exit(1);
}

int main(int argc, char **argv)
{
  indent_cnt.push(0);
  auto GlobalST = new ST;
  GlobalST->parentST = NULL;
  CurrST = GlobalST;
  STEntry* name = new STEntry;
  name->lex = "__name__";
  name->type = {"str", 0};
  GlobalST->insert("__name__", name);
  yyparse();
  freopen("Global.csv", "w", stdout);
  GlobalST->print();
  freopen("3AC.txt", "w", stdout);
  string final_res = "0\t";
  res += '@';
  int num_line = 1;
  if (res[0] == '@'){
    final_res = "";
    num_line = 0;
  }
  for (int i = 0; i < res.size(); i++){
    if (res[i] == '@') {
        continue;
    }
      if (res[i] == '\n' && res [i+1] == '@'){
        final_res += "\n";
      }
      else if (res[i] == '\n'){
        final_res += "\n" + to_string(num_line) + "\t";
        num_line += 1;
      }
      else {
        final_res += res[i];
      }
  }
  cout << final_res;
  return 0;
}