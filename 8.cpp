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
    if(pid == 0)
    {
        cout << "Child process\n";
        sleep(2);
        cout << "Child exiting\n";
        cout << getpid() << " "<< getppid() << endl;
    }
    else if(pid > 0)
    {
        wait(0);
        cout << "Parent End\n";
        cout <<getpid() << " "<< pid <<endl ;
    }
    else
        cerr << "fork error\n";
    return 0;
}