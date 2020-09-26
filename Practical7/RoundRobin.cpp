#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct process
{
  int pid;
  int bt;
  int at;
  int wt;
  int turnAroundTime;
};

void WaitingTime(struct process *processes, int n, int quantum)
{
  int leftTime[n];
  for (int i = 0; i < n; i++)
    leftTime[i] = p[i].bt;
  int time = 0;
  while (1)
  {
    int done = 1;
    for (int i = 0; i < n; i++)
    {
      if (leftTime[i] > 0)
      {
        done = 0;
        if (leftTime[i] > quantum)
        {
          time += quantum;
          leftTime[i] -= quantum;
        }
        else
        {
          time += leftTime[i];
          p[i].wt = time - p[i].bt;
          leftTime[i] = 0;
        }
      }
    }
    if (done == 1)
      break;
  }
}

void TurnAroundTime(struct process *processes, int n)
{
  for (int i = 0; i < n; i++)
    p[i].turnAroundTime =p[i].bt +p[i].wt -p[i].at;
        
}

void printAverageTimes(struct process *processes, int n, int quantum)
{
  float totalwt = 0.0f;
  float totalTurnAroundTime = 0.0f;
  WaitingTime(processes, n, quantum);
  TurnAroundTime(processes, n);
  std::cout<<"Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n";
  std::cout<<"--------------------------------------------------------";
  std::cout<<"-------------------------\n";
  for (int i=0; i<n; i++)
  {
    totalwt += p[i].wt;
    totalTurnAroundTime += p[i].turnAroundTime;
    printf("%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",
           p[i].pid,
           p[i].bt,
           p[i].at,
           p[i].wt,
           p[i].turnAroundTime);
  }
  std::cout<<"\nAverage Waiting Time ="<<(float)totalwt/n;
  std::cout<<"\nAverage Turn-Around time =\n"<<(float)totalTurnAroundTime/n;
}

int main(void)
{
  int n, quantum;

  std::cout<<"Enter Time Quantum: ";
  std::cin>>quantum;

  std::cout<<"Enter Number of Processes: ";
  std::cin>>n;

  struct process processes[n];

  for (int i=0; i<n; i++)
  {
    p[i].pid=i+1;
    std::cout<<"Burst Time for Process : "<<i + 1;
    std::cin>>p[i].bt;
    std::cout<<"Arrival Time for Process : "<<i + 1;
    std::cin>>p[i].at;
  }

  std::cout<<"\n";

  printAverageTimes(processes, n, quantum);

  return 0;
}
