#include "TCPSocket.h"

using namespace std;

void terminate_with_error (int sock);

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

	cout << "finished" << endl;
}

// A function to print an error message and terminate
void terminate_with_error (int sock)
{
	//printf ("%s\n",error_msg); // printing error
	perror("Socket Error:"); // printing system error
	if (sock != -1) // Close socket and exit is socket opened
	{	
		close (sock);
		exit(1);
	}
}