//Jmp.cpp

#include "Jmp.h"

Jmp::Jmp():Jmp(""){}

Jmp::Jmp(string param1):labelName(param1), Instruction(){}

Instruction* Jmp::clone(stringstream& ss)
{
    Jmp *jmp = new Jmp();
    jmp->initialize(ss);
    return jmp;
}

void Jmp::initialize(stringstream& ss)
{
    string str = "";
    getline(ss,str);
    labelName.assign(str);
}

void Jmp::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec)
{
    // auto itjmp = varMap.find(name);
    // //int index = stoi(varMap[name]);
    // for(auto itjmp = instVec.begin(); itjmp!=instVec.end(); itjmp++)
    // {
    //     (*itjmp)->process(varMap,instVec);
    // }
}
//*********************************************
string Jmp::getName(){
    return labelName;
}

string Jmp::getType()
{
    return "JMP";
}

// bool Jmp::checkJmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     return true;
// }

Jmp::~Jmp(){}