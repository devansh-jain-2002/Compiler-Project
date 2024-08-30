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
    stack <string> cont_label;
    int offset = 0;
    string res;
    string res_x86;
    map <string,string> str_map;
    string newString(string src){
        static int cnt = 1;
        string str = ".str"+to_string(cnt++);
        str_map[str] = src;
        return str;
    }
    template<typename T>
    void type_check(T &x, T &y){
        if (x.type != y.type){
            if(x.type.is_list != y.type.is_list){
                cerr << "Error! Types do not match at line number " << yylineno << endl;
                exit(1);
            }
            if (x.type == Float_type && y.type == Int_type){
                y.type = Float_type;
            }
            else if (x.type == Bool_type && y.type == Int_type){
                int_to_bool_x86(y.lex);
            }
            else if (x.type == Int_type && y.type == Bool_type){
                y.type = Int_type;
            }
            else {
                cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
                cerr << "Expected: " << x.type.s << " got: " << y.type.s << endl;
                exit(1);
            }
        }
    }
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

    res_x86 += ($1).x86;
}

file_input : file_input NEWLINE {
    $$ = $1;
}
| file_input stmt {
    ($$)._3AC = ($1)._3AC + ($2)._3AC;
    ($$).x86 = ($1).x86 + ($2).x86;
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
        entry->lex = parentST->current_Class->name + "." + ($2).lex;
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
    ($$).x86 += ".globl " + lex + "\n";
    ($$).x86 += ".type " + lex + ", @function\n";
    ($$).x86 += lex + ":\n";
    ($$).x86 += "pushq %rbp\n";
    ($$).x86 += "movq %rsp , %rbp\n";
    offset = oldST->offset;
    offset = offset % 16 ? offset + 8 : offset;
    ($$).x86 += "subq $" + to_string(offset) + ", %rsp\n";
    ($$).x86 += ($9).x86;
    ($$).x86 += "leave\n";
    ($$).x86 += "ret\n";
}
| DEF NAME func_action parameters COLON {
    ////printf("Function begins here\n");
    CurrST->return_type = None_type;
    ST* parentST = CurrST->parentST;
    auto fun = new Function;
    fun->return_type = None_type;
    fun->args = ($4).args;
    fun->funcST = CurrST;
    auto entry = new STEntry;
    if(parentST->type == CLASS_ST){
        entry->lex = parentST->current_Class->name + "." + ($2).lex;
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
    ($$).x86 += ".globl " + lex + "\n";
    ($$).x86 += ".type " + lex + ", @function\n";
    ($$).x86 += lex + ":\n";
    ($$).x86 += "pushq %rbp\n";
    ($$).x86 += "movq %rsp , %rbp\n";
    offset = oldST->offset;
    offset = offset % 16 ? offset + 8 : offset;
    ($$).x86 += "subq $" + to_string(offset) + ", %rsp\n";
    ($$).x86 += ($7).x86;
    ($$).x86 += "leave\n";
    ($$).x86 += "ret\n";
}
;
// funcdef: DEF NAME func_action parameters ARROW type_name {
//     CurrST->return_type = ($6).type;
// } COLON suite
// {
//     ST* oldST = CurrST;
//     CurrST = CurrST->parentST;
//     auto fun = new Function;
//     fun->return_type = ($6).type;
//     fun->args = ($4).args;
//     fun->funcST = oldST;
//     auto entry = new STEntry;
//     // cout << "Adding function " << ($2).lex << endl;
//     if(CurrST->type == CLASS_ST){
//         // cout << "Class function" << endl;
//         entry->lex = CurrST->current_Class->name + "." + ($2).lex;
//     }
//     else{
//         // cout << "Global function" << endl;
//         entry->lex = ($2).lex;
//     }
//     ($$)._3AC = "@beginfunc " + entry->lex + ":\n" + "ra = popparam\n" + ($4)._3AC + ($9)._3AC + "goto ra\n" "@endfunc\n";
//     ($$).x86 += ".globl " + entry->lex + "\n";
//     ($$).x86 += ".type " + entry->lex + ", @function\n";
//     ($$).x86 += entry->lex + ":\n";
//     ($$).x86 += "pushq %rbp\n";
//     ($$).x86 += "movq %rsp , %rbp\n";
//     offset = oldST->offset;
//     offset = offset % 16 ? offset + 8 : offset;
//     ($$).x86 += "subq $" + to_string(offset) + ", %rsp\n";
//     ($$).x86 += ($9).x86;
//     ($$).x86 += "leave\n";
//     ($$).x86 += "ret\n";
//     entry->func = fun;
//     entry->lineno = ($1).lineno;
//     CurrST->insert(($2).lex, entry);
// }
// | DEF NAME func_action parameters COLON suite {
//     ST* oldST = CurrST;
//     CurrST = CurrST->parentST;
//     auto fun = new Function;
//     fun->return_type = None_type;
//     fun->args = ($4).args;
//     fun->funcST = oldST;
//     auto entry = new STEntry;
//     // cout << "Adding function " << ($2).lex << endl;
//     if(CurrST->type == CLASS_ST){
//         // cout << "Class function" << endl;
//         entry->lex = CurrST->current_Class->name + "." + ($2).lex;
//     }
//     else{
//         // cout << "Global function" << endl;
//         entry->lex = ($2).lex;
//     }
//     ($$)._3AC = "@beginfunc " + entry->lex + ":\n" + "ra = popparam\n"+ ($4)._3AC +  ($6)._3AC  + "goto ra\n"  + "@endfunc\n";
//     ($$).x86 += ".globl " + entry->lex + "\n";
//     ($$).x86 += ".type " + entry->lex + ", @function\n";
//     ($$).x86 += entry->lex + ":\n";
//     ($$).x86 += "pushq %rbp\n";
//     ($$).x86 += "movq %rsp , %rbp\n";
//     offset = oldST->offset;
//     offset = offset % 16 ? offset + 8 : offset;
//     ($$).x86 += "subq $" + to_string(offset) + ", %rsp\n";
//     ($$).x86 += ($6).x86;
//     ($$).x86 += "leave\n";
//     ($$).x86 += "ret\n";
//     entry->func = fun;
//     entry->lineno = ($1).lineno;
//     CurrST->insert(($2).lex, entry);
// }
// ;

parameters: LEFTBRACKET typedargslist RIGHTBRACKET {
    $$ = $2;
    int cnt = ($$).args_list.size();
    int off = -16;
    for (int i = 0; i < cnt; i++){
        CurrST->offmap[($$).args_list[i].first] = off;
        off -= 8;
    }
    CurrST->offset = 0;
}
| LEFTBRACKET RIGHTBRACKET {
}

typedargslist : argument1 {
    $$ = $1;
    ($$).args.push_back(($1).type);
    ($$).args_list.push_back({($1).lex, ($1).type});
}
| typedargslist COMMA argument1 {
    $$ = $1;
    ($$).args.push_back(($3).type);
    ($$).args_list.push_back({($3).lex, ($3).type});
    
    $$._3AC = ($1)._3AC + ($3)._3AC;
    ($$).x86 = ($1).x86 + ($3).x86;
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
    ($$).x86 = ($3).x86 + assign_x86(($1).lex,($3).lex);
    
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
    ($$).x86 = ($1).x86 + ($3).x86;
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
    ($$).x86 += ($3).x86;
    if (($3).type == Int_type || ($3).type == Bool_type){
        ($$).x86 += print_int_x86(($3).lex);
    }
    else if (($3).type == Str_type){
        ($$).x86 += print_str_x86(($3).lex);
    }
}

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
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << ($3).type.s << " got: " << ($5).type.s << endl;
            exit(1);
        }
        else if (($3).type == Bool_type && ($5).type == Int_type){
            ($$).x86 = int_to_bool_x86(($5).lex);
        }
        else{
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << ($3).type.s << " got: " << ($5).type.s << endl;
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
        ($$).x86 += ($5).x86 + array_assign(($1).lex, to_string(offset), ($5).lex);
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
        ($$).x86 += ($5).x86 + assign_x86(($1).lex,($5).lex);
    }
}
| atom_expr ASSIGN test {

    if (($1).type != ($3).type){
        if (($1).type == Float_type && ($3).type == Int_type){
            ($3).type = Float_type;
        }
        else if (($1).type == Int_type && ($3).type == Float_type){
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << ($1).type.s << " got: " << ($3).type.s << endl;
            exit(1);
        }
        else if (($1).type == Bool_type && ($3).type == Int_type){
            ($$).x86 = int_to_bool_x86(($3).lex);
        }
        else if (($1).type == Int_type && ($3).type == Bool_type){
            ($3).type = Int_type;
        }
        else{
            cerr << "Error! Type mismatch in assignment at line number: " << yylineno << endl;
            cerr << "Expected: " << ($1).type.s << " got: " << ($3).type.s << endl;
            exit(1);
        }
    }
    
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
    if (!($1).is_idx) {
        ($$)._3AC = ($1)._3AC + ($3)._3AC + ($1).lex + " = " + ($3).lex + "\n";
        ($$).x86 = ($1).x86 + ($3).x86 + assign_x86(($1).lex,($3).lex);
    }
    else {
        ($$)._3AC = ($1)._3AC + ($3)._3AC + ($1).lex + "[" + ($1).idx + "] =" + ($3).lex + "\n";
        ($$).x86 = ($1).x86 + ($3).x86 + array_assign(($1).lex,($1).idx,($3).lex);
    }
}
| atom_expr augassign test {
    if (($1).is_assign == 0){
        cerr << "Error! Lvalue required in assignment at line number: " << yylineno << endl;
        exit(1);
    }
    Type t;
    if (!($1).is_attr && !($1).is_idx){
        auto entry = CurrST->lookup(($1).lex);
        t = entry->type;
    }
    else {
        t = ($1).type;
    }
    if(($2).lex=="PLUSEQUAL" || ($2).lex=="MINUSEQUAL" || ($2).lex=="MULTIPLYEQUAL" ||  ($2).lex=="DIVIDEEQUAL" || ($2).lex=="MODEQUAL" ||  ($2).lex=="EXPONENTEQUAL" ){
        if(t != Int_type && t !=Float_type && t!=Bool_type){
            cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
            exit(1);
        }
        if(t==Int_type && ($3).type==Bool_type){
            ($3).type=Int_type;
        }
        if (t == Float_type && ($3).type == Int_type){
            ($3).type = Float_type;
        }
    // if(($3).type==Int_type && ($1).type==Bool_type){
    //     ($1).type=Int_type;
    // }
    // if(($3).type==Bool_type && ($1).type==Bool_type){
    //     ($1).type=Int_type;
    //     ($3).type=Int_type;
    // }
    // if(($1).type==Float_type && ($3).type==Int_type){
    //     ($3).type=Float_type;
    // }
    // if(($3).type==Float_type && ($1).type==Int_type){
    //     ($1).type=Float_type;
    // }
    // if (($1).type != ($3).type){
    //     cerr << "Here Error! Type Mismatch in at line no. " <<yylineno<<endl;
    //     exit(1);
    // }



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
    string idx;
    string src;
    if(($1).is_idx){
        auto dest = newTemp();
        idx = ($1).idx;
        src = ($1).lex;
        ($$)._3AC += dest + " = " + src + "[" + idx + "]\n";
        ($$).x86 += array_deref(dest, src, idx);
        ($1).lex = dest;
    }
    ($$)._3AC = ($$)._3AC + ($3)._3AC + tmpp + " = " + ($1).lex + " " + str + " " + ($3).lex + "\n";
    if(($1).is_idx){
        ($$)._3AC = ($$)._3AC + src + "[" + idx + "] = " + tmpp + "\n"; 
    }
    else ($$)._3AC = ($$)._3AC + ($1).lex + " = " + tmpp + "\n";
    ($$).x86 += ($1).x86 + ($3).x86;
    if (str == "+")
    {
        ($$).x86 += add_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "-")
    {
        ($$).x86 += sub_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "*")
    {
        ($$).x86 += mul_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "/" || str == "//")
    {
        ($$).x86 += div_x86(tmpp,($1).lex,($3).lex);
    }    
    else if (str == "\%")
    {
        ($$).x86 += modul_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "&")
    {
        ($$).x86 += and_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "|")
    {
        ($$).x86 += or_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "^")
    {
        ($$).x86 += xor_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == "<<")
    {
        ($$).x86 += leftshift_x86(tmpp,($1).lex,($3).lex);
    }
    else if (str == ">>")
    {
        ($$).x86 += rightshift_x86(tmpp,($1).lex,($3).lex);
    }
    //temp1 = 1; assign
    //temp2 = 1;
    else if (str == "**")
    {
        ($$).x86 += pow_x86(tmpp,($1).lex,($3).lex);
    }
    if(($1).is_idx){
        ($$).x86 += array_assign(src,idx,tmpp);
    }
    else ($$).x86 += assign_x86(($1).lex,tmpp);
    
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
    ($$).x86 = "jmp " + e_label.top() + "\n";
}

continue_stmt: CONTINUE {
    ($$)._3AC += "goto " + cont_label.top() + "\n";
    ($$).x86 = "jmp " + cont_label.top() + "\n";
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
    $$.x86 = ($2).x86;
    ($$).x86 += "movq " + get_addr(($2).lex) + ", %rax\n";
    $$.x86 += "leave\nret\n";
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
    $$.x86 += "leave\nret\n";
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

    ($$).x86 = ($2).x86 + ifz_x86(($2).lex,($$).next);

} 

if_stmt: dummy_if suite if_stmt_help_1 {
    auto s = newLabel();
    
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + "\n";
    
    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($3).x86 + s + ":\n";
}

| dummy_if suite if_stmt_help {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + "\n";
    
    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($3).x86 + s + ":\n";
}
| dummy_if suite ELSE COLON suite {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($5)._3AC + "@label " + s + "\n";

    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($5).x86 + s + ":\n";
}
| dummy_if suite {
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "@label " + ($1).next + ":\n";
    
    ($$).x86 = ($1).x86 + ($2).x86;
    ($$).x86 += ($1).next + ":\n";
}

dummy_elif : ELIF test COLON {
    ($$).next = newLabel();
    ($$)._3AC = ($2)._3AC + "ifz " + ($2).lex + " goto " + ($$).next + ":\n";
    ($$).x86 = ($2).x86 + ifz_x86(($2).lex,($$).next);
    
}

if_stmt_help : dummy_elif suite {
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "@label " + ($1).next + ":\n";
    ($$).x86 = ($1).x86 + ($2).x86 + ($1).next + ":\n";

}
| dummy_elif suite if_stmt_help {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + ":\n";

    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($3).x86 + s + ":\n";
}

if_stmt_help_1  : dummy_elif suite ELSE COLON suite {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($5)._3AC + "@label " + s + ":\n";

    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($5).x86 + s + ":\n";
}
| dummy_elif suite if_stmt_help_1 {
    auto s = newLabel();
    ($$)._3AC = ($1)._3AC + ($2)._3AC + "goto " + s + "\n" + "@label " + ($1).next + ":\n" + ($3)._3AC + "@label " + s + ":\n";

    ($$).x86 = ($1).x86 + ($2).x86 + "jmp " + s + "\n";
    ($$).x86 += ($1).next + ":\n" + ($3).x86 + s + ":\n";
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
    ($$)._3AC = "@label " + s + ":\n" + ($2)._3AC + "ifz " + ($2).lex + " goto " + e + "\n" + ($5)._3AC + "goto " + s + "\n" + "@label " + e + ":\n";

    ($$).x86 = s + ":\n" + ($2).x86 + ifz_x86(($2).lex,e) + ($5).x86 + "jmp " + s +  "\n" + e + ":\n" ;
    s_label.pop();
    e_label.pop();
}
| WHILE test COLON loop_action suite ELSE COLON suite{
    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    ($$)._3AC = "@label " + s + ":\n" + ($2)._3AC + "ifz " + ($2).lex + " goto " + e + "\n" + ($5)._3AC + "goto " + s + "\n" + "@label " + e + ":\n" + ($8)._3AC + "@label " + f + ":\n";
    ($$).x86 = s + ":\n" + ($2).x86 + ifz_x86(($2).lex,e) + ($5).x86 + "jmp " + s +  "\n" + e + ":\n" + ($8).x86 + f + ":\n";
    s_label.pop();
    e_label.pop();
}

loop_action_1 : {
    auto s = newLabel();
    auto e = newLabel();
    auto c = newLabel();
    s_label.push(s);
    e_label.push(e);
    cont_label.push(c);
}
for_stmt: FOR NAME IN ranges COLON loop_action_1 suite ELSE COLON suite {  
    ($$)._3AC += ($4)._3AC;

    ($$).x86 += ($4).x86;

    auto st = CurrST->lookup(($2).lex);

    ($$)._3AC += ($2).lex + " = " + ($4).rng_start + "\n";

    ($$).x86 += assign_x86(($2).lex, ($4).rng_start);

    auto s = s_label.top();
    auto e = newLabel();
    auto f = e_label.top();
    auto c = cont_label.top();
    auto temp = newTemp();

    ($$)._3AC += "@label " + s + ":\n";
    ($$)._3AC += temp +  "=" + ($2).lex + " < " + ($4).rng_end + "\n";

    ($$).x86 += s + ":\n";
    ($$).x86 += lessth_x86(temp,($2).lex,($4).rng_end);

    auto temp2 = newTemp();

    string incr = temp2 + " = " + ($2).lex + "\n" + ($2).lex + " = " + temp2 + " + 1\n";

    ($$)._3AC += "ifz " + temp + " goto " + e + "\n";
    ($$)._3AC += ($7)._3AC + incr + "goto " + s + "\n";
    ($$)._3AC += "@label " + e + ":\n";
    ($$)._3AC += ($10)._3AC + "@label " + f + ":\n";

    ($$).x86 += s + ":\n" + ifz_x86(temp,e) + ($7).x86 + c + ":\n" + assign_x86(temp2,($2).lex) + add_x86(($2).lex,temp2,to_string(1)) + "jmp " + s + "\n" + e + ":\n" + ($10).x86 + f + ":\n";
 
    s_label.pop();
    e_label.pop();
    cont_label.pop();
}
| FOR NAME IN ranges COLON loop_action_1 suite {
    ($$)._3AC += ($4)._3AC;
    ($$).x86 += ($4).x86;


    auto st = CurrST->lookup(($2).lex);
    
    ($$)._3AC += ($2).lex + " = " + ($4).rng_start + "\n";
    ($$).x86 += assign_x86(($2).lex, ($4).rng_start);

    auto s = s_label.top();
    auto e = e_label.top();
    auto c = cont_label.top();
    auto temp = newTemp();

    ($$)._3AC += "@label " + s + ":\n";
    ($$)._3AC += temp +  " = " + ($2).lex + " < " + ($4).rng_end + "\n";

    ($$).x86 += s + ":\n";
    ($$).x86 += lessth_x86(temp,($2).lex,($4).rng_end);

    auto temp2 = newTemp();
    
    string incr = temp2 + " = " + ($2).lex + "\n" + ($2).lex + " = " + temp2 + " + 1\n";
    ($$)._3AC += "ifz " + temp + " goto " + e + "\n";
    ($$)._3AC += ($7)._3AC;
    ($$)._3AC += "@label " + c + ":\n";
    ($$)._3AC += incr;
    ($$)._3AC += "goto " + s + "\n";
    ($$)._3AC += "@label " + e + ":\n";
    ($$).x86 +=  ifz_x86(temp,e) + ($7).x86 + c + ":\n" + assign_x86(temp2,($2).lex) + add_x86(($2).lex,temp2,to_string(1)) + "jmp " + s + "\n" + e + ":\n" ;

    s_label.pop();
    e_label.pop();
    cont_label.pop();
}

ranges : RANGE LEFTBRACKET test COMMA test RIGHTBRACKET {
    if (($3).type != Int_type){
            cerr << "Error! In range only int type input is allowed: " << yylineno << endl;
            exit(1);
        }
    if (($5).type != Int_type){
            cerr << "Error! In range only int type input is allowed: " << yylineno << endl;
            exit(1);
        }
    ($$).rng_start = ($3).lex;
    ($$).rng_end = ($5).lex;
    
    ($$)._3AC = ($3)._3AC + ($5)._3AC;
    ($$).x86 = ($3).x86 + ($5).x86;
}
| RANGE LEFTBRACKET test RIGHTBRACKET {
    if (($3).type != Int_type){
            cerr << "Error! In range only int type input is allowed: " << yylineno << endl;
            exit(1);
    }
    ($$).rng_start = "0";
    ($$).rng_end = ($3).lex;

    ($$)._3AC = ($3)._3AC;
    ($$).x86 = ($3).x86;
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
    ($$).x86 = ($1).x86 + ($2).x86;
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
    ($$).x86 = ($1).x86 + ($3).x86 + or_or_x86(($$).lex, ($1).lex, ($3).lex);
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
    ($$).x86 = ($1).x86 + ($3).x86 + and_and_x86(($$).lex, ($1).lex, ($3).lex);
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
    ($$).x86 = ($2).x86 + not_x86(($$).lex, ($2).lex);
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

    ($$).x86 = ($1).x86 + ($3).x86;

    if (($2).lex == "==")
    {
        if(string_comp) ($$).x86 += equal_str_x86(($$).lex, ($1).lex, ($3).lex);
        else ($$).x86 += equal_x86(($$).lex, ($1).lex, ($3).lex);
    }
    else if (($2).lex == "<")
    {
        if(string_comp) ($$).x86 +=lessth_str_x86(($$).lex, ($1).lex, ($3).lex);
        else ($$).x86 +=lessth_x86(($$).lex, ($1).lex, ($3).lex);
    }
    else if (($2).lex == ">")
    {
        if (string_comp) ($$).x86 += greaterth_str_x86(($$).lex, ($1).lex, ($3).lex);
        else ($$).x86 += greaterth_x86(($$).lex, ($1).lex, ($3).lex);
    }
    else if (($2).lex == ">=")
    {
        if(string_comp)($$).x86 += greater_than_equal_str_x86(($$).lex, ($1).lex, ($3).lex);
        else($$).x86 += greater_than_equal_x86(($$).lex, ($1).lex, ($3).lex);
    }
    else if (($2).lex == "<=")
    { 
        if(string_comp) ($$).x86 +=less_than_equal_str_x86(($$).lex, ($1).lex, ($3).lex);
        else ($$).x86 +=less_than_equal_x86(($$).lex, ($1).lex, ($3).lex);
    }
    else if (($2).lex == "!=")
    {
        if(string_comp)($$).x86 += not_equal_str_x86(($$).lex, ($1).lex, ($3).lex);
        else ($$).x86 += not_equal_x86(($$).lex, ($1).lex, ($3).lex);
    }

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
    ($$).x86=($1).x86 + ($3).x86 + xor_x86(($$).lex,($1).lex,($3).lex);

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
    ($$).x86=($1).x86 + ($3).x86 + bitor_x86(($$).lex,($1).lex,($3).lex);
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
    ($$).x86=($1).x86+ ($3).x86 + and_x86(($$).lex,($1).lex,($3).lex);
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
    ($$).x86=($1).x86+ ($3).x86 + leftshift_x86(($$).lex,($1).lex,($3).lex);
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
    ($$).x86=($1).x86+ ($3).x86 + rightshift_x86(($$).lex,($1).lex,($3).lex);
}

arith_expr: term {
    $$ = $1;
}

| arith_expr PLUS term {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Here Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();

    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " + " + ($3).lex + "\n");

    // quad q = {"+", ($1).lex, ($3).lex, ($$).lex};
    // CurrST->code.push_back(quad);

    // //x86
    ($$).x86 = ($1).x86 + ($3).x86;

    ($$).x86 = ($$).x86 + add_x86(($$).lex,($1).lex,($3).lex);
    
}
| arith_expr MINUS term {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " - " + ($3).lex + "\n");

    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).x86 = ($$).x86 + sub_x86(($$).lex,($1).lex,($3).lex);
}

