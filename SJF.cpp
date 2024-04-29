#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Process
{
int pid;
float arrivalTime = 0;
float burstTime = 0;
int completionTime = 0;
float waitingTime = 0;
float turnaroundTime = 0;

bool completed = false;
};

string ganttChart = "";

void Info(Process process[], int n)
{
for (int i = 0; i < n; i++)
{
process[i].pid = i + 1;
cout << "Enter Arrival time for Process " << i + 1 << ": ";
cin >> process[i].arrivalTime;

cout << "Enter Burst Time for Process " << i + 1 << ": ";
cin >> process[i].burstTime;
}
}

void printGanttChart(int currentTime, int shortest, Process p[])
{
ganttChart += "|P" + to_string(p[shortest].pid) + " ";
}

void Shortest_job(Process process[], int n)
{
float currentTime = 0;
int completedprocess = 0;

while (completedprocess < n)
{
int shortest = -1;
float shortestBurstTime = numeric_limits<float>::max();

for (int i = 0; i < n; i++)
{

if (!process[i].completed && process[i].arrivalTime <=

currentTime && process[i].burstTime < shortestBurstTime)

{
shortest = i;
shortestBurstTime = process[i].burstTime;
}
}

if (shortest == -1)
{
currentTime++;
continue;
}

process[shortest].completionTime = currentTime +

process[shortest].burstTime;

process[shortest].turnaroundTime =
process[shortest].completionTime - process[shortest].arrivalTime;

process[shortest].waitingTime =

process[shortest].turnaroundTime - process[shortest].burstTime;

process[shortest].completed = true;

printGanttChart(currentTime, shortest, process);
currentTime = process[shortest].completionTime;
completedprocess++;
}
}

void AvgWaitingTurnaround(Process process[], int n)
{
float avgWaitingTime = 0.0;
float avgTurnAroundTime = 0.0;
float sumWaitingTime = 0;
float sumTurnAroundTime = 0;
for (int i = 0; i < n; i++)
{
sumWaitingTime += process[i].waitingTime;
sumTurnAroundTime += process[i].turnaroundTime;
}
avgWaitingTime = sumWaitingTime / n;
avgTurnAroundTime = sumTurnAroundTime / n;

cout << "Average Waiting Time: " << avgWaitingTime << endl;
cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;

cout << endl;
cout << "Gantt Chart:" << endl;

cout << ganttChart << "|" << endl;
}

void display(Process process[], int n)
{
cout << endl;
cout << "Process\tArrival Time\tBurst Time\tCompletion

Time\tWaiting Time\tTurnaround Time\n";
for (int i = 0; i < n; i++)
{
cout << process[i].pid << "\t" << process[i].arrivalTime <<

"\t\t" << process[i].burstTime << "\t\t"

<< process[i].completionTime << "\t\t" <<
process[i].waitingTime << "\t\t" << process[i].turnaroundTime << endl;
}
}

int main()
{
int n;
cout << "Enter the number of process: ";
cin >> n;

Process *process = new Process[n];

Info(process, n);
Shortest_job(process, n);
display(process, n);
AvgWaitingTurnaround(process, n);

delete[] process;

return 0;
}
