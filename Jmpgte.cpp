//Jmpgte.cpp
#include "Jmpgte.h"
Jmpgte::Jmpgte():Jmpgt("","",""){}
//change constructor to be like jmpgt
Jmpgte::Jmpgte(string l, string p2, string p3):Jmpgt(l,p2,p3){}

Instruction* Jmpgte::clone(stringstream& ss)
{
    Jmpgte* jmpgte = new Jmpgte();
    jmpgte->initialize(ss);
    return jmpgte;
}

void Jmpgte::process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*> instVec)
{
    
    labelName = Jmpgt::labelName;
    cout<<labelName<<endl;
    param2 = Jmpgt::param2;
    param3 = Jmpgt::param3;
    
    cout<<param2<<":"<<param3<<":"<<endl;
    
    if(param2.at(0)=='$') varParam2.assign(varMap[param2].first);
    else varParam2.assign(param2);
    if(param3.at(0)=='$') varParam3.assign(varMap[param3].first);
    else varParam3.assign(param3);
    // labelName.assign(Jmpgt::labelName);
    // param2.assign(Jmpgt::param2);
    // param3.assign(Jmpgt::param3);
    // int index = stoi(varMap[labelName].first);
    // //need to take into account constants
    // if(stoi(varMap[param2].first)>=stoi(varMap[param3].first))
    // {
    //     for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //     }
    // }
}

string Jmpgte::getName()
{
    return labelName;
}
string Jmpgte::getType()
{
    return "JMPGTE";
}

string Jmpgte::getParam2()
{
    return varParam2;
}

string Jmpgte::getParam3()
{
    return varParam3;
}
// bool Jmpgte::checkJmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     param2.assign(Jmpgt::param2);
//     param3.assign(Jmpgt::param3);
//     if(param2>=param3) return true;
//     return false;
// }
Jmpgte::~Jmpgte(){}