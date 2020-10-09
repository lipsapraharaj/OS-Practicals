#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main()
{
    float a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10],p[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

     cout<<"Enter the number of Processes: ";
    cin>>n;
    cout<<"\nEnter Arrival time,Burst time and Priority of the processes\n";
    for(i=0;i<n;i++)
    {
      cout<<"\nArrival time of process "<<i+1<<": ";
      cin>>a[i];
      cout<<"\nBurst time of process "<<i+1<<": ";
      cin>>b[i];
      cout<<"\nPriority of process "<<i+1<<": ";
      cin>>p[i];
    }

   
    for(i=0; i<n; i++)
        x[i]=b[i];

    p[9]=-1;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && p[i]>p[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
     
 cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time"<<"\t"<<"turnaround-time"<<"\t"<<"completion-time"<<"\t"<<"Priority"<<endl;
    for(i=0; i<n; i++)
    {
         cout<<"P"<<i+1<<"\t\t"<<x[i]<<"\t\t\t\t"<<a[i]<<"\t\t\t\t"<<waiting[i]<<"\t\t\t\t"<<turnaround[i]<<"\t\t\t"<<completion[i]<<"\t\t\t\t\t\t\t"<<p[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
   cout<<"\n\nAverage waiting time ="<<avg/n;
   cout<<"\nAverage Turnaround time ="<<tt/n<<endl;
    return 0;
}







