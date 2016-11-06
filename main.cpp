//main.cpp
#include "common.h"
#include <unordered_map>
#include <string>
//#include "Instruction.h"
#include "Sub.h"

using namespace std;

void parse(const string& file, unordered_map<string, string>& varMap, unordered_map<string, Instruction*>& instMap);

int main(int argc, const char* argv[] )
{
	
	Sub* testSub = new Sub();
	testSub->process();
	// unordered_map<string, string> varMap;
	// //vector<class name w/template> resultVec;
	// unordered_map<string, Instruction*> instMap;
	// //check there is file
	// if(argc > 1) {
	// 	parse(argv[1], varMap, instMap);
	// }else {
	// 	cout << "no file" << endl;
	// }

	// for(auto it = varMap.cbegin(); it != varMap.cend(); it++){
	// 	cout << it->first << ": " << it->second << endl;
	// }
	return 0;

}

/******** PARSE VAR, MAKE DATATYPE OBJECT, STORE IN VARMAP *****/

void parse(const string& file, unordered_map<string, string>& varMap, unordered_map<string, Instruction*>& instMap)
{
	//adding instructions into instruction map
	// instMap["ADD"] = new add();
	// instMap["MUL"] = new mul();
	instMap["SUB"] = new Sub();
	// instMap["DIV"] = new div();
	// instMap["ASSIGN"] = new assign();
	// instMap["OUT"] = new out();
	// instMap["SET_STR_CHAR"] = new ssc();
	// instMap["GET_STR_CHAR"] = new gsc();
	// instMap["LABEL"] = new lable();
	// instMap["JMP"] = new jmp();
	// instMap["JMPZ"] = new jmpz();
	// instMap["JMPNZ"] = new jmpnz();
	// instMap["JMPGT"] = new jmpgt();
	// instMap["JMPLT"] = new jmplt();
	// instMap["JMPGTE"] = new jmpgte();
	// instMap["JMPLTE"] = new jmplte();
	// instMap["SLEEP"] = new sleep();

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
			inst->process();
		} else cout << "Instruction not found in map" << endl;
	}
	readFile.close();
}
