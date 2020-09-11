#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  int x;
  std::cout<<"\nKernel Version : ";
  fflush(stdout);
  system("awk 'NR == 1 {print $3;}' /proc/version");
  std::cout<<"\nCPU Type and Model:\n";
  system("awk 'NR == 5 {$1=$2=$3=\"\\b\"; print $0;}' /proc/cpuinfo");
  return 0;
}