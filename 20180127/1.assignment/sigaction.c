#include "func.h"
void sig(int signum,siginfo_t *p,void *p1)//函数指针
{
	printf("before %d is coming\n",signum);
	sleep(3);
	sigset_t pend;//设定将要被阻塞的信号
	sigemptyset(&pend);//清空信号
	sigpending(&pend);//挂起信号
	if(sigismember(&pend,SIGQUIT))
	{
		printf("SIGQUIT is pending\n");
	}else{
		printf("SIGQUIT is not pending\n");
	}
	printf("after %d is coming\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sig;//将函数指针赋值
	act.sa_flags=SA_SIGINFO;
	sigemptyset(&act.sa_mask);//清空信号集合
	sigaddset(&act.sa_mask,SIGQUIT);
	int ret;
	ret=sigaction(SIGINT,&act,NULL);//捕获2号信号
	if(-1==ret)
	{
		perror("sigaction\n");
		return -1;
	}
	ret=sigaction(SIGQUIT,&act,NULL);//捕获2号信号
	if(-1==ret)
	{
		perror("sigaction\n");
		return -1;
	}
	while(1);
	return 0;

}
