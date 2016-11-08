//Jmpgt.h
#ifndef JMPGT_H
#define JMPGT_H
#include "Sub.h"

class Jmpgt:public Instruction
{
protected:
    string labelName;
    string param2;
    string varParam2;
    string varParam3;
    string param3;
    string type;
    bool param2IsVar=false;
    bool param3IsVar=false;
public:
    Jmpgt();
    Jmpgt(string l, string p2, string p3);
    virtual Instruction* clone(stringstream& ss);
    void initialize(stringstream& ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*>& instVec);
    virtual string getName();
    //virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap);
    virtual string getType();
    virtual string getParam2();
    virtual string getParam3();
    virtual ~Jmpgt();
};

#endif