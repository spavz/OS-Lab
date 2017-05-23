#include<iostream>
#include<string>
using namespace std;
struct process
{
    int max[3];
    int allocated[3];
    int need[3];
    string name;
    bool isProcessed;
};
int main()
{
    int n,total[3],available[3];
    string sequence = "";
    cout<<"Enter No. Of Processes\n";
    cin>>n;
    struct process *p = new struct process[n];
    cout<<"Enter Total No. Of Resouces\n";
    cin>>total[0]>>total[1]>>total[2];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Process Name :\n";
        cin>>p[i].name;
        cout<<"Enter Maximum Resources for "<<p[i].name<<" : "<<endl;
        cin>>p[i].max[0]>>p[i].max[1]>>p[i].max[2];
        cout<<"Enter Allocated Resources for "<<p[i].name<<" : "<<endl;
        cin>>p[i].allocated[0]>>p[i].allocated[1]>>p[i].allocated[2];
        p[i].need[0]=p[i].max[0]-p[i].allocated[0];
        p[i].need[1]=p[i].max[1]-p[i].allocated[1];
        p[i].need[2]=p[i].max[2]-p[i].allocated[2];
        p[i].isProcessed=false;
    }
    available[0]=total[0];
    available[1]=total[1];
    available[2]=total[2];
    for(int i=0;i<n;i++)
    {
        available[0]-=p[i].allocated[0];
        available[1]-=p[i].allocated[1];
        available[2]-=p[i].allocated[2];
    }
    int i=0;
    bool flag=false;
    while(i<n)
    {
        int select=-1;
        for(int j=0;j<n;j++)
        {
            if(p[j].need[0]<=available[0]&&p[j].need[1]<=available[1]&&p[j].need[2]<=available[2] && !p[j].isProcessed)
            {
                select=j;
                flag=true;
                break;
            }
        }
        if(flag)
        {
            flag=false;
            p[select].isProcessed=true;
            sequence.append(p[select].name);
            sequence.append(" , ");
            available[0]+=p[select].allocated[0];
            available[1]+=p[select].allocated[1];
            available[2]+=p[select].allocated[2];
            i++;
        }
        else
        {
            cout<<"No Safe Sequence Obtained\n";
            return 0;
        }
    }
    cout<<"Safe Sequence : "<<sequence<<endl;
}
