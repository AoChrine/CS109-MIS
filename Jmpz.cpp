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
    if(param2.at(0)=='$') varParam2=varMap[param2].first;
    else varParam2=param2;
    // int index = stoi(varMap[labelName].first);
    // int z = stoi(varMap[param2].first);
    // if(z==0)
    // {
    //     for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //     }
    // }
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
    return param2;
}

// bool Jmpz::param2Jmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     if(stoi(varMap[param2].first)==0) return true;
//     return false;
// }



Jmpz::~Jmpz(){}