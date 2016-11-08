//Jmpz.h
#ifndef JMPZ_H
#define JMPZ_H
#include "Sub.h"

class Jmpz:public Instruction
{
protected:
    string labelName;
    string param2;
    string varParam2;
public:
    Jmpz();
    Jmpz(string l, string c);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream &ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec);
    virtual string getName();
    // virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap);
    virtual string getType();
    virtual string getParam2();
    virtual ~Jmpz();
    
};

#endif