#include<bits/stdc++.h>
using namespace std;
struct ST;
static void printST(ST* st);
static string newTemp();
static string newLabel() {
    static int label_count = 0;
    return "L" + to_string(label_count++);
}
static map <string, int> sz = {{"int",4},{"float",4},{"str",8},{"bool",4}};
static map <string, bool > is_global;
struct Type {
    string s;
    int is_list;
    bool operator == (const Type& t) const {
        if ( this->s == "int" && t.s == "float" && this -> is_list == t.is_list) {
            return true;
        }
        else if ( this->s == "float" && t.s == "int" && this -> is_list == t.is_list) {
            return true;
        }
        else if (this->s == "bool" && t.s == "int" && this -> is_list == t.is_list) {
            return true;
        }
        else if (this->s == "int" && t.s == "bool" && this -> is_list == t.is_list) {
            return true;
        }
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
    ST *parentST = NULL;
    ST *parentClassST = NULL;
    Type return_type = {"", 0};
    Class *current_Class = NULL;
    void insert(string name, STEntry* entry) {
        // cout << "Inserting " << name << endl;
        // cout << "Current Class: " << (current_Class == NULL ? "NULL" : current_Class->name) << endl;
        // cout << "Here, inserting " + name + "\n";
        if (mapS.find(name) != mapS.end()) {
            cerr << "Error : Redeclaration of " << name << endl;
            exit(1);
        }
        if (is_global[name]) {
            ST* tempST = this;
            while (tempST->parentST != NULL) {
                tempST = tempST->parentST;
            }
            if (tempST->mapS.find(name) != tempST->mapS.end()) {
                cerr << "Error : Redeclaration of global" << name << endl;
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
            if (sz[entry->type.s] == 0){
                sz[entry->type.s] = 8;
            }
            if (sz [entry->type.s] > 8 || entry->type.is_list){
                offset += 8;
            }
            else {
                offset += sz[entry->type.s];
            }
        }
    }
    STEntry* lookup(string name) {
        if (mapS.find(name) == mapS.end()) {
            if (parentST != NULL) {
                return parentST->lookup(name);
            }
            cout << "Symbol " << name << " not found\n";
            exit(1);
        }
        return mapS[name];
    }
    STEntry *lookupClassAttr(string name) {
        // cout << "Looking up " << name << endl;
        if (mapS.find(name) == mapS.end()) {
            if (current_Class->parent != NULL) {
                return current_Class->parent->classST->lookupClassAttr(name);
            }
            cout << "Attribute/method " << name << " not found\n";
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
static string newTemp(){
    static int temp_count = 0;
    return "t" + to_string(temp_count++);
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
    Function* func;
    Class* cls;
    TrailerType trailer_type;
    bool is_attr;
    string _3AC;
    int sz = 0;
    int is_idx = 0;
    string rng_start;
    string rng_end;
    string attr_name;
    int is_assign = 0;
    bool is_class = false;
};