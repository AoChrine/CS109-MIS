//file: Sub.h
#ifndef SUB_H
#define SUB_H
#include "common.h"
#include "Instruction.h"

// template <class T>
class Sub: public Instruction
{
  protected:
    int param1;
    int param2;
    int param3;
  public:
    Sub();
    Sub(int para1, int para2, int para3);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream &ss);
    virtual void process();
    Sub operator-();
    virtual ~Sub();
};

#endif
