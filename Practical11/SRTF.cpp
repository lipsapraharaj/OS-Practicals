#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main()
{
    float a[10];
    int b[10],x[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"\nEnter the number of Processes: ";  //input
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process "<<i+1<<" : ";  //input
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter burst time of process "<<i+1<<" : ";  //input
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"\n\nProcess"<<"\t\t"<< "Burst-time"<<"\t"<<"Arrival time" <<"\t"<<"Waiting time" <<"\t"<<"Turnaround-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t\t\t"<<x[i]<<"\t\t\t\t"<<a[i]<<"\t\t\t\t"<<waiting[i]<<"\t\t\t\t"<<turnaround[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  \nAverage Turnaround time ="<<tt/n<<endl;
    return 0;
}
