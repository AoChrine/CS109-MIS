//Label.h
#ifndef LABEL_H
#define LABEL_H 
#include "Sub.h"

class Label:public Instruction
{
protected:
    string name;
public:
    Label();
    Label(string param1);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream &ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec);
    virtual string getName();
    virtual string getType(){return "LABEL";}
    virtual ~Label();
};

#endif