//Label.cpp

#include "Label.h"

Label::Label():Label(""){}

Label::Label(string param1):name(param1), Instruction(){}

Instruction* Label::clone(stringstream & ss)
{
    Label * label = new Label();
    label->initialize(ss);
    return label;
}

void Label::initialize(stringstream& ss)
{
    string str ="";
    getline(ss, str);
    name.assign(str);
}

void Label::process(unordered_map<string, pair<string,string>>& varMap, vector<Instruction*>& instVec)
{
    //plan: put label name in variable list, value being the next number instruction. when 
    //jumping, look up variable name in varMap. look up value in varMap in orderMap, iterate
    
    //cout<<"LProcessing"<<instVec.size()<<endl;
    varMap[name].first = to_string(instVec.size());
}

string Label::getName()
{
    return "LABEL";   
}

Label::~Label(){}