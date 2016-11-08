//Jmpz.cpp
#include "Jmpz.h"

Jmpz::Jmpz():Jmpz("",""){}

Jmpz::Jmpz(string l, string c):label(l),check(c),Instruction(){}

Instruction* Jmpz::clone(stringstream &ss)
{
    Jmpz* jmpz = new Jmpz();
    jmpz->initialize(ss);
    return jmpz;
}

void Jmpz::initialize(stringstream &ss)
{
    string str = "";
    getline(ss,str,',');
    label.assign(str);
    getline(ss,str,',');
    //need to take into account constants
    check.assign(str);
}

void Jmpz::process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec)
{
    int index = stoi(varMap[label]);
    int z = stoi(varMap[check]);
    if(z==0)
    {
        for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
        {
            (*it)->process(varMap,instVec);
        }
    }
}

Jmpz::~Jmpz(){}