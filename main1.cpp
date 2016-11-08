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
	
	// checkMap["JMP"] = 0;
	// checkMap["JMPZ"] = 0;
	// checkMap["JMPNZ"] = 0;
	// checkMap["JMPGT"] = 0;
	// checkMap["JMPGTE"] = 0;
	// checkMap["JMPLT"] = 0;
	// checkMap["JMPLTE"] = 0;
	instMap["VAR"] = new Var();
	instMap["ADD"] = new Add();
	instMap["MUL"] = new Mul();
	 instMap["SUB"] = new Sub();
	 instMap["DIV"] = new Div();
	// instMap["ASSIGN"] = new Assign();
	// instMap["OUT"] = new Out();
	 instMap["SET_STR_CHAR"] = new Ssc();
	 instMap["GET_STR_CHAR"] = new Gsc();
	 instMap["LABEL"] = new Label();
	 instMap["JMP"] = new Jmp();
	 instMap["JMPZ"] = new Jmpz();
	 instMap["JMPNZ"] = new Jmpnz();
	 instMap["JMPGT"] = new Jmpgt();
	 instMap["JMPLT"] = new Jmplt();
	 instMap["JMPGTE"] = new Jmpgte();
	 instMap["JMPLTE"] = new Jmplte();
	//instMap["SLEEP"] = new Sleep();

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
	int index=0;
	for(auto it = instVec.begin(); it != instVec.end(); it++){
		//if instruction is jump, set it to iterator at label
		 
	}
	readFile.close();
}