//Ssc.cpp

#include "Ssc.h"

Ssc::Ssc():Ssc("",0,""){}

Ssc::Ssc(string str, int i, string c): 
    line(str), index(i), character(c), Instruction(){}
    
void Ssc::initialize(stringstream& ss)
{
    string s= "";
    getline(ss,s,',');
    line.assign(s);
    cout<<line<<endl;
    getline(ss,s, ',');
    index = strtof(s.c_str(),NULL);
    cout<<index<<endl;
    getline(ss,s, ',');
    character.assign(s);
    cout<<character<<endl;
}

void Ssc::process(unordered_map<string, string>& varMap)
{
    if(varMap.count(line)==1)
    {
        string temp="";
        temp.assign(varMap[line]);
        cout<<temp<<endl;
        temp[index] = character[1];
        varMap[line] = temp;
    } else {cout<<"key doesn't exist"<<endl;}
        cout<<"processing"<<endl;
}

Instruction * Ssc::clone(stringstream & ss)
{
    Ssc* ssc= new Ssc();
    ssc->initialize(ss);
    return ssc;
}

Ssc::~Ssc(){}
