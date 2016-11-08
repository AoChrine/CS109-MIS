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
    while(!ss.eof()) {  //as long as file continues
        paramVec.push_back(str);
        getline(ss, str, ',');
    }
    //push all the parsed strings to the paramVector
    paramVec.push_back(str);
}

void Out::process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec){
    ofstream out;
    out.open("MIS.out", std::ios_base::app);
    
    for(auto it = paramVec.begin(); it!= paramVec.end(); it++){
        if((*it).at(0) == '$'){
            //print out variables passed into out with their names and values
            string val = varMap[(*it)].first;
            out << *it << ": " << val << endl;
        }else{
            //print out any constants passed in
            out << *it << endl;
        }
        
    }
}

string Out::getName()
{
    return "";
}

