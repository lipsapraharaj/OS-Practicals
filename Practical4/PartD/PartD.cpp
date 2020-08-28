//using wait()

#include<cstdio>
#include<cstdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
int pid;
pid=fork();
if(pid<0)
printf("Child process cannot be created");
else if(pid>0)
{
  wait(NULL);
  printf("Parent : Child Exited\n");
}

else
{
printf("Child : Parent Process id: %d\n" , getppid());
printf("Child : Process id : %d\n" , getpid());
}
return 0;
}