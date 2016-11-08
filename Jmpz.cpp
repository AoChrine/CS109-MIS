//Jmpz.cpp
#include "Jmpz.h"

Jmpz::Jmpz():Jmpz("",""){}

Jmpz::Jmpz(string l, string c):labelName(l),param2(c),Instruction(){}

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
    labelName.assign(str);
    getline(ss,str,',');
    //need to take into account constants
    param2.assign(str);
}

void Jmpz::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec)
{
    //update val from map if param is variable
    if(param2.at(0)=='$') varParam2=varMap[param2].first;
    //else set param to const
    else varParam2=param2;
}

string Jmpz::getName()
{
    return labelName;
}

string Jmpz::getType()
{
    return "JMPZ";
}

string Jmpz::getParam2()
{
    return varParam2;
}

// bool Jmpz::param2Jmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     if(stoi(varMap[param2].first)==0) return true;
//     return false;
// }



Jmpz::~Jmpz(){}