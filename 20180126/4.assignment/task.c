#include "func.h"


void sig(int signum,siginfo_t *p,void *p1)
{
	printf("before sleep %d is coming\n",signum);
	sleep(3);
	printf("after sleep %d is coming\n",signum);
}
int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=sig;
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
	int ret;
	ret=sigaction(SIGINT,&act,NULL);
	sigaction(SIGQUIT,&act,NULL);
	while(1);
	return 0;
}

