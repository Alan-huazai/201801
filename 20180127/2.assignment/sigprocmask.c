#include "func.h"
int main()
{
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	int ret;
	ret=sigprocmask(SIG_BLOCK,&mask,NULL);//阻塞
	if(-1==ret)
	{
		perror("sigprocmask");
		return -1;
	}
	sleep(5);	
	sigset_t pend;//判断是否挂起
	sigemptyset(&pend);
	sigpending(&pend);

	if(sigismember(&pend,SIGINT))
	{
		printf("SIGINT is pending\n");
	}else{
		printf("SIGINT is not pending\n");
	}

	ret=sigprocmask(SIG_UNBLOCK,&mask,NULL);//解除阻塞
	if(-1==ret)
	{
		perror("sigprocmask");
		return -1;
	}
	return 0;
}
