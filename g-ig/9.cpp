#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector< pair<int,int> > v;
	unordered_map<int,int> arrival, burst, end, turnaround, wait;
	int N;

	cout<<"No of processes\n";
	cin>>N;
	cout<<"Enter arrival and burst times\n";

	for (int i = 0; i < N; ++i)
	{
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,i));
		burst[i]=b;
	}

	sort(v.begin(), v.end());
	cout<<"P"<<"\t"<<"arrival"<<"\t"<<"burst"<<"\t"<<"wait"<<"\t"<<"turnaround"<<"\t"<<"end"<<"\t\n";
	int temp = 0;
	float avgW=0,avgT=0;

	for (auto& x:v)
	{
		int i = x.second;

		arrival[i] = x.first;
		temp += burst[i];
		end[i]= temp;
		turnaround[i] = end[i] - arrival[i];
		wait[i] = turnaround[i] - burst[i];
		cout<<"P"<<i<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<turnaround[i]<<"\t"<<end[i]<<"\t"<<"\n";

		avgW += wait[i];
		avgT += turnaround[i];
	}

	cout << "Average waiting time: "<<avgW/N<<endl;
	cout << "Average turnaround time: "<<avgT/N<<endl;

	return 0;
}
