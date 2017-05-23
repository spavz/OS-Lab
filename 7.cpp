#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> // Declaration for exit()
using namespace std;
int c = 0;

int main()
{
	string process;
	
	pid_t pID = fork();
	int i = 0;

	if (pID == 0) 
	{	 process = "Child Process: ";
		c++;
		
	}
	else if (pID < 0) 
	{
		cerr << "Failed to fork" << endl;
		exit(1);
	}
	else {
		i++;
		process = "Parent Process:";
	}


	cout << process;
	cout << " Global variable: " << c;
	cout << " Stack variable: " << i << endl;
}