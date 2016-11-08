// Assign.cpp

#include "Assign.h"

using namespace std;
  
// creating a new Assign object based on the provided string stream    
Instruction* Assign::clone(stringstream& ss){
    Assign* assign = new Assign();
    assign->initialize(ss);
    return assign;
}

// parses and initializes variables in Assign 
void Assign::initialize (stringstream& ss){
    string str = "";
    getline(ss, str, ',');
    param1.assign(str);             // sets parameter to change
    getline(ss, str, ',');
    param2.assign(str);             // sets what to change parameter to
}

void Assign::process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec){
    if(param2[0] == '$'){           // if parameter is a variable, get value from map
        varMap[param1].first = varMap[param2].first;    // set param2 to param1
    }else{
        varMap[param1].first = param2;
    }
}

string Assign::getName()
{
    return "Assign";
}
