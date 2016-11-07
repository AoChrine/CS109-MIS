//Instruction.h
#include "common.h"
using namespace std;

class Instruction
{
protected:
public:
  Instruction();
  virtual Instruction* clone(stringstream& ss) = 0;
  virtual void initialize(stringstream& ss) = 0;
  virtual void process(unordered_map<string, string>& varMap) = 0;
  virtual ~Instruction();
};
