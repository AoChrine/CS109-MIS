//Jmpnz.h
#ifndef JMPNZ_H
#define JMPNZ_H
#include "Jmpz.h"

class Jmpnz: public Jmpz
{
protected:
    string label;
    string check;
public:
    Jmpnz();
    Jmpnz(string l, string c);
    virtual Instruction * clone(stringstream &ss);
    virtual void process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec);
    virtual ~Jmpnz();    
};

#endif