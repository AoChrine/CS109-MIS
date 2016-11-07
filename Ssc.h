//Ssc.h
#ifndef SSC_H
#define SSC_H
#include "Sub.h"

class Ssc: public Instruction
{
protected:
    string line;
    int index;
    string character;
public:
    Ssc();
    Ssc(string str, int i, string c);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream& ss);
    virtual void process(unordered_map<string, string>& varMap);
    virtual ~Ssc();
};

#endif