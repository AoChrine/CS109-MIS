//Jmplt.cpp

#include "Jmplt.h"

Jmplt::Jmplt():Jmpgt("","",""){}

Jmplt::Jmplt(string l, string p2, string p3):Jmpgt(l,p2,p3){}

Instruction* Jmplt::clone(stringstream& ss)
{
    Jmplt* jmplt = new Jmplt();
    jmplt->initialize(ss);
    return jmplt;
}

void Jmplt::process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*> instVec)
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
    // if(stoi(varMap[param2].first)<stoi(varMap[param3].first))
    // {
    //     for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //     }
    // }
}

string Jmplt::getName(){
    return labelName;
}

string Jmplt::getType()
{
    return "JMPLT";
}

string Jmplt::getParam2()
{
    return varParam2;
}

string Jmplt::getParam3()
{
    return varParam3;
}

// bool Jmplt::checkJmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     param2.assign(Jmpgt::param2);
//     param3.assign(Jmpgt::param3);
//     if(param2>param3) return true;
//     return false;
// }

Jmplt::~Jmplt(){}