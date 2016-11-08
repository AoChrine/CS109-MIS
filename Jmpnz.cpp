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

void Jmpnz::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec)
{
    if(param2.at(0)=='$') varParam2=varMap[param2].first;
    else varParam2=param2;
    // labelName = Jmpz::labelName;
    // param2 = Jmpz::param2;
    // int index = stoi(varMap[labelName].first);
    // int z = stoi(varMap[param2].first);
    // if(z!=0)
    // {
    //     for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //     }
    // }
}

string Jmpnz::getName()
{
    return labelName;
}

string Jmpnz::getType()
{
    return "JMPNZ";
}

string Jmpnz::getParam2()
{
    return param2;
}

// bool Jmpnz::param2Jmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     param2 = Jmpz::param2;
//     int z= stoi(varMap[param2].first);
//     if(z!=0) return true;
//     return false;
// }

Jmpnz::~Jmpnz(){}