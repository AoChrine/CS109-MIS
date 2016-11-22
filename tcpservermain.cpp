#include "TCPServerSocket.h"
#include "common.h"


using namespace std;


int main (int argc,char ** argv){

	TCPServerSocket testSocket((char*)"127.0.0.1",9999,1);
	testSocket.initializeSocket();
	TCPSocket* tcpsock = testSocket.getConnection(0,0,-1,-1);
	//cout << "does it get here" << endl;
	
	int maxBytes = 1024; // size of buffer
	char buffer[maxBytes]; // alocat buffer of 1 K
	memset(buffer,0,maxBytes); // initialize it.
	int bytes_read = tcpsock->readFromSocket(buffer, maxBytes); // read data from the socket
	// if returned number of bytes is bigger that zero then print information about client and themessage
	if ( bytes_read > 0 ){
		//printf ("Received Message from %s:%d\n",(char*)inet_ntoa(clientAddr.sin_addr),clientAddr.sin_port);
		vector<string> stringVec;
		char* temp;
		temp = strtok(buffer,"~");
		while(temp != NULL) {
			string tempstr(temp);
			stringVec.push_back(tempstr);
			temp = strtok(NULL,"~");

		}
		for(auto&x: stringVec) {
			cout << x << endl;
		}
	}else perror("Error Receiving Message:"); // else print error through perror.
}
