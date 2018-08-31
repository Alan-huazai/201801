#include "func.h"
int main()
{
	int semid;
	semid=semget(1234,1,IPC_CREAT|0600);//创建一个信号量
	if(-1==semid)//判断创建是否成功
	{
		perror("semid\n");
		return -1;
	}
	return 0;
}
