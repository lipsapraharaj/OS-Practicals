#include<iostream>
#include<stdio.h>
#include<stdlib.h>
 
using namespace std;
 
int main()
{
    int at[20], bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    std::cout<<"Enter Total Number of Processes:";
    std::cin>>n;
 
    std::cout<<"\nEnter Burst Time, Arrival Time and Priority\n";
    for(i=0;i<n;i++)
    {
        std::cout<<"\nP["<<i+1<<"]\n";
        std::cout<<"Burst Time:";
        std::cin>>bt[i];
        std::cout<<"Priority:";
        std::cin>>pr[i];
        p[i]=i+1;
        std::cout<<"Arrival time :";
        std::cin>>at[i];           //contains process number
    }
   

 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    std::cout<<"\nProcess\t Priority\t    Burst Time\t Arrival Time  \tWaiting Time\t Turn Around Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        std::cout<<"\nP["<<p[i]<<"]\t\t "<<pr[i]<<"\t\t\t   "<<bt[i]<<"\t\t\t    "<<at[i]<<"\t\t\t   "<<wt[i]<<"\t\t\t    "<<tat[i];
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    std::cout<<"\n\nAverage Waiting Time="<<avg_wt;
    std::cout<<"\nAverage Turnaround Time="<<avg_tat;
 
    return 0;
}