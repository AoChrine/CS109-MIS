//Jmpnz.h
#ifndef JMPNZ_H
#define JMPNZ_H
#include "Jmpz.h"

class Jmpnz: public Jmpz
{
protected:
    string labelName;
    string param2;
    string varParam2;
public:
    Jmpnz();
    Jmpnz(string l, string c);
    virtual Instruction * clone(stringstream &ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec);
    virtual string getName();
    //virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap);
    virtual string getType();
    virtual string getParam2();
    virtual ~Jmpnz();    
};

#endif