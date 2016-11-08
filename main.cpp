//main.cpp
#include "common.h"
//#include "Instruction.h"
#include "Var.h"
#include "Add.h"
#include "Mul.h"
#include "Sub.h"
#include "Div.h"
#include "Ssc.h"
#include "Gsc.h"
#include "Label.h"
#include "Sleep.h"
#include "Assign.h"
#include "Out.h"
#include "Jmp.h"
#include "Jmpz.h"
#include "Jmpnz.h"
#include "Jmpgt.h"
#include "Jmpgte.h"
#include "Jmplt.h"
#include "Jmplte.h"

// #include "DataType.cpp"

using namespace std;

void parse(const string& file, unordered_map<string, pair<string,string>>& varMap, unordered_map<string, Instruction*>& instMap, vector<Instruction*>& instVec);

int main(int argc, const char* argv[] )
{
	
	unordered_map<string, pair<string, string>> varMap;
	//vector<class name w/template> resultVec;
	unordered_map<string, Instruction*> instMap;
	vector<Instruction*> instVec;
	
	//check there is file
	if(argc > 1) {
		parse(argv[1], varMap, instMap, instVec);
	}else {
		cout << "no file" << endl;
	}

	for(auto it = varMap.cbegin(); it != varMap.cend(); it++){
		cout << it->first << ": " << it->second.first << endl;
	}

	return 0;

}

/******** PARSE VAR, MAKE DATATYPE OBJECT, STORE IN VARMAP *****/

void parse(const string& file, unordered_map<string, pair<string,string>>& varMap, unordered_map<string, Instruction*>& instMap,vector<Instruction*>& instVec)
{
	int instCount=0;
	//adding instructions into instruction map
	
	instMap["VAR"] = new Var();
	instMap["ADD"] = new Add();
	instMap["MUL"] = new Mul();
	instMap["SUB"] = new Sub();
	instMap["DIV"] = new Div();
	instMap["ASSIGN"] = new Assign();
	instMap["OUT"] = new Out();
	instMap["SET_STR_CHAR"] = new Ssc();
	instMap["GET_STR_CHAR"] = new Gsc();
	instMap["LABEL"] = new Label();
	instMap["SLEEP"] = new Sleep();
	 instMap["JMP"] = new Jmp();
	 instMap["JMPZ"] = new Jmpz();
	 instMap["JMPNZ"] = new Jmpnz();
	 instMap["JMPGT"] = new Jmpgt();
	 instMap["JMPLT"] = new Jmplt();
	 instMap["JMPGTE"] = new Jmpgte();
	 instMap["JMPLTE"] = new Jmplte();


	string line=""; //reading lines from text file
	ifstream readFile(file);
	string name = ""; //string for instruction type
	while(getline(readFile, line))
	{
		stringstream iss(line);
		getline(iss, name, ' ');
		Instruction * inst = instMap[name];
		if(inst !=NULL)
		{
			inst=inst->clone(iss);
			if(name.compare("LABEL")==0) {
				cout<<"Label"<<endl;
				inst->process(varMap, instVec);
			} 
			instVec.push_back(inst);
		} else cout << "Instruction not found in map" << endl;
	}
	auto it = instVec.begin();
	int jumpCounter = 0;
	vector<double> differenceVec;
	while(it != instVec.end()){
		if(((*it)->getType()).compare("JMP") == 0)
		{
			int itCount = stoi(varMap[(*it)->getName()].first);
			it = next(instVec.begin(), itCount);
			if(itCount < jumpCounter){
				cout << "Infinite Loop from Jump" << endl;
				break;
			}
			jumpCounter = itCount;
			(*it)->process(varMap,instVec);
			it++;
		}else if(((*it)->getType()).compare("JMPGT") == 0) {
			(*it)->process(varMap,instVec);
			float param2 = stof((*it)->getParam2());
			cout << "param2: " << param2 << endl;
			float param3 = stof((*it)->getParam3());
			if(param2 > param3) {
				differenceVec.push_back(param2-param3); 
				int itCount = stoi(varMap[(*it)->getName()].first);
				it = next(instVec.begin(), itCount);
				if(itCount < jumpCounter){
					cout << differenceVec.back() << ": " << differenceVec.front() << endl;
					if(differenceVec.size() == 2) {
						if(differenceVec.back() >= differenceVec.front()) {
							cout << "Infinite Loop from JMPGT" << endl;
							break;
						}
						differenceVec.clear();
					}
				}
				jumpCounter = itCount;
			}
			if(((*it)->getType()).compare("LABEL") != 0) {
				(*it)->process(varMap,instVec);
			}
			it++;
		}else if(((*it)->getType()).compare("JMPGT") == 0) {
			(*it)->process(varMap,instVec);
			cout<<"help"<<endl;
			float param2 = stof((*it)->getParam2());
			cout << "param2: " << param2 << endl;
			float param3 = stof((*it)->getParam3());
			if(param2 > param3) {
				differenceVec.push_back(param2-param3); 
				int itCount = stoi(varMap[(*it)->getName()].first);
				it = next(instVec.begin(), itCount);
				if(itCount < jumpCounter){
					cout << differenceVec.back() << ": " << differenceVec.front() << endl;
					if(differenceVec.size() == 2) {
						if(differenceVec.back() >= differenceVec.front()) {
							cout << "Infinite Loop from JMPGT" << endl;
							break;
						}
						differenceVec.clear();
					}
				}
				jumpCounter = itCount;
			}
			if(((*it)->getType()).compare("LABEL") != 0) {
				(*it)->process(varMap,instVec);
			}
			it++;
		}else if(((*it)->getType()).compare("JMPLT") == 0)  {
			
		}else if(((*it)->getType()).compare("JMPLTE") == 0) {
			
		}else if(((*it)->getType()).compare("JMPZ") == 0) {
			
		}else if(((*it)->getType()).compare("JMPNZ") == 0) {
			
		}else{
			if(((*it)->getType()).compare("LABEL") != 0) {
				(*it)->process(varMap,instVec);
			}
			it++;
		}
		jumpCounter++;
	}
	readFile.close();
}
