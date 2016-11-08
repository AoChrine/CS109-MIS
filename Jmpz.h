//Jmpz.h
#ifndef JMPZ_H
#define JMPZ_H
#include "Sub.h"

class Jmpz:public Instruction
{
protected:
    string label;
    string check;
public:
    Jmpz();
    Jmpz(string l, string c);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream &ss);
    virtual void process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec);
    virtual ~Jmpz();
    
};

#endif