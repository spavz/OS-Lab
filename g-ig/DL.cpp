#include <iostream>
#include <vector>
using namespace std;
vector<int> operator+(vector<int> v1, vector<int> v2)
{ 
	vector<int> x(v1);
	for (int i = 0; i < v1.size(); ++i)
		x[i] = v1[i] + v2[i];
	return x;
}

int main(int argc, char const *argv[])
{
	int n;
    string sequence = "";
    cout<<"Enter No. Of Processes\n";
    cin>>n;
	vector< vector<int> > max(n,vector<int>(3,0)),allocation(n,vector<int>(3,0)),need(n,vector<int>(3,0));
	vector<int> total(3,0);
	vector<bool> finish(n,false);
	cout<<"Enter Total No. Of Resouces\n";
	for (int i = 0; i < 3; ++i)
		cin >> total[i];
	vector<int> available(total);
	cout<<"Max matrix\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
				cin >> max[i][j];

	cout<<"Allocation matrix\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j)
		{
				cin >> allocation[i][j];
				need[i][j] = max[i][j] - allocation[i][j];
				available[j] -= allocation[i][j];
		}

	//cout<<endl<<total[0]<<"\t"<<total[1]<<"\t"<<total[2]<<endl;

	// for (int i = 0; i < 3; ++i)
	// 	for (int j = 0; j < n; ++j)
	// 		available[i] -= allocation[j][i];
		

	//cout<<endl<<available[0]<<"\t"<<available[1]<<"\t"<<available[2]<<endl;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(!finish[j] && need[j] < available)
			{
				cout<<endl<<available[0]<<"\t"<<available[1]<<"\t"<<available[2]<<"\t"<<need[j][0]<<"\t"<<need[j][1]<<"\t"<<need[j][2]<<endl;
				available = available + allocation[j];
				finish[j] = true;
				sequence += to_string(j) + " ";

			}
	for (int i = 0; i < n; ++i)
		if(!finish[i]){
			cout<< "Deadlock"<<endl;
			return 0;
		}

	cout<< sequence <<endl;
	return 0;
}