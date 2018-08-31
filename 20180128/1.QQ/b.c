#include "func.h"
#include "func.c"
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		perror("error args\n");
		return -1;
	}
	int fdr,fdw;
	//b端打开1号管道读端
	fdr=open(argv[1],O_RDONLY);
	//再打开2号管道写端
	fdw=open(argv[2],O_WRONLY);
	printf("I am B\n");
	fd_set rdset;//定义一个集合
	char buf[128]={0};
	int ret;
	int shmid=shmget((key_t)1235,4096,IPC_CREAT|0600);	
	struct text *p=(struct text*)shmat(shmid,NULL,0);
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			//标准输入可读
			if(FD_ISSET(0,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(0==ret)
				{
					printf("bye bye1\n");
					close(fdr);
					close(fdw);
					break;
				}
				write(fdw,buf,strlen(buf)-1);
				strcpy(p->buf,buf);
				 p->flag=2;
				
			}
			//
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				if(0==ret)
				{
					printf("bye bye2\n");
					close(fdr);
					close(fdw);
					break;
				}
				strcpy(p->buf,buf);
				p->flag=1;
				printf("%s\n",buf);
			}
		}
	}
	return 0;
}
