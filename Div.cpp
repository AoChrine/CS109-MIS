//Div.cpp

#include "Div.h"

Div::Div():Sub(T param1, T param2, T param3){};

void Div::initialize(stringstream & ss)
{
    string str = "";
    getline(ss,str,',');
    param2 = strof(str.c_str(),NULL);
    getline(ss,str,',');
    param3 = strof(str.c_str(),NULL);
}

Instruction * Div::clone(stringstream & ss)
{
    Div* div = new Div();
    div->initialize(ss);
    return div;
}

Div::~Div(){}; //Destructor