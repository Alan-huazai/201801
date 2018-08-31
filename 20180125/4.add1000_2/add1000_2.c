#include "func.h"
#define N 10000000
int main()
{
	int shmid;
	shmid=shmget((key_t)1234,4096,IPC_CREAT|0600);
	if(-1==shmid)
	{
		perror("shmget");
		return -1;
	}

	printf("shmid=%d\n",shmid);
	int semid;
	semid=semget(1234,1,IPC_CREAT|0600);
	if(-1==semid)
	{
		perror("semget\n");
		return -1;
	}
	int ret;
	ret=semctl(semid,0,SETVAL,1);
	
		if(-1==ret)
		{
			perror("semctl");
			return -1;
		}
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	if((int*)-1==p)
	{
		perror("shmat");
		return -1;
	}
	p[0]=0;
	int i=0;
	struct sembuf sopp,sopv;
	bzero(&sopp,sizeof(sopp));
	bzero(&sopp,sizeof(sopv));
	sopp.sem_num=0;
	sopp.sem_op=-1;
	sopp.sem_flg=SEM_UNDO;
	sopv.sem_num=0;
	sopv.sem_op=1;
	sopv.sem_flg=SEM_UNDO;
	if(!fork())//子进程
	{

		for(i=0;i<N;i++)
		{
			semop(semid,&sopp,1);
			p[0]++;
			semop(semid,&sopv,1);
		}
	}else{
		
		for(i=0;i<N;i++)
		{
			semop(semid,&sopp,1);
			p[0]++;
			semop(semid,&sopv,1);
		}
			wait(NULL);
			printf("p[0]=%d\n",p[0]);
	}
	return 0;
}
