#include "func.h"
int main()
{
	int semid;
	semid=semget(1234,1,IPC_CREAT|0600);
	if(-1==semid)//错误返回-1
	{
		perror("semget");
		return -1;
	}
	return 0;

}
