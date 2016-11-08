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
    //set label name in varMap to hold the line number in which the label instruction appeared
    varMap[name].first = to_string(instVec.size());
}

string Label::getName()
{
    return "LABEL";   
}

Label::~Label(){}