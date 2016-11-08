// Sub.cpp

#include "Sub.h"

using namespace std;

Sub::Sub():Sub("",0,0){}

// parametized constructor initialiing data members using attribute lists and invoking parent constructor
Sub::Sub(string para1, int para2, int para3):
    param1(para1), param2(para2), param3(para3), Instruction(){}
  
// creating a new Sub object based on the provided string stream    
Instruction* Sub::clone(stringstream& ss){
    Sub * sub = new Sub();
    sub->initialize(ss);
    return sub;
}

void Sub::initialize (stringstream& ss){
    string str = "";
    getline(ss, str, ',');
    param1.assign(str);
    getline(ss,str,',');
    if(ss.str().at(0)!='$')
    {
        param2=strtof(str.c_str(),NULL);
    } else {cout<<str.c_str()<<endl;}
    getline(ss,str,',');
    if(ss.str().at(0)!='$')
    {
        param3=strtof(str.c_str(),NULL);
    } else {cout<<endl;}

}

//Sub operator-();

void Sub::process(unordered_map<string, string>& varMap,vector<Instruction*>& instVec){
    int temp=param3-param2;
    varMap[param1]=to_string(temp);
}



Sub::~Sub(){} // destructor

