//same program,same code

#include<cstdio>
#include<unistd.h>
#include<sys/types.h>

int main()
{
int pid;
pid=fork();
if(pid<0)
printf("Child process cannot be created");
else
printf("Process id : %d, Parent Process id : %d\n" , getpid(), getppid());
return 0;
}
