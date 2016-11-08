//Jmplt.h
#ifndef JMPLT_H
#define JMPLT_H
#include "Jmpgt.h"

class Jmplt:public Jmpgt
{
protected:
    string label;
    string param2;
    string param3;
public:
    Jmplt();
    Jmplt(string l, string p2, string p3);
    virtual Instruction *clone(stringstream& ss);
    virtual void process(unordered_map<string,string>&varMap, vector<Instruction*> instVec);
    virtual ~Jmplt();
};

#endif