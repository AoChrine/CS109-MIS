//Jmpgte.h
#ifndef JMPGTE_H
#define JMPGTE_H
#include "Jmpgt.h"

class Jmpgte:public Jmpgt
{
protected:
    string label;
    string param2;
    string param3;
public:
    Jmpgte();
    Jmpgte(string l, string p2, string p3);
    virtual Instruction *clone(stringstream& ss);
    virtual void process(unordered_map<string,string>&varMap, vector<Instruction*> instVec);
    virtual ~Jmpgte();
};

#endif