term : factor {
    $$=$1;
}

| term MULTIPLY factor {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " * " + ($3).lex + "\n");
    
    
    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).x86 = ($$).x86 + mul_x86(($$).lex,($1).lex,($3).lex);
}

| term DIVIDE factor {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " / " + ($3).lex + "\n");

    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).x86 = ($$).x86 + div_x86(($$).lex,($1).lex,($3).lex);

}
| term MOD factor {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " \% " + ($3).lex + "\n"); 

    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).x86 = ($$).x86 + modul_x86(($$).lex,($1).lex,($3).lex);
}
| term DIVIDEDIVIDE factor {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    ($$).type = Int_type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " // " + ($3).lex + "\n");

    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).x86 = ($$).x86 + div_x86(($$).lex,($1).lex,($3).lex);

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
        ($2).type=Int_type;  // Boolean Typecasting
    }
    ($$) = ($2);

    
}
| MINUS factor {
    if(($2).type != Int_type && ($2).type !=Float_type && ($2).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if(($2).type==Bool_type){
        ($2).type=Int_type;  // Boolean Typecasting
    }
    ($$).type =($2).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($2)._3AC + (($$).lex + " = " + " -" + ($2).lex + "\n");

    ($$).x86 = ($2).x86 + neg_x86(($$).lex,($2).lex);
}
| BITNOT factor {
    if(($2).type != Int_type && ($2).type !=Float_type && ($2).type !=Bool_type){  // Boolean Typecasting
        cerr<<"Error! Unsupported type at line no. "<<yylineno<<endl;
        exit(1);
    }
    if(($2).type==Bool_type){
        ($2).type=Int_type;  // Boolean Typecasting
    }
    ($$).type =($2).type;
    ($$).lex=newTemp();
    ($$)._3AC = ($2)._3AC + (($$).lex + " = " + " ~" + ($2).lex + "\n");

    ($$).x86 = ($2).x86 + bitnot_x86(($$).lex,($2).lex);
}

power : atom_expr_1 {
    $$=$1;   
}

| atom_expr_1 EXP factor {
    if(($1).type==Int_type && ($3).type==Bool_type){
        ($3).type=Int_type;
    }
    if(($3).type==Int_type && ($1).type==Bool_type){
        ($1).type=Int_type;
    }
    if(($3).type==Bool_type && ($1).type==Bool_type){
        ($1).type=Int_type;
        ($3).type=Int_type;
    }
    if(($1).type==Float_type && ($3).type==Int_type){
        ($3).type=Float_type;
    }
    if(($3).type==Float_type && ($1).type==Int_type){
        ($1).type=Float_type;
    }
    
    if(($1).type != Int_type && ($1).type !=Float_type && ($1).type !=Bool_type){
        cerr<<"Error! Unsupported at line no. "<<yylineno<<endl;
        exit(1);
    }
    if (($1).type != ($3).type){
        cerr << "Error! Type Mismatch in at line no. " <<yylineno<<endl;
        exit(1);
    }
    
    ($$).type = ($1).type;
    ($$).lex = newTemp();
    ($$)._3AC = ($1)._3AC + ($3)._3AC + (($$).lex + " = " + ($1).lex + " ** " + ($3).lex + "\n");

    //ADD EXPONENTIAL X86
    ($$).x86 = ($1).x86 + ($3).x86 +  pow_x86(($$).lex,($1).lex,($3).lex);

}
atom_expr_1 : atom_expr {
    $$ = $1;
    if(($1).is_idx){
        auto dest = newTemp();
        auto idx = ($1).idx;
        auto src = ($1).lex;
        ($$)._3AC += dest + " = " + src + "[" + idx + "]\n";
        ($$).lex = dest;
        ($$).x86 += array_deref(dest, src, idx);
        ($$).is_idx = 0;
    }
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
        ($$)._3AC += ($2)._3AC;
        auto temp = newTemp();
        ($$)._3AC += temp + " = " + ($2).lex + " + 1\n";
        ($$)._3AC += temp + " = " + temp + " * " + to_string(8) + "\n";
        ($$).lex = ($1).lex;
        ($$).idx = temp;
        ($$).x86 = ($2).x86;
        ($$).x86 += add_x86(temp, ($2).lex, to_string(1));
        ($$).x86 += mul_x86(temp, temp, to_string(8));
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
        ($$).x86 = ($2).x86;
        auto temp = newTemp();
        ($$)._3AC += temp + " = " +  ($2).lex  + " + 1\n";
        ($$).x86 += add_x86(temp, ($2).lex ,to_string(1));
        ($$)._3AC += temp + " = " + temp + " * " + to_string(8) + "\n";
        ($$).x86 += mul_x86(temp, temp , to_string(8));
        auto temp2 = newTemp();
        ($$)._3AC += temp2 + " = " + ($1).lex + "[" + to_string(attr->offset) + "]\n";
        ($$).x86 += array_deref(temp2, ($1).lex, to_string(attr->offset));
        ($$).lex = temp2;
        ($$).idx = temp;
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
        // cout << "Looking up _ for " << ($1).attr_name << "\n";
        // if(cls->parent) cout << cls->parent->name << "\n";
        auto attr = cls->classST->lookupClassAttr(($1).attr_name);
        if(attr->func){
            cerr << "Error : Not an attribute\n";
            exit(1);
        }
        ($$).type = attr->type;
        // cout << "here\n";
        ($$).lex = ($1).lex;
        ($$).is_idx = 1;
        ($$).idx = to_string(attr->offset);
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
    $$ = $2;
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
        
        ($$).x86 += array_deref(($$).lex, ($2).args_list[0].first, to_string(0));
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
            exit(1);
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
        ($$).x86 = ($2).x86;

        if (($2).args_list.size()%2) {
            ($2).args_list.push_back({to_string(0),Int_type});
        }
        for (int i = ($2).args_list.size() - 1; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        for (int i = ($2).args_list.size() - 1; i >= 0 ; i--){
            ($$).x86 += push_x86(($2).args_list[i].first);
        }
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + mthd->lex + " " + to_string(($2).args_list.size()) + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        ($$).x86 += "call " + mthd->lex + "\n";
        ($$).x86 += "addq $" + to_string(8*($2).args_list.size()) + ", %rsp\n";
        if (mthd->func->return_type != None_type){
            ($$).lex = newTemp();
            ($$)._3AC += ($$.lex + " = " + "popparam\n");
            ($$).x86 += "mov %rax, " + get_addr(($$).lex) + "\n";
        }
    }
    else if (entry->cls){ // it's a constructor

        auto ctor = entry->cls->classST->lookup("__init__")->func;
        if (ctor->args.size() != ($2).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;
            exit(1);
        } 
        for (int i = 0; i < ctor->args.size() - 1; i++){
            if (ctor->args[i+1] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
                    exit(1);
            }
        }
        ($$).type = {($1).lex,0};
        ($$)._3AC += "param " + to_string(entry->cls->classST->offset) + "\n";
        ($$)._3AC += "call memalloc 1\n";
        auto temp = newTemp();
        ($$)._3AC += "popparam " + temp + "\n"; 
        ($$).x86 += malloc_x86(to_string(entry->cls->classST->offset),temp);
        if(($2).args_list.size()%2 == 0){
            ($2).args_list.push_back({to_string(0), Int_type});
        }
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$).x86 += push_x86(($2).args_list[i].first);
        }
        ($$)._3AC += "param " + temp + "\n"; 
        ($$).x86 += push_x86(temp);
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + ($1).lex + ".__init__ " + to_string(ctor->args.size()) + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        ($$).x86 += "call " + ($1).lex + ".__init__\n";
        ($$).x86 += "addq $" + to_string(8*($2).args_list.size()+8) + ", %rsp\n";
        ($$).lex = temp;
    }
    else if (($1).is_attr) {
        auto cls = CurrST->lookup(entry->type.s)->cls;
        auto mthd_S = cls->classST->lookupClassAttr(($1).attr_name);
        auto mthd = mthd_S->func;
        if (mthd->args.size() != ($2).args_list.size() + 1) {
            cout << "Error number of arguments do not match at line no. " << yylineno << endl;;
            exit(1);
        } 
        for (int i = 0; i < mthd->args.size() - 1; i++){
            if (mthd->args[i+1] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
                    exit(1);
            }
        }
        ($$).type = mthd->return_type;
        if(($2).args_list.size()%2 == 0){
            ($2).args_list.push_back({to_string(0), Int_type});
        }
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$)._3AC += "param " + ($2).args_list[i].first + "\n";
        }
        for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
            ($$).x86 += push_x86(($2).args_list[i].first);
        }
        ($$)._3AC += "param " + ($1).lex + "\n";
        ($$).x86 += push_x86(($1).lex);
        ($$)._3AC += "stackpointer +xxx\n";
        ($$)._3AC += "call " + mthd_S->lex + " " + to_string(mthd->args.size()) + "\n";
        ($$).x86 += "call " + mthd_S->lex + "\n";
        ($$)._3AC += "stackpointer -yyy\n";
        ($$).x86 += "addq $" + to_string(8*($2).args_list.size()+8) + ", %rsp\n";
        if (mthd->return_type != None_type){
            ($$).lex = newTemp();
            ($$)._3AC += ($$.lex + " = " + "popparam\n");\
            ($$).x86 += "mov %rax, " + get_addr(($$).lex) + "\n";
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
                exit(1);
            }
            if (($1).func->args.size() != ($2).args_list.size()){
                cout << "Error! number of arguments do not match at line no. "<< yylineno << endl;
                exit(1);
            }
            for (int i = 0; i < ($1).func->args.size(); i++){
                if (($1).func->args[i] != ($2).args_list[i].second){
                    cout << "Error! Type of arguments do not match at line no. "<< yylineno << endl;
                    exit(1);
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
            
            //x86
            ($$).x86 = ($2).x86;
            if(($2).args_list.size()%2){
                ($2).args_list.push_back({to_string(0),Int_type});
            }
            for (int i = ($2).args_list.size() - 1 ; i >= 0 ; i--){
                ($$).x86 += push_x86(($2).args_list[i].first);
            }
            ($$).x86 += "call " + ($1).lex + "\n";
            ($$).x86 += "addq $" + to_string(8*($2).args_list.size()) + ", %rsp\n";
            if (($1).func->return_type != None_type){
                ($$).x86 += "movq %rax, " + get_addr(($$).lex) + "\n";
            }
        }
    }
    }
}

