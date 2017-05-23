#include <iostream>
using namespace std;

int full=0,empty=3,x=0;
bool mutex=true;

void wait(int& s)
{
	s--;
}

void wait(bool& mutex)
{
	mutex = false;
}

void signal(int& s) {s++;}

void signal(bool& mutex){mutex = true;}

void producer()
{

	wait(mutex);
	signal(full);
	wait(empty);
	x++;
	cout << "Producer produces the item "<<x;
	signal(mutex);
}

void consumer()
{
	wait(mutex);
	wait(full);
	signal(empty);
	cout << "Consumer consumes item "<<x;
	x--;
	signal(mutex);
}

int main()
{
	cout<<"1.PRODUCER\n2.CONSUMER\n";
	int n;
	while(true)
	{
		cout<<"\nENTER YOUR CHOICE\n";
		cin >> n;
		switch(n)
		{
			case 1:
				if(mutex && empty)
					producer();
				else
					cout<<"Full"<<endl;
				break;

			case 2:
				if(mutex && full)
					consumer();
				else
					cout<<"Empty"<<endl;
				break;
			default:
				return 0;
		}
	}

}

