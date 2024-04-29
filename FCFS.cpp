#include <iostream>
#include <iomanip>
using namespace std;
struct Process
{
int burst_time;
int arrival_time;
int waiting_time;
int turnaround_time;
int completion_time;
};
void CalcCompletionTime(Process process[], int n)
{

process[0].completion_time = process[0].burst_time +

process[0].arrival_time;
for (int i = 1; i < n; i++)
{
process[i].completion_time = (max(process[i - 1].completion_time,

process[i].arrival_time) + process[i].burst_time);
}
}
void CalcWaitingTime(Process process[], int n)
{
process[0].waiting_time = 0;
for (int i = 1; i < n; i++)
{
process[i].waiting_time = max(0, process[i - 1].completion_time -

process[i].arrival_time);
}
}
void CalcTurnaroundTime(Process process[], int n)
{
for (int i = 0; i < n; i++)
{

process[i].turnaround_time = process[i].waiting_time +

process[i].burst_time;
}
}
int AvgWaiting(Process process[], int n)
{
int avg, sum;
for (int i = 0; i < n; i++)
{
sum = sum + process[i].waiting_time;
}

avg = sum / n;
return avg;
}
int AvgTurnaround(Process process[], int n)
{
int avg, sum;
for (int i = 0; i < n; i++)
{
sum = sum + process[i].turnaround_time;
}
avg = sum / n;
return avg;
}
void swap(Process *a, Process *b)
{
Process temp = *a;
*a = *b;
*b = temp;
}
void display(Process process[], int n)
{
cout<<"Process Arrival Time Burst Time Completion Time
Turnaround Time Waiting Time";
for(int i=0;i<n;i++)
{
cout<<"\n"<<i+1;
cout<<setw(15)<<process[i].arrival_time;
cout<<setw(15)<<process[i].burst_time;
cout<<setw(15)<<process[i].completion_time;
cout<<setw(25)<<process[i].turnaround_time;
cout<<setw(15)<<process[i].waiting_time;
}
}
void SortProcesses(Process a[], int n)
{
for(int i=0;i<n-1;i++)
{
for (int j=0;j<n-1-i;j++)
{
if(a[j].arrival_time>a[j+1].arrival_time)

{
swap(&a[j],&a[j+1]);
}
}
}
}
int main()
{
int n, i;
int avg_waiting_time, avg_turnaround_time;
cout << "Enter number of processes: ";
cin >> n;
Process process[n];
for (i = 0; i < n; i++)
{
cout << "Enter burst time for process " << i + 1<<": ";
cin >> process[i].burst_time;
cout << "Enter arrival time for process " << i + 1<<": ";
cin >> process[i].arrival_time;
}

SortProcesses(process, n);
CalcCompletionTime(process, n);
CalcWaitingTime(process, n);
CalcTurnaroundTime(process, n);
avg_waiting_time = AvgWaiting(process, n);
avg_turnaround_time = AvgTurnaround(process, n);
display(process, n);
cout<<"\nAverage Waiting Time: "<<avg_waiting_time;
cout<<"\nAverage Turnaround time: "<<avg_turnaround_time;
return 0;
}