lvalue : NAME {
    $$ = $1;
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
        // cout << "Looking up for " << ($2).lex << " in class " << cls->name << "\n";
        // cout << "Parent =" << cls->parent->name << "\n";
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
    ($$)._3AC += temp + " = " + to_string(($2).args_list.size()+1) + " * " + to_string(8) + "\n";
    ($$)._3AC += "param " + temp + "\n";
    ($$)._3AC += "call memalloc 1\n";
    auto temp2 = newTemp();
    ($$)._3AC += "popparam " + temp2 + "\n";
    ($$)._3AC += temp2 + "[" + to_string(0) + "]" + " = " + to_string(($2).args_list.size()) + "\n";
    for (int i = 0; i < ($2).args_list.size(); i++){
        ($$)._3AC += temp2 + "[" + to_string(8*(i+1)) + "]" + " = " + ($2).args_list[i].first + "\n";
    }
    ($$).lex = temp2;
    ($$).sz = ($2).args_list.size();
    ($$).x86 = ($2).x86;
    ($$).x86 += mul_x86(temp, to_string(($2).args_list.size()+1), to_string(8));
    ($$).x86 += malloc_x86(temp, temp2);
    ($$).x86 += array_assign(temp2, to_string(0), to_string(($2).args_list.size()));
    for (int i = 0; i < ($2).args_list.size(); i++){
        ($$).x86 += array_assign(temp2, to_string((i+1)*8), ($2).args_list[i].first);
    }
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
    if(($1).lex[0] == '\''){
        string s = "";
        for(auto &x : ($1).lex){
            if(x == '\"'){
                s += "\\\"";
            }
            else {
                s += x;
            }
        }
        ($1).lex = s;
        ($1).lex[0] = '\"';
        ($1).lex[($1).lex.size()-1] = '\"';
    }
    ($$).lex = newString(($1).lex);
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
    ($$).args_list.clear();
    ($$).args_list.push_back({($1).lex, ($1).type});
}       

