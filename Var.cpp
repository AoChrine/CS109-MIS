#include "Var.h"
// #include "DataType.cpp"
using namespace std;


/////////FORWARD DECLARATION PROBLEMS////////////////////////////////////////////////


Var::Var():Var("","","",""){}


Var::Var(string s_stringN, string s_stringT, string s_defaultVal, string s_size):
stringN(s_stringN), stringT(s_stringT), defaultVal(s_defaultVal), size(s_size), Instruction(){}


// creating a new Var object based on the provided string stream    
Instruction* Var::clone(stringstream& ss){
    Var* var = new Var();
    var->initialize(ss);
    return var;
}


void Var::initialize (stringstream& ss){
    string str = "";
    getline(ss, str, ',');
    stringN = str;
    getline(ss,str,',');
    stringT = str;
    getline(ss,str,',');
    defaultVal = str; //will return char(if it is char) in single quotes
    getline(ss,str,',');
    if(str.empty()) {
        defaultVal = str;
        size = "";
    } else{
        size = defaultVal;
        defaultVal = str;
    }
}


void Var::process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec){
    if(stringT == "NUMERIC") {
        d = new NUMERIC(stringN, defaultVal);
        pair<string, string>numPair (d->getName(), to_string(d->getValue()));
        varMap.insert(numPair);
        cout << "inserted numeric into orderMap" << endl;
    }
    if(stringT == "REAL"){
        d = new REAL(stringN, defaultVal); 
        pair<string, string>numPair (d->getName(), to_string(d->getValue()));
        varMap.insert(numPair); 
        cout << "inserted real into orderMap" << endl;
    }
    if(stringT == "CHAR"){
        d = new CHAR(stringN, defaultVal);
        string s(1, d->getChar());
        pair<string, string>numPair (d->getName(), s);
        varMap.insert(numPair);
        cout << "inserted char into orderMap" << endl;
    }
    if(stringT == "STRING"){
        d = new STRING(stringN, defaultVal, size);
        string s(d->getString());
        pair<string, string>numPair (d->getName(), s);
        varMap.insert(numPair);
        cout << "inserted string into orderMap" << endl;
    }
   
}

Var::~Var(){} // destructor

// int main()
// {
//     cout << "this is main" << endl;
// }