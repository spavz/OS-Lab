#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector< pair<int,int> > v;
	unordered_map<int,int> burst, turnaround, wait;
	int N;

	cout<<"No of processes\n";
	cin>>N;
	cout<<"Enter burst time\n";

	for (int i = 0; i < N; ++i)
	{
		int b;
		cin >> b;
		v.push_back(make_pair(b,i));
	}

	sort(v.begin(), v.end());
	cout<<"P"<<"\t"<<"burst"<<"\t"<<"wait"<<"\t"<<"turnaround"<<"\t\n";
	int temp = 0;
	float avgW=0,avgT=0;

	for (auto& x:v)
	{
		int i = x.second;

		burst[i] = x.first;
		temp += burst[i];
		turnaround[i] = temp;
		wait[i] = turnaround[i] - burst[i];
		cout<<"P"<<i<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<turnaround[i]<<"\t"<<"\n";

		avgW += wait[i];
		avgT += turnaround[i];
	}

	cout << "Average waiting time: "<<avgW/N<<endl;
	cout << "Average turnaround time: "<<avgT/N<<endl;

	return 0;
}
