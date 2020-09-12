#include<iostream>
#include<stdio.h>
#include<stdlib.h>
 
using namespace std;
 
int main()
{
int n,bt[20],wt[20],tat[20],i,j;
  float avwt=0,avtat=0;
    std::cout<<"Enter total number of processes(maximum 20):";
    std::cin>>n;
 
    std::cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        std::cout<<"P["<<i+1<<"]:";
        std::cin>>bt[i];
    }
 
    wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    std::cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        std::cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i];
    }
 
    avwt/=i;
    avtat/=i;
    std::cout<<"\n\nAverage Waiting Time:"<<avwt;
    std::cout<<"\nAverage Turnaround Time:"<<avtat;
 
    return 0;
}