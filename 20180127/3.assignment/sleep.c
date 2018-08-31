#include "func.h"

void sig(int signum)
{
//	printf("%d is coming\n",signum);
}
int main()
{
	signal(SIGALRM,sig);
	alarm(3);//启动定时器，3秒后向当前进程发送信号
	pause();
	
	//while(1);
	return 0;
}
