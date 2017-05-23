#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector< pair<int,int> > v;
    unordered_map<int,int> priority, burst, turnaround, wait;
    int N;

    cout<<"No of processes\n";
    cin>>N;
    cout<<"Enter priority and burst times\n";

    for (int i = 0; i < N; ++i)
    {
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,i));
        burst[i]=b;
    }

    sort(v.begin(), v.end());
    cout<<"P"<<"\t"<<"prio"<<"\t"<<"burst"<<"\t"<<"wait"<<"\t"<<"turnaround"<<"\t\t\n";
    int temp = 0;
    float avgW=0,avgT=0;

    for (auto& x:v)
    {
        int i = x.second;

        priority[i] = x.first;
        temp += burst[i];
        turnaround[i] = temp;
        wait[i] = turnaround[i] - burst[i];
        cout<<"P"<<i<<"\t"<<priority[i]<<"\t"<<burst[i]<<"\t"<<wait[i]<<"\t"<<turnaround[i]<<"\t\t"<<"\n";

        avgW += wait[i];
        avgT += turnaround[i];
    }

    cout << "Average waiting time: "<<avgW/N<<endl;
    cout << "Average turnaround time: "<<avgT/N<<endl;

    return 0;
}
