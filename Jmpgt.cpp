//Jmpgt.cpp

#include "Jmpgt.h"

Jmpgt::Jmpgt():Jmpgt("","",""){}

Jmpgt::Jmpgt(string l,string p2, string p3):labelName(l),param2(p2),param3(p3),Instruction(){}

Instruction * Jmpgt::clone(stringstream& ss)
{
    Jmpgt * jmpgt = new Jmpgt();
    jmpgt->initialize(ss);
    return jmpgt;
}
void Jmpgt::initialize(stringstream& ss)
{
    string str="";
    getline(ss,str,',');
    labelName.assign(str);
    getline(ss,str,',');
    param2.assign(str);
    getline(ss,str,',');
    param3.assign(str);
}

void Jmpgt::process( unordered_map<string, pair<string,string>>& varMap, vector<Instruction*>& instVec)
{
    //dollar sign is gone, not updating with map value
    // if(param2.at(0)=='$' || param2IsVar) {
    //     param2=varMap[varParam2].first;
    //     param2IsVar = true;
    // }
    // cout << "param2 jmpgt: " << param2 << endl;
    // if(param3.at(0)=='$' || param3IsVar) {
    //     param3=varMap[varParam3].first;
    //     param3IsVar = true;
    // }
    
    if(param2.at(0)=='$') varParam2.assign(varMap[param2].first);
    else varParam2.assign(param2);
    if(param3.at(0)=='$') varParam3.assign(varMap[param3].first);
    else varParam3.assign(param3);
    // int index = stoi(varMap[labelName].first);
    // cout<<index<<endl;
    // int x=0,y=0;
    // if(param2.at(0)=='$') x=stoi(varMap[param2].first);
    // else x=stoi(param2);
    // if(param3.at(0)=='$') y=stoi(varMap[param3].first);
    // else y = stoi(param3);
    // //need to take into account constants
    // cout<<x<<":"<<y<<endl;
    // while(x>y)
    // {
    //     for(auto it=instVec.begin()+index+1;it!=instVec.end(); it++)
    //     {
    //         (*it)->process(varMap,instVec);
    //         //if(x>y) break;
    //     }
    //     //if(x>y) break;
    // }
}

// bool Jmpgt::checkJmp(unordered_map<string, pair<string,string>>& varMap)
// {
//     int x=0,y=0;
//     if(param2.at(0)=='$') x=stoi(varMap[param2].first);
//     else x=stoi(param2);
//     if(param3.at(0)=='$') y=stoi(varMap[param3].first);
//     else y=stoi(param3);
//     if(x>y) return true;
//     return false;
// }
string Jmpgt::getType()
{
    return "JMPGT";
}
string Jmpgt::getParam2()
{
    return varParam2;
}

string Jmpgt::getParam3()
{
    return varParam3;
}

string Jmpgt::getName(){
    return labelName;
}

Jmpgt::~Jmpgt(){}