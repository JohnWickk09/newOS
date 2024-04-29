#include <iostream>
using namespace std;
int main() {
int n;
cout<<"Enter no. of processes:";
cin>>n;
int processes[n];
for(int i=0;i<n;i++)
{
processes[i]=i;
}
int r;
cout<<"Enter no. of resources:";
cin>>r;
int max[n][r];
for(int i=0;i<n;i++)
{
cout<<"Enter the max no. of resouces for process "<<i<<":";
for(int j=0;j<r;j++)
{
cin>>max[i][j];
}
}

int alloc[n][r];
for(int i=0;i<n;i++)
{
cout<<"Enter the no. of resources allocated for process "<<i<<":";
for(int j=0;j<r;j++)
{
cin>>alloc[i][j];
}
}
int need[n][r];
for(int i=0;i<n;i++)
{
for(int j=0;j<r;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}

int avail[r];
cout<<"Enter the available resources:";
for(int i=0;i<r;i++)
{
cin>>avail[i];
}
/*int max[5][3]={{5,2,1},
{3,2,2},
{3,2,2},
{7,3,1},
{5,0,3}};
int need[5][3]={{2,2,0},
{3,0,1},
{1,2,2},
{5,2,1},
{1,0,1}};
int avail[3]={1,6,2};*/
bool finish[n];
for(int i=0;i<n;i++)
{
finish[i]=0;
}
int SafeSeq[n]={};
int count=0;
for(int k=0;k<n;k++)
{

for(int i=0;i<n;i++)
{
if (finish[i]==0){
int j=0;
int flag=1;
while(j<r){
if(need[i][j]<=avail[j])
{
//cout<<a[i][j];
j++;
flag=0;
}
else
{
flag=1;
break;
}
}
if(flag==0)
{
finish[i]=1;
SafeSeq[count++]=i;
for(int j=0;j<r;j++)
{
avail[j]=avail[j]-need[i][j];
avail[j]=avail[j]+max[i][j];
}
}
}}}
int flag1=0;
for(int i=0;i<n;i++)
{
if(finish[i]==1)
{
flag1=1;
}
}
if(flag1==1)
{
cout<<"It is a Safe Sequence"<<endl;
for(int i=0;i<count;i++)
{
cout<<SafeSeq[i]<<",";
}
}
else
{
cout<<"Sequence is not safe"<<endl;
}
return 0;
}
