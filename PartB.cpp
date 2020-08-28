//same program,different code

#include<cstdio>
#include<unistd.h>
#include<sys/types.h>

int main()
{
int pid;
pid=fork();
if(pid<0)
printf("Child process cannot be created");
else if(pid>0)
printf("Parent : Forked Child\n");
else
{
printf("Child : Parent Process id: %d\n" , getppid());
printf("Child : Process id : %d\n" , getpid());
}
return 0;
}