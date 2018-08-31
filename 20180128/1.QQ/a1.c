#include "func.h"
#include "func.c"
int main()
{
		//连接共享内存
		int shmid=shmget((key_t)1234,4096,IPC_CREAT|0600);
		if(-1==shmid) 
		{
			perror("shmet\n");
			return -1;
		}
		struct text *p=(struct text*)shmat(shmid,NULL,0);
		while(1)
		{	
			if(1==p->flag)
			{
				printf("小蔡:");
				printf("%s\n",p->buf);
				p->flag=0;
			}

			if(2==p->flag)
			{
				printf("小伟:");
				printf("%s\n\n",p->buf);
				p->flag=0;
			}
		}
	return  0;
}