| testlist_list COMMA test {
    type_check($3,$1);
    ($$)._3AC = ($1)._3AC + ($3)._3AC;
    ($$).x86 = ($1).x86 + ($3).x86;
    ($$).type = ($1).type;
    ($$).args_list.push_back({($3).lex, ($3).type});
}        
            
classdef: CLASS NAME COLON 
{
    //printf("Class Begins Here\n");
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    ST* oldST = CurrST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = ($2).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[($2).lex] = CurrST;
    auto cls = CurrST->current_Class;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    entry->func = NULL;
    oldST->insert(($2).lex, entry);
} 
suite {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[($2).lex] = cls->classST->offset;
    cls->parent = NULL;
    ($$)._3AC = ($5)._3AC;
    ($$).x86 = ($5).x86;
}
| CLASS NAME LEFTBRACKET RIGHTBRACKET COLON 
{
    ST *newST = new ST;
    newST->parentST = CurrST;
    newST->type = CLASS_ST;
    ST* oldST = CurrST;
    CurrST = newST;
    CurrST->current_Class = new Class;
    CurrST->current_Class->name = ($2).lex; 
    CurrST->current_Class->classST = CurrST;
    cls_ST[($2).lex] = CurrST;
    auto cls = CurrST->current_Class;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    entry->func = NULL;
    oldST->insert(($2).lex, entry);
} 
suite {
    ST* oldST = CurrST;
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[($2).lex] = cls->classST->offset;
    cls->parent = NULL;
    ($$)._3AC = ($7)._3AC;
    ($$).x86 = ($7).x86;
}

