// Sleep.cpp

#include "Sleep.h"

using namespace std;
  
// creating a new Sleep object based on the provided string stream    
Instruction* Sleep::clone(stringstream& ss){
    Sleep* sleep = new Sleep();
    sleep->initialize(ss);
    return sleep;
}

// parses and initializes sleep parameter
void Sleep::initialize (stringstream& ss){
    string str = "";
    getline(ss, str);
    param1.assign(str);
}

void Sleep::process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec){
    if(param1[0] == '$'){   // if parameter is a variable, get value from varMap
        //param1 = varMap[param1].first;
        varParam = varMap[param1].first;
    }else{
        varParam = param1;
    }
    //chrono::seconds dura(atoi(param1.c_str())); // creates duration to sleep for in seconds
    chrono::seconds dura(atoi(varParam.c_str())); // creates duration to sleep for in seconds
    this_thread::sleep_for(dura);               // sleeps for specified duration
    
    /*
    try {
        int n = boost::lexical_cast<int>(s);
        std::cout << "n = " << n << std::endl;
    } catch (boost::bad_lexical_cast) {
        std::cout << "conversion failed" << std::endl;
    }
    */
}

string Sleep::getName()
{
    return "";
}
