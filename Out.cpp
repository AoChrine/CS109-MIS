//Out.cpp
#include "Out.h"

using namespace std;
  
// creating a new Sub object based on the provided string stream    
Instruction* Out::clone(stringstream& ss){
    Out* out = new Out();
    out->initialize(ss);
    return out;
}

void Out::initialize (stringstream& ss){
    string str = "";
    getline(ss, str, ',');
    while(!ss.eof()) {
        paramVec.push_back(str);
        cout << "pushed in: " << str << endl;
        getline(ss, str, ',');
        cout << "initializing add with str: " << str << endl;
    }
    paramVec.push_back(str);
}

void Out::process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec){
    
    for(auto it = paramVec.begin(); it!= paramVec.end(); it++){
        if((*it).at(0) == '$'){
            
            string val = varMap[(*it)].first;
            cout << *it << ": " << val << endl;
        }else{
            cout << *it << endl;
        }
        
    }
}

string Out::getName()
{
    return "";
}

