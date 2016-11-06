// Sub.cpp

#include "Sub.h"

using namespace std;

Sub::Sub():Sub(0,0,0){}

// parametized constructor initialiing data members using attribute lists and invoking parent constructor
Sub::Sub(int para1, int para2, int para3):
    param1(para1), param2(para2), param3(para3), Instruction(){}
  
// creating a new Sub object based on the provided string stream    
Instruction* Sub::clone(stringstream& ss){
    Sub * sub = new Sub();
    sub->initialize(ss);
    return sub;
}

void Sub::initialize (stringstream& ss){
    cout << "initializing" << endl;
}

void Sub::process(){
    cout << "processing" << endl;
}



Sub::~Sub(){} // destructor

