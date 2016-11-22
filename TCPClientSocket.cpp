#include "TCPSocket.h"

using namespace std;

int main (int argc,char ** argv)
{

	if ( argc != 3) { // Check on the number of arguments and exit if incorrect
		printf ("Usage: ./client <server-address> <file> \n");
	}	

	TCPSocket client((char*)"127.0.0.1",9999,-1,-1);

	vector<string> stringVec;

	//make function to return constant void pointer to send over socket
	ifstream readFile(argv[2]);
	string name = "";
	string line = "";
	while(getline(readFile,line))
	{
		stringVec.push_back(line);
	}


	string passstr = stringVec.at(0);
	for(auto it = stringVec.begin()+1; it != stringVec.end(); it++){
		passstr += '~'+(*it);
	}
	const void* mystr = passstr.c_str();
	if ( argc != 3) { // Check on the number of arguments and exit if incorrect
		printf ("Usage: ./client <server-address> <file> \n");
		exit(1);
	}
	
	send(client.getSocket(),mystr,passstr.size(),0);
	//client.writeToSocket((char *)"fuck karim", 100); // Send a message to the server.
		//close(sock);// Close the socket.

	vector<string> outVec;
	vector<string> errVec;

	char* tempOut;
	char* tempErr;
	int maxBytes = 1000000; // size of buffer
	char buffer[maxBytes]; // alocat buffer of 1 K
	memset(buffer,0,maxBytes); // initialize it.
	int bytes_read = client.readFromSocket(buffer, maxBytes); // read data from the socket
	cout << buffer << endl;
	// if returned number of bytes is bigger that zero then print information about client and themessage
	if ( bytes_read > 0 ){
		//printf ("Received Message from %s:%d\n",(char*)inet_ntoa(clientAddr.sin_addr),clientAddr.sin_port);
		char* temp;
		// cout << buffer << endl;
		temp = strtok(buffer,"@");
		bool isOut = true;
		cout << "before the while loop" << endl;

		////////////////////////////////////// PARSING ERROR, MAXBYTE SIZE ERROR /////////////////////////////////////////

		while(temp != NULL) {
			if(isOut) {
				cout << "in isOut loop" << endl;
				char* temp2;
				temp2 = strtok(temp,"~");
				while(temp2 != NULL) {
					string tempstr(temp2);
					outVec.push_back(tempstr);
					cout << tempstr << endl;
					temp2 = strtok(NULL,"~");
				}
				isOut = false;
			}else{
				cout << "in NOTISOUT loop" << endl;
				char* temp2;
				temp2 = strtok(temp,"~");
				while(temp2 != NULL) {
					string tempstr(temp2);
					cout << "TEMP STR IN ERR IS: " << tempstr << endl;
					errVec.push_back(tempstr);
					temp2 = strtok(NULL,"~");
				}
				temp = strtok(NULL,"|");
			}
			//temp = strtok(NULL,"|");
		 	if(temp == NULL) cout << "TEMP is null " << endl;
			cout << "moving onto parsing err" << endl;
		}	
	}else perror("Error Receiving Message:"); // else print error through perror.


	ofstream out;
	out.open("MISclient.out", std::ios_base::app);

	for(auto&x: outVec) {
		out << x << endl;
	}

	ofstream err;
	err.open("MISclient.err", std::ios_base::app);


	for(auto&x: errVec) {
		err << x << endl;
	}

	cout << "finished" << endl;
}

