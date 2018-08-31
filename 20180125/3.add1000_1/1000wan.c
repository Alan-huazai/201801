#include "func.h"
#define N 10000000

int main(int argc,char*argv[])
{
	int shmid;
	shmid=shmget((key_t)1234,4096,IPC_CREAT|0600);//创建共享内存
	if(-1==shmid)
	{
		perror("shmget\n");
		return -1;
	}
	printf("shmid=%d\n",shmid);
	int *p;
	p=(int*)shmat(shmid,NULL,0);//连接共享内存
	if((int*)-1==p)//连接失败
	{
		perror("shmat\n");
		return -1;
	}
	p[0]=0;
	int i=0;
	if(!fork())
	{
		for(i=0;i<N;i++)
		{
			p[0]++;
		}
	}else{
		for(i=0;i<N;i++)
		{
			p[0]++;
		}
		wait(NULL);//等待所有进程执行完毕
		printf("p[0]=%d\n",p[0]);
		shmctl(shmid,IPC_RMID,0);
		return 0;
	}
	return 0;
}