| CLASS NAME LEFTBRACKET NAME {

    ST *newST = new ST;
    ST *oldST = CurrST;
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
    auto cls = CurrST->current_Class;
    auto entry = new STEntry;
    entry->lex = ($2).lex;
    entry->cls = cls;
    entry->lineno = ($1).lineno;
    entry->func = NULL;
    oldST->insert(($2).lex, entry);

} RIGHTBRACKET COLON suite {
    auto cls = CurrST->current_Class;
    CurrST = CurrST->parentST;
    sz[($2).lex] = cls->classST->offset;
    
    ($$)._3AC = ($8)._3AC;
    ($$).x86 = ($8).x86;
}

arglist: arglist_help {
    $$ = $1;
}
| arglist_help COMMA {
   $$ = $1;
}

arglist_help: argument {
    $$ = $1;
    $$.args_list.clear();
    $$.args_list.push_back({($1).lex, ($1).type});
}
| arglist_help COMMA argument {
    $$ = $1;
    ($$).args_list.push_back({($3).lex, ($3).type});
    $$._3AC = ($1)._3AC + ($3)._3AC;
    ($$).x86 = ($1).x86 + ($3).x86;
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
    if (argc != 3) {
        printf("Usage: %s --input=<input_file> --output=<output_file>\n", argv[0]);
        return 1; // Exit with an error code
    }

    // Variables to store input and output file paths
    char *inputFilePath = NULL;
    char *outputFilePath = NULL;

    // Loop through command-line arguments to extract input and output file paths
    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "--input=", 8) == 0) {
            inputFilePath = argv[i] + 8; // Extract input file path
        } else if (strncmp(argv[i], "--output=", 9) == 0) {
            outputFilePath = argv[i] + 9; // Extract output file path
        }
    }

    // Check if both input and output file paths are provided
    if (inputFilePath == NULL || outputFilePath == NULL) {
        printf("Error: Both input and output file paths must be provided.\n");
        return 1; // Exit with an error code
    }
    
    indent_cnt.push(0);
    auto GlobalST = new ST;
    GlobalST->parentST = NULL;
    CurrST = GlobalST;
    STEntry* name = new STEntry;
    name->lex = "__name__";
    name->type = {"str", 0};
    GlobalST->insert("__name__", name);
    GlobalST->offset = 0;
    freopen(inputFilePath, "r", stdin);
    yyparse();
    freopen("Global.csv", "w", stdout);
    GlobalST->print();
    freopen((string(inputFilePath)+".3ac").c_str(), "w", stdout);
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
    str_map[string("str0")] = "\"%d\\n\"";
    string init_str = ".section .data\n";
    for(auto x : str_map) {
    init_str += x.first + ":\n";
    init_str += ".string " + x.second + "\n";
    }
    init_str += ".text\n";
    res_x86 = init_str + res_x86;
    freopen(outputFilePath, "w", stdout);
    cout << res_x86;
    return 0;
}
