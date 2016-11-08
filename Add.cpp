// Add.cpp

#include "Add.h"

using namespace std;
  
// creating a new Add object based on the provided string stream    
Instruction* Add::clone(stringstream& ss){
    Add* add = new Add();
    add->initialize(ss);
    return add;
}

// parses and initializes variables in Add 
void Add::initialize (stringstream& ss){
    int counter = 1;
    string str = "";
    getline(ss, str, ',');
    param1.assign(str);                                 // initializes variable to store sum
    getline(ss, str, ',');
    while(!ss.eof()) {                                  // creates vector with up to 13 parameters
        if(counter >= 13){
            break;
        }
        paramVec.push_back(str);
        cout << "pushed in: " << str << endl;
        getline(ss, str, ',');
        cout << "initializing add with str: " << str << endl;
        counter++;
    }
    paramVec.push_back(str);
}

// processing of addition functionality
void Add::process(unordered_map<string, pair<string, string>>& varMap,vector<Instruction*>& instVec){
    double sum = 0;
    for(auto it = paramVec.begin(); it!= paramVec.end(); it++){     // iterates through each parameter
        if((*it).at(0) == '$'){                                     // if parameter is variable, get value from map
           //*it = varMap[(*it)].first;
           varParam = varMap[(*it)].first;
        }else{
            varParam = *it;
        }
        //sum += stod((*it));                                         // add to sum
        sum += stod(varParam);
    }
    
    if(varMap[param1].second == "NUMERIC") {                        // cast as 8 bit int if storage variable is NUMERIC
        varMap[param1].first=to_string((int64_t)sum);
    }else{
         varMap[param1].first=to_string(sum);
    }

}

string Add::getName()
{
    return "";
}

