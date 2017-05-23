#include <sys/wait.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;



int main()
{
    pid_t pid;
    cout << "Parent greeting\n";
    pid = fork();
        cout << getpid() << " "<< getppid() << endl;

    return 0;
}