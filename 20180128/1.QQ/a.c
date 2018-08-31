#include "func.h"
#include "func.c"
//A端
int main(int argc,char* argv[])
{
	int fdw,fdr;
	fdw=open(argv[1],O_WRONLY);//打开1号管道写端
	if(-1==fdr)
	{
		perror("open");
		return -1;
	}
	fdr=open(argv[2],O_RDONLY);//打开2号管道读端
	if(-1==fdw)
	{
		perror("open");
		return -1;
	}
	printf("I am A\n");
	char buf[128]={0};
	int ret;
//	char *p;
	int shmid=shmget((key_t)1234,4096,IPC_CREAT|0600);
  //p=(char *)shmat(shmid,NULL,0);//创建共享内存
	struct text *p=(struct text*)shmat(shmid,NULL,0);
	fd_set rdset;//定义一个集合
	while(1)
	{
		FD_ZERO(&rdset);//将所有rdset集合清零
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);//无描述符阻塞，用来监控
		if(ret>0)
		{
			if(FD_ISSET(fdr,&rdset))//管道可读，读管道
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				if(0==ret)
				{
					printf("bye bye\n");
					close(fdr);
					close(fdw);
					break;
				}
				strcpy(p->buf,buf);//写入共享内存
				p->flag=2;
				printf("%s\n",buf);
			}
			if(FD_ISSET(0,&rdset))//标准输入可读，读标准输入
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(ret>0)
				{
					
					strcpy(p->buf,buf);//写入共享内存
					p->flag=1;
					write(fdw,buf,strlen(buf)-1);//将读到的标准输入，写到2号管道
				//	strcpy(p->buf,buf);//写入共享内存
				//	p->flag=1;
				}else{
					printf("bye bye\n");
					close(fdr);
					close(fdw);
					break;
				}
			}
		}
	}
	return 0;
}
