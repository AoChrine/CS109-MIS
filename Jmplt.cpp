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

void Jmplt::process(unordered_map<string,string>&varMap, vector<Instruction*> instVec)
{
    label.assign(Jmpgt::label);
    param2.assign(Jmpgt::param2);
    param3.assign(Jmpgt::param3);
    int index = stoi(varMap[label]);
    //need to take into account constants
    if(stoi(varMap[param2])<stoi(varMap[param3]))
    {
        for(auto it=instVec.begin()+index;it!=instVec.end(); it++)
        {
            (*it)->process(varMap,instVec);
        }
    }
}

Jmplt::~Jmplt(){}