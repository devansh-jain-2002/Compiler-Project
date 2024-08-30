#include<bits/stdc++.h>
using namespace std;
struct ST;
static void printST(ST* st);
extern int yylineno;
static string newTemp();
static string newLabel() {
    static int label_count = 0;
    return "L" + to_string(label_count++);
}
static map <string, int> sz = {{"int",8},{"float",8},{"str",8},{"bool",8}};

static map <string, bool > is_global;
struct quad {
    string op;
    string arg1;
    string arg2;
    string res;
};
struct Type {
    string s;
    int is_list;
    bool operator == (const Type& t) const {
        return s == t.s && is_list == t.is_list;
    }
    bool operator!= (const Type& t) const {
        return !(*this == t);
    }
};
static void printType(Type t){
    if (t.is_list) {
        cout << "list[" << t.s << "]";
    }
    else cout << t.s;
}
struct Function {
    Type return_type={"", 0};
    vector<Type> args;
    ST* funcST=NULL;
};
struct ClassAttr {
    Type type={"", 0};
    int offset=-1;
};
struct Class {
    Class* parent=NULL;
    string name="";
    ST* classST=NULL;
    map<string, ClassAttr> attr;
};
struct STEntry {
    string lex = "";
    int addr = -1;
    int lineno = -1;
    int offset = -1;
    Type type = {"", 0};
    Function* func = NULL;
    Class* cls = NULL;
    int is_arg = 0; // 1 if it is an function argument
    int is_attr = 0; // 1 if it is a class attribute
    void print(){
        if (func != NULL) { // Token, lexeme, type, offset, line number
            cout << "FUNCTION, " << lex << ", ";
            // cout << "Function " << lex << ":";
            for (int i = 0; i < func->args.size(); i++) {
                printType(func->args[i]);
                if (i != func->args.size() - 1) {
                    cout << " x ";
                }
            }
            if (func->args.size() == 0) {
                cout << "void";
            }
            cout << "->";
            printType(func->return_type);
            cout << ", " << 0 << ", " << lineno << endl;
            // cout << endl;
        }
        else if (cls != NULL) {
            cout << "CLASS, " << lex << ", ";
            cout << ",, " << 0 << ", " << lineno << endl;
        }
        else { // Token, lexeme, type, offset, line number
            cout << "IDENTIFIER, " << lex << ", ";
            printType(type);
            cout << ", " << offset << ", " << lineno << endl;
        }
    }
};
struct ST {
    int offset = 0;
    int type = 0;
    map<string, STEntry*> mapS;
    map<string, int> offmap;
    ST *parentST = NULL;
    ST *parentClassST = NULL;
    Type return_type = {"", 0};
    Class *current_Class = NULL;
    vector <quad> code;
    void insert(string name, STEntry* entry) {
        // cout << "Inserting " << name << endl;
        // cout << "Current Class: " << (current_Class == NULL ? "NULL" : current_Class->name) << endl;
        if (mapS.find(name) != mapS.end()) {
            cerr << "Error : Redeclaration of " << name << " at line number " << yylineno << endl;
            exit(1);
        }
        if (is_global[name]) {
            ST* tempST = this;
            while (tempST->parentST != NULL) {
                tempST = tempST->parentST;
            }
            if (tempST->mapS.find(name) != tempST->mapS.end()) {
                cerr << "Error : Redeclaration of global" << name << " at line number " << yylineno << endl;
                exit(1);
            }
            tempST->mapS[name] = entry;
            entry->offset = offset;
            offset += sz[entry->type.s];
            return;
        }
        mapS[name] = entry;
        if (entry->cls == NULL && entry->func == NULL) {
            entry->offset = offset;
            offmap[name] = offset + 8;
            offset += 8;
            // if (sz[entry->type.s] == 0){
            //     sz[entry->type.s] = 8;
            // }
            // if (sz [entry->type.s] > 8 || entry->type.is_list){
            //     offset += 8;
            // }
            // else {
            //     offset += sz[entry->type.s];
            // }
        }
    }
    STEntry* lookup(string name) {
        if (mapS.find(name) == mapS.end()) {
            if (parentST != NULL) {
                return parentST->lookup(name);
            }
            cout << "Symbol " << name << " not found " << " at line number " << yylineno << endl;
            exit(1);
        }
        return mapS[name];
    }
    STEntry *lookupClassAttr(string name) {
        // cout << "Looking up " << name << endl;
        if (mapS.find(name) == mapS.end()) {
            // cout << "Looking up in " << current_Class->name << "\n";
            if (current_Class->parent != NULL) {
                // cout << "Looking up in " << current_Class->parent->name << "\n"; 
                return current_Class->parent->classST->lookupClassAttr(name);
            }
            cout << "Attribute/method " << name << " not found" << " at line number " << yylineno << endl;
            exit(1);
        }
        if (type != 2) {
            cout << "Symbol " << name << " not found" << " at line number " << yylineno << endl;
            exit(1);
        }
        return mapS[name];
    }
    void print(){
        cout << "Token, Lexeme, Type, Offset, Line Number\n";
        map <string, Function*> func_map;
        map <string, Class*> class_map;
        for(auto entry: mapS){
            if(entry.second->func != NULL){
                // // cout << "Function " << entry.first << ":\n";  
                // entry.second->func->funcST->print();
                // cout << "End of Function " << entry.first << endl;
                func_map[entry.second->lex] = entry.second->func;
            }
            else if(entry.second->cls != NULL){
                // cout << "Class " << entry.first << ":\n";
                // entry.second->cls->classST->print();
                // cout << "End of Class : " << entry.first << endl;
                class_map[entry.first] = entry.second->cls;
            }
            entry.second->print();
        }
        for (auto entry: func_map){
            // change output file to funcname.csv
            freopen((entry.first + ".csv").c_str(), "w", stdout);
            entry.second->funcST->print();
        }
        for (auto entry: class_map){
            // change output file to classname.csv
            freopen((entry.first + ".csv").c_str(), "w", stdout);
            entry.second->classST->print();
        }
    }
};
static void printST(ST* st){
    st->print();
}
static ST* CurrST;
// map <string, int> off_map;



