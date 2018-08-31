#include "func.h"
int  main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child, mypid=%d,myppid=%d\n",getpid(),getppid());
		return 0;
	}else
	{
		printf("I am parent,pid=%d,mypid=%d\n",pid,getpid());
		int status;
		pid_t pid_recycle;
		pid_recycle=wait(&status);
		if(WIFEXITED(status))
		{
			printf("exit status=%d",WEXITSTATUS(status));;
		}else{
			printf("child process dump\n");
		}
		printf("pid_recycle=%d\n",pid_recycle);
		sleep(1);
		return 0;
	}
}
