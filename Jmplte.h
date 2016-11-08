//Jmplte.h
#ifndef JMPLTE_H
#define JMPLTE_H
#include "Jmpgt.h"

class Jmplte: public Jmpgt
{
protected:
    string label;
    string param2;
    string param3;
    public:
    Jmplte();
    Jmplte(string l, string p2, string p3);
    virtual Instruction *clone(stringstream& ss);
    virtual void process(unordered_map<string,string>&varMap, vector<Instruction*> instVec);
    virtual ~Jmplte();
};

#endif
