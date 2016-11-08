//Jmplte.cpp

#include "Jmplte.h"

Jmplte::Jmplte():Jmpgt("","",""){}

Jmplte::Jmplte(string l, string p2, string p3):Jmpgt(l,p2,p3){}

Instruction* Jmplte::clone(stringstream& ss)
{
    Jmplte* jmplte = new Jmplte();
    jmplte->initialize(ss);
    return jmplte;
}

void Jmplte::process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*> instVec)
{
    labelName.assign(Jmpgt::labelName);
    param2.assign(Jmpgt::param2);
    param3.assign(Jmpgt::param3);
    
    if(param2.at(0)=='$') varParam2=varMap[param2].first;
    else varParam2.assign(param2);
    if(param3.at(0)=='$') varParam3=varMap[param3].first;
    else varParam3.assign(param3);
    // labelName.assign(Jmpgt::labelName);
    // param2.assign(Jmpgt::param2);
    // param3.assign(Jmpgt::param3);
    // int index = stoi(varMap[labelName].first);
    // //need to take into account constants
    // if(stoi(varMap[param2].first)<=stoi(varMap[param3].first))
    // {
    //     for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //     }
    // }
}

string Jmplte::getName()
{
    return labelName;
}

string Jmplte::getType()
{
    return "JMPLTE";
}

string Jmplte::getParam2()
{
    return varParam2;
}

string Jmplte::getParam3()
{
    return varParam3;
}

// bool Jmplte::checkJmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     param2.assign(Jmpgt::param2);
//     param3.assign(Jmpgt::param3);
//     if(param2<=param3) return true;
//     return false;
// }
Jmplte::~Jmplte(){}