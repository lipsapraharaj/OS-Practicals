#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  int a;
  std::cout<<"Kernel Version :\n";
  fflush(stdout);
  system("awk 'NR == 1 {print $3;}' /proc/version");
  std::cout<<"Information on Configured amount of Free and Used Memory\n";
  fflush(stdout);
  system("cat /proc/meminfo | awk 'NR==1,NR==2 {print}'");
  return 0;
  
}