static string newTemp(){
    static int temp_count = 0;
    string res = "#t" + to_string(temp_count++);
    CurrST->offmap[res] = CurrST->offset + 8;
    CurrST->offset += 8;
    return res;
}
enum STType {
    GLOBAL_ST,
    FUNCTION_ST,
    CLASS_ST
};
enum TrailerType {
    LIST_ACCESS,
    FUNCTION_CALL,
    ATTR_ACCESS
};
struct semantic_value_type {
    int addr;
    int lineno;
    string lex;
    Type type;
    string next;
    vector<Type> args;
    vector<pair<string, Type>> args_list;
    vector<quad> code;
    Function* func;
    Class* cls;
    TrailerType trailer_type;
    bool is_attr;
    string _3AC;
    int sz = 0;
    int is_idx = 0;
    int offset;
    string rng_start;
    string rng_end;
    string attr_name;
    int is_assign = 0;
    bool is_class = false;
    string x86;
    string idx;
};


static string get_addr(string src) {
    if(CurrST->offmap.find(src)==CurrST->offmap.end())
        return "$" + src;
    else
        return to_string(-CurrST->offmap[src]) + "(\%rbp)";
}

static string call_strcmp (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rdi\n";
    s += "movq " + src2 + ", %rsi\n";
    s += "call strcmp\n";
    s += "cltq\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}
static string print_int_x86(string src) {
    src = get_addr(src);
    string s;
    s += "movq " + src + ", %rsi\n";
    s += "movq $str0 , %rdi\n";
    s += "movq $0, %rax\n";
    s += "call printf\n";
    return s;
}

static string int_to_bool_x86(string &src){
    if(CurrST->offmap.find(src)==CurrST->offmap.end()){
        src = to_string(stoi(src)>=1);
        return "";
    }
    src = get_addr(src);
    string s;
    s += "movq " + src + ", %r8\n";
    s += "cmpq    $0, %r8\n";
    s += "setg    \%al\n";
    s += "movzbl  \%al, \%eax\n";
    s += "movq    %rax, " + src + "\n";
    return s;
}

static string print_str_x86(string src) {
    string s;
    s += "movq " + get_addr(src) + ", %rdi\n";
    s += "call puts\n";
    return s;
}

static string malloc_x86(string cnt, string dest){
    string s;
    dest = get_addr(dest);
    cnt = get_addr(cnt);
    s += "movq " + cnt + ", %rdi\n";
    s += "call malloc\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string push_x86(string src){
    return "pushq " + get_addr(src) + "\n";
}
static string add_x86(string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "addq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string sub_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "subq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string mul_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "imulq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string div_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "movq " + src2 + ", %r8\n";
    s += "cqto\n";
    s += "idivq %r8\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string leftshift_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "movq " + src2 + ", %rcx\n";    
    s += "salq \%cl, %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string rightshift_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "movq " + src2 + ", %rcx\n";    
    s += "sarq \%cl, %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string lessth_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";    
    s += "setl \%al\n";
    s += "andb $1, \%al\n"; 
    s += "movzbl \%al, \%eax\n"; 
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string lessth_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += lessth_x86(dest, temp, to_string(0));
    return s;
}

static string greaterth_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";    
    s += "setg \%al\n";
    s += "andb $1, \%al\n"; 
    s += "movzbl \%al, \%eax\n"; 
    s += "movq %rax, " + dest + "\n";
    return s;
}
static string greaterth_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += greaterth_x86(dest, temp, to_string(0));
    return s;
}

static string modul_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";   
    s += "movq " + src2 + ", %r8\n";
    s += "cqto\n";
    s += "idivq %r8\n"; 
    s += "movq %rdx, " + dest + "\n";
    return s;
}

