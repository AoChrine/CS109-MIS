//Div.cpp

#include "Div.h"
using namespace std;

Div::Div():Sub("",0,0){};

Div::Div(string para1, int para2, int para3):Sub(para1, para2, para3){}

Instruction * Div::clone(stringstream & ss)
{
    Div* div = new Div();
    div->initialize(ss);
    return div;
}

//Div operator/();


void Div::process(unordered_map<string, string>& varMap)
{
	cout<<"Div Processing"<<endl;
	param1 = Sub::param1;
	param2 = Sub::param2;
	param3 = Sub::param3;
	cout<<param1<<"<"<<param2<<"<"<<param3<<endl;
    int temp = param2/param3;
    varMap[param1]=to_string(temp);
}
Div::~Div(){}; //Destructor