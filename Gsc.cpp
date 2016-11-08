//Gsc.cpp

#include "Gsc.h"

Gsc::Gsc():Ssc("",0,""){};

Gsc::Gsc(string str, int i, string c):Ssc(str, i, c){}

void Gsc::process(unordered_map<string, pair<string,string>>& varMap,vector<Instruction*>& instVecc)
{
    
	line = Ssc::line;
	index=Ssc::index;
	character=Ssc::character;

    if(varMap.count(line)==1)
    {
        string temp="";
        temp.assign(varMap[line].first);
        string a(1, temp[index]);
        //cout<<a<<endl;
        varMap[character].first.assign(a);
    } else {cout<<"key doesn't exist"<<endl;}
}

Instruction * Gsc::clone(stringstream& ss)
{
    Gsc* gsc = new Gsc();
    gsc->initialize(ss);
    return gsc;
}

string Gsc::getName()
{
    return "";
}

Gsc::~Gsc(){}