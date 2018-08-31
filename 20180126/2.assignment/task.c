#include "func.h"

void sig(int signum)
{
	printf("%d is coming\n",signum);
}
int main()
{
	if(signal(SIGINT,sig)==SIG_ERR)
	{
		perror("signal\n");
		return -1;
	}
	while(1);
	return 0;
}
