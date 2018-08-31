#include "func.h"
int main()
{
	int shmid=shmget((key_t)1235,4096,IPC_CREAT|0600);
	printf("%d",shmid);
	//连接共享内存
	char *p=(char*)shmat(shmid,NULL,0);	
	strcpy(p,"world");
	return 0;
}
