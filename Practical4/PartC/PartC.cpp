//different programs

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
execlp("/bin/ls", "ls" , NULL);

else
{
execlp("/usr/bin/free", "free" , NULL);
}
return 0;
}