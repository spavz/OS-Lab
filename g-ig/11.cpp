#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	unordered_map<int,int> burst, burst1, turnaround, wait;
	unordered_map<int,bool> done;
	int N;

	cout<<"No of processes\n";
	cin>>N;
	cout<<"Enter burst time\n";

	for (int i = 0; i < N; ++i)
		cin >> burst[i];


	cout<<"Enter quantum\n";
	int quantum;
	cin >> quantum;


	for (int i = 0; i < 100; ++i)
	{
		int t = i%N;
		int j = 0;
		for (int i = 0; i < quantum && !done[t]; ++i)
			if(burst1[t] < burst[t])
			{
				burst1[t]++;
				v.push_back(t);
			}
			else
				done[t]=true;				
	}

	for (int i = 0; i < v.size(); ++i)
	{
		int x = v[i];
		turnaround[x] = i+1;
		wait[x]=turnaround[x] - burst[x];

	}

	cout<<"P"<<"\t"<<"burst"<<"\t"<<"wait"<<"\t"<<"turnaround"<<"\t\n";
	float avgW=0,avgT=0;
	for (int i = 0; i < N; ++i)
	{
		cout<<"P"<<i<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<turnaround[i]<<"\t"<<"\n";
		avgW+= wait[i];
		avgT+= turnaround[i];
	}

	cout << "Average waiting time: "<<avgW/N<<endl;
	cout << "Average turnaround time: "<<avgT/N<<endl;

	return 0;
}
