//Jmpnz.cpp

#include "Jmpnz.h"

Jmpnz::Jmpnz():Jmpz("",""){}

Jmpnz::Jmpnz(string l, string c):Jmpz(l,c){}

Instruction * Jmpnz::clone(stringstream &ss)
{
    Jmpnz* jmpnz = new Jmpnz();
    jmpnz->initialize(ss);
    return jmpnz;
}

void Jmpnz::process(unordered_map<string,string>& varMap,vector<Instruction*>& instVec)
{
    label = Jmpz::label;
    check = Jmpz::check;
    int index = stoi(varMap[label]);
    int z = stoi(varMap[check]);
    if(z!=0)
    {
        for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
        {
            (*it)->process(varMap,instVec);
        }
    }
}

Jmpnz::~Jmpnz(){}