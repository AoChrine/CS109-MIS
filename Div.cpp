//Div.cpp

#include "Div.h"
using namespace std;

Div::Div():Sub("","",""){} // calls inherited Sub constructor

Div::Div(string para1, string para2, string para3):Sub(para1, para2, para3){}

// creating a new Div object based on the provided string stream    
Instruction * Div::clone(stringstream & ss)
{
    Div* div = new Div();
    div->initialize(ss);
    return div;
}

// processing of addition functionality, using initializer from Sub and doing appropriate parsing
void Div::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVec)
{
	param1 = Sub::param1; // parameters set through Sub's initializer
	param2 = Sub::param2;
	param3 = Sub::param3;
	
	if(param2.at(0)=='$') varParam2=varMap[param2].first;
    else varParam2.assign(param2);
    if(param3.at(0)=='$') varParam3=varMap[param3].first;
    else varParam3.assign(param3);
	
	double temp = stof(varParam2)/stof(varParam3); // division of two parameters
    varMap[param1].first=to_string(temp);    // pushes newly assigned variable back to varMap
}

string Div::getName(){return "";}


Div::~Div(){}; //Destructor