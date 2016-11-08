//Jmp.cpp

#include "Jmp.h"

Jmp::Jmp():Jmp(""){}

Jmp::Jmp(string param1):name(param1), Instruction(){}

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
    name.assign(str);
}

void Jmp::process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec)
{
    int index = stoi(varMap[name]);
    for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    {
        (*it)->process(varMap,instVec);
    }
}

Jmp::~Jmp(){}