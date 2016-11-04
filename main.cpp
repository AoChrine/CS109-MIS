#include "common.h"
#include <unordered_map>
#include <string>
using namespace std;

const int MaxChar = 512;
const int MaxToken = 14;
const char* const SPACE = " ";
const char* const COMMA = ",";

void parse(const string& file, unordered_map<string, string>& varMap);

int main(int argc, const char* argv[] )
{
	unordered_map<string, string> varMap;
	//vector<class name w/template> resultVec;
	//check there is file
	if(argc > 1) {
		parse(argv[1], varMap);
	}else {
		cout << "no file" << endl;
	}

	for(auto it = varMap.cbegin(); it != varMap.cend(); it++){
		cout << it->first << ": " << it->second << endl;
	}
	return 0;

}

/******** PARSE VAR, MAKE DATATYPE OBJECT, STORE IN VARMAP *****/

void parse(const string& file, unordered_map<string, string>& varMap)
{
	//create a file-reading object
	ifstream  in;
	//open file
	in.open(file);
	//read each line of file
	while( !in.eof())
	{
		//create buffer to hold line
		char buffer[MaxChar];
		//getline
		in.getline(buffer, MaxChar);
		int n = 0;
		//buffer to store token
		//unordered_map<const char*, string>
		const char* token[MaxToken] = {};
		//parse line, first token by space
		token[0] = strtok(buffer, SPACE);
		//if line not blank, parse subsequent token by comma
		if(token[0]){
			for (n=1; n < MaxToken; n++) {
				token[n] = strtok(0, COMMA);
				//if no more token, break
				if(!token[n]) break;
			}
		}
		//print statement to check
		for(int i = 0; i < n; i++) {
			string tokenStr(token[i]);
			//cout << "Token[" << i << "]: " << token[i] << endl;
			//cout << tokenStr << endl;
			if(tokenStr.at(0) == '$') {
				/*?*******insert value as variable values *********/
				varMap.insert(make_pair(tokenStr, "0"));
			}
		}
	}
}