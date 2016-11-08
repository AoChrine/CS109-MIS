//Jmpgt.h
#ifndef JMPGT_H
#define JMPGT_H
#include "Sub.h"

class Jmpgt:public Instruction
{
protected:
    string label;
    string param2;
    string param3;
public:
    Jmpgt();
    Jmpgt(string l, string p2, string p3);
    virtual Instruction* clone(stringstream& ss);
    void initialize(stringstream& ss);
    virtual void process(unordered_map<string,string>& varMap, vector<Instruction*>& instVec);
    virtual ~Jmpgt();
};

#endif