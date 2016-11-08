//Jmpgt.cpp

#include "Jmpgt.h"

Jmpgt::Jmpgt():Jmpgt("","",""){}

Jmpgt::Jmpgt(string l,string p2, string p3):label(l),param2(p2),param3(p3),Instruction(){}

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
    label.assign(str);
    getline(ss,str,',');
    param2.assign(str);
    getline(ss,str,',');
    param3.assign(str);
}

void Jmpgt::process(unordered_map<string,string>& varMap, vector<Instruction*>& instVec)
{
    int index = stoi(varMap[label]);
    //need to take into account constants
    if(stoi(varMap[param2])>stoi(varMap[param3]))
    {
        for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
        {
            (*it)->process(varMap,instVec);
        }
    }
}

Jmpgt::~Jmpgt(){}