//Jmp.cpp

#include "Jmp.h"

Jmp::Jmp():Jmp(""){}

Jmp::Jmp(string param1):labelName(param1), Instruction(){}

Instruction* Jmp::clone(stringstream& ss)
{
    Jmp *jmp = new Jmp();
    jmp->initialize(ss);
    return jmp; //clone and return the new jmp object
}

void Jmp::initialize(stringstream& ss)
{
    string str = "";
    getline(ss,str);
    labelName.assign(str); //set labelName for jump
}

void Jmp::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec){}

string Jmp::getName(){
    return labelName; //return labelName
}

string Jmp::getType()
{
    return "JMP";
}

Jmp::~Jmp(){}