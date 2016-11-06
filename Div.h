//Div.h

#include "Div.h"
class Instruction
class Sub
using namespace std;
template<class T>

class Div:public Sub
{
protected:
  T * param1;
  T * param2;
  T * param3;
public:
	Div():Sub(T * param1, T * param2, T * param3);
	virtual Intruction* clone(stringstream& ss);
	virtual void initialize(stringstream& ss);
  	virtual void process();
  	virtual Div operator/();
	virtual ~div();
}

