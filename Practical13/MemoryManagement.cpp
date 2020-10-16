#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int main()

{

  int c,i,j,k,n,l,m[10],p[10],po[20],flag,z,y,temp,temp1;

      std::cout<<"Enter No. Of Memory Partitions: ";

      std::cin>>n;

      std::cout<<"\nEnter Memory Size For\n";

      for(i=1;i<=n;i++)

      {

        std::cout<<"\nPartition "<<i<<" :\t";

        std::cin>>m[i];

        po[i]=i;       

      }

      std::cout<<"\nEnter no. of processes: ";

      std::cin>>j;

      std::cout<<"\nEnter Memory Size for\n";

      for(i=1;i<=j;i++)

      {

      std::cout<<"\nProcess "<<i<<" :\t";

        std::cin>>p[i];                 

      }        

      std::cout<<"\n******** MENU DRIVEN PROGRAM OF MEMORY MANAGEMENT**********\n1.FIRST-FIT\n2.BEST-FIT\n3.WORST-FIT\n4.QUIT\nEnter your choice: ";

      std::cin>>c;

      switch(c)

      {

      case 1:

            for(i=1;i<=j;i++)

      {

          flag=1;

          for(k=1;k<=n;k++)

      {

          if(p[i]<=m[k])

          {

             std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB has been  allocated at memory partition: "<<po[k]<<" that is of  "<<m[k]<<"KB";

             m[k]=m[k]-p[i];

             break;           

          }

          else

         {

            flag++;  

          }


      }   

      if(flag>n)

      {

         std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       

      }           

      }


      break;


      case 2:


       for(y=1;y<=n;y++)

          {

          for(z=y;z<=n;z++)

          {

          if(m[y]>m[z])

          {

          temp=m[y];

          m[y]=m[z];

          m[z]=temp;

          temp1=po[y]; 

          po[y]=po[z];

          po[z]=temp1;            

          }                 

          }             

          }

          for(i=1;i<=j;i++)

      {

          flag=1;

          for(k=1;k<=n;k++)

      {

          if(p[i]<=m[k])

          {

             std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB has been allocated at memory partition: "<<po[k]<<" that is of  "<<m[k]<<"KB";;

             m[k]=m[k]-p[i];

             break;           

          }

          else

         {

            flag++;  

          }


      }   

      if(flag>n)

      {

         std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       

      }           

      }


          break;


          case 3:

          for(y=1;y<=n;y++)

          {

          for(z=y;z<=n;z++)

          {

          if(m[y]<m[z])

          {

          temp=m[y];

          m[y]=m[z];

          m[z]=temp;

          temp1=po[y]; 

          po[y]=po[z];

          po[z]=temp1;            

          }                 

          }             

          }

          for(i=1;i<=j;i++)

      {

          flag=1;

          for(k=1;k<=n;k++)

      {

          if(p[i]<=m[k])

          {

             std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB has been allocated at memory partition: "<<po[k]<<" that is of  "<<m[k]<<"KB";;

             m[k]=m[k]-p[i];

             break;           

          }

          else

         {

            flag++;  

          }

      }   

      if(flag>n)

      {

         std::cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";       

      }           

      }

          break;

          }  


      return 0;

}