#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)//子进程
	{
		printf("I am child,mypid=%d,myppid=%d\n",getpid(),getppid());
		while(1);
		return 0;
	}else{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
	//	sleep(10);
		while(1);
		return 0;	
	}
	//printf("you can see me\n");
}
