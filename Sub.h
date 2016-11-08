//file: Sub.h
#ifndef SUB_H
#define SUB_H
#include "common.h"
#include "Instruction.h"

class Sub: public Instruction
{
  protected:
    string param1;
    int param2;
    int param3;
  public:
    Sub();
    Sub(string para1, int para2, int para3);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream &ss);
    virtual void process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec);
    Sub operator-();
    virtual ~Sub();
};

#endif
