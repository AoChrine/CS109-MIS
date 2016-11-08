//Jmplte.h
#ifndef JMPLTE_H
#define JMPLTE_H
#include "Jmpgt.h"

class Jmplte: public Jmpgt
{
protected:
    string labelName;
    string param2;
    string param3;
    string varParam2;
    string varParam3;
public:
    Jmplte();
    Jmplte(string l, string p2, string p3);
    virtual Instruction *clone(stringstream& ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*> instVec);
    virtual string getName();
    //virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap);
    virtual string getType();
    virtual string getParam2();
    virtual string getParam3();
    virtual ~Jmplte();
};

#endif