static string xor_x86(string dest, string src1, string src2)
{
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";   
    s += "xorq " + src2 + ", %rax\n";  
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string ifz_x86 (string src, string addr) {
    src = get_addr(src);
    string s;
    s += "movq " + src + ", %r9\n"; 
    s += "cmpq $0 , %r9\n";
    s += "je " + addr + "\n";
    return s;
}

static string assign_x86 (string dest, string src) {
    dest = get_addr(dest);
    src = get_addr(src);
    string s;
    s += "movq " + src + " , %rax\n";
    s += "movq " + string("%rax, ") + dest + "\n";
    return s; 
}

// a = s [i]

static string array_deref(string dest, string src, string idx) {
    dest = get_addr(dest);
    idx = get_addr(idx);
    src = get_addr(src);
    string s;
    s += "movq " + src + " , %rax\n";
    s += "movq " + idx + " , %rcx\n";
    s += "movq (%rax, %rcx) , %rdx\n";
    s += "movq %rdx, " + dest + "\n";
    return s;
}

// string power_x86(string dest, string src1, string src2) {
//     dest = get_addr(dest);
//     src1 = get_addr(src1);
//     src2 = get_addr(src2);
    
// }

// s[i] = a

static string array_assign(string dest, string idx, string src){
    dest = get_addr(dest);
    idx = get_addr(idx);
    src = get_addr(src);
    string s;
    s += "movq " + src + ", %rdx\n";
    s += "movq " + dest + ", %rax\n";
    s += "movq " + idx + ", %rcx\n";
    s += "movq %rdx , (%rax, %rcx)\n";
    return s;
}


//     c = a - 1;
//     c = a / b;
//     c = a * b;
//     c = a >> b;
//     c = a << b;
//     c = a > b;
//     c = a < b;

    // c = a == b;//
    // c = a != b;//
    // c = a & b;//
    // c = a | b;//
    // c = !a;//
    // c = -a;//
    // c = a >= b;//
    // c = a <=b;//

        //c = a&&b
static string equal_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";
    s += "sete \%al\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}
static string equal_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += equal_x86(dest, temp, to_string(0));
    return s;
}
static string not_equal_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";
    s += "setne \%al\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}
static string not_equal_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += not_equal_x86(dest, temp, to_string(0));
    return s;
}

static string and_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "andq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}


static string or_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "orq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string not_x86  (string dest, string src) {
    src = get_addr(src);
    dest = get_addr(dest);
    string s;
    s += "cmpq " + src + ", %rax\n";
    s += "sete \%al\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string neg_x86  (string dest, string src) {
    src = get_addr(src);
    dest = get_addr(dest);
    string s;
    s += "movq " + src + ", %rax\n";
    s += "negq \%rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string greater_than_equal_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";
    s += "setge \%al\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string greater_than_equal_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += greater_than_equal_x86(dest, temp, to_string(0));
    return s;
}
static string less_than_equal_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "cmpq " + src2 + ", %rax\n";
    s += "setle \%al\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string less_than_equal_str_x86(string dest, string src1, string src2) {
    auto temp = newTemp();
    string s;
    s += call_strcmp(temp, src1, src2);
    s += less_than_equal_x86(dest, temp, to_string(0));
    return s;
}

static string and_and_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %r8\n";
    s += "cmpq $0,  %r8\n";
    s += "setg \%dl\n";
    s += "movq " + src2 + ", %r9\n";
    s += "cmpq $0,  %r9\n";
    s += "setg \%al\n";
    s += "andl \%edx, \%eax\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string or_or_x86  (string dest, string src1, string src2) {
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %r8\n";
    s += "cmpq $0,  %r8\n";
    s += "setg \%dl\n";
    s += "movq " + src2 + ", %r9\n";
    s += "cmpq $0,  %r9\n";
    s += "setg \%al\n";
    s += "orl \%edx, \%eax\n";
    s += "movzbl \%al, \%eax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string bitnot_x86  (string dest, string src) {
    src = get_addr(src);
    dest = get_addr(dest);
    string s;
    s += "movq " + src + ", %rax\n";
    s += "notq \%rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}

static string bitor_x86 (string dest, string src1, string src2){
    src1 = get_addr(src1);
    src2 = get_addr(src2);
    dest = get_addr(dest);
    string s;
    s += "movq " + src1 + ", %rax\n";
    s += "orq " + src2 + ", %rax\n";
    s += "movq %rax, " + dest + "\n";
    return s;
}



static string pow_x86(string dest, string src1, string src2){

    string s;

    auto t_1 = newTemp();
    auto t_2 = newTemp();

    s += assign_x86(dest, to_string(1));
    s += assign_x86(t_2, to_string(1));

    auto l_1 = newLabel();

    s += "jmp " + l_1 +"\n" ;

    auto l_2 = newLabel();

    s += l_2 + " :\n";
    s += mul_x86(dest,dest,src1);

    s += add_x86(t_2,t_2,to_string(1));
    s += l_1 + " :\n";
    
    s += "movq " + get_addr(src2) + ", %r9\n";
    s += "cmpq %r9, " + get_addr(t_2) + "\n";
    s += "jle " + l_2 + "\n";
    return s;
}

