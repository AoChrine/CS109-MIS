//Gsc.h
#ifndef GSC_H
#define GSC_H
#include "Ssc.h"
using namespace std;

class Gsc: public Ssc
{
protected:
    string line;
    int index;
    string character;
public:
    Gsc();
    Gsc(string str, int i, string c);
    virtual Instruction* clone(stringstream& ss);
    virtual void process(unordered_map<string, string>& varMap);
    virtual ~Gsc();
};

#endif