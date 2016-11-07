#include "Var.h"
using namespace std;

Var::Var():Var("", "","",""){}

Var::Var(string s_stringN, string s_stringT, string s_defaultVal, string s_size):
stringN(s_stringN), stringT(s_stringT), defaultVal(s_defaultVal), size(s_size), Instruction(){}

// creating a new Var object based on the provided string stream    
Instruction* Var::clone(stringstream& ss){
    Var * var = new Var();
    var->initialize(ss);
    return var;
}

void Var::initialize (stringstream& ss){
    string str = "";
    getline(ss, str, ',');
    stringN = strtof(str.c_str(), NULL);
    getline(ss,str,',');
    stringT = strtof(str.c_str(), NULL);
    if(stringT = "CHAR") {
        getline(ss,str,',');
        defaultVal = str;
    
    cout << param1 << param2 << param3 << endl;
}
