//Jmp.h

#include "Sub.h"

class Jmp: public Instruction
{
protected:
    string name;
public:
    Jmp();
    Jmp(string param1);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream&ss);
    virtual void process(unordered_map<string,string>& varMap, vector<Instruction*>& instVec);
    virtual ~Jmp();
};