//Instruction.h
//#pragma once

#include "common.h"
using namespace std;

class Instruction
{
protected:
public:
  Instruction(); // constructor
  virtual Instruction* clone(stringstream& ss) = 0; // pure virtual clone to be inherited by all children
  virtual void initialize(stringstream& ss) = 0;    // pure virtual intialize to be inherited by all children
  virtual void process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec) = 0; // pure virtual process to be inherited by all children
  virtual string getName()=0;
  virtual string getType()=0;
  virtual string getParam2(){"";}
  virtual string getParam3(){"";}
  //virtual bool checkJmp(unordered_map<string, pair<string,string>>& varMap){}
  virtual ~Instruction(); // desctructor
};
