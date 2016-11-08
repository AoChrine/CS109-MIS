//Jmp.h

#include "Sub.h"

class Jmp: public Instruction
{
protected:
    string labelName;
    string type;
public:
    Jmp();
    Jmp(string param1);
    virtual Instruction * clone(stringstream &ss);
    void initialize(stringstream&ss);
    virtual void process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*>& instVec);
    virtual string getName();
    //virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap);
    virtual string getType();
    virtual ~Jmp();
};