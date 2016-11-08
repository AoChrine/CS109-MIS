//Div.h
#ifndef DIV_H
#define DIV_H
#include "Sub.h"

using namespace std;
//template<class T>
	
class Div:public Sub
{
protected:
  string param1;
  int param2;
  int param3;
public:
	Div();
	Div(string para1,int para2, int para3);
	virtual Instruction* clone(stringstream& ss);
  	virtual void process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec);
  	//virtual Div operator/();
	virtual ~Div();
};

#endif