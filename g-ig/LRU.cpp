#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(vector<int> v,int x)
{
	if(find(v.begin(), v.end(),x) == v.end())
		return 999;
	return find(v.begin(), v.end(),x) - v.begin();
}

int min_element(vector<int> v)
{
	return min_element(v.begin(), v.end()) - v.begin();
}

int main()
{
	int it,f=0,n;
	vector<int> frame,count;
	string ref;
	cin >> n >> ref;

	for (int i = 0; i < ref.size(); ++i)
	{
		it = find(frame,ref[i]);
		if(it == 999)
		{		
			if(count.size()==n){
				it = min_element(count);
				frame[it] = ref[i];
			} else {
				frame.push_back(ref[i]);
				count.push_back(i);			
			}
			f++;			
		}
		count[it] = i;
	}

	cout<<f<<endl;

}
