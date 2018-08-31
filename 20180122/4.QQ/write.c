#include "func.h"
//管道的写端
int main(int argc,char* argv[])
{
	if(argc!=3)//两个参数
	{
		perror("error args\n");
		return -1;
	}
	int fdw,fdr;
	fdw=open(argv[1],O_WRONLY);//打开1号管道写端
	if(-1==fdw)
	{
		perror("open");
		return -1;
	}
	fdr=open(argv[2],O_RDONLY);
	if(-1==fdr)
	{
		perror("error args");
		return -1;
	}
	printf("I am pipe O_A\n");//管道能在这里卡住


	char buf[128]={0};
	fd_set rdset;
	int ret;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(0,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(0==ret)
				{
					printf("bye bte\n");
					close(fdr);
					close(fdw);
					break;
				}
				write(fdw,buf,strlen(buf)-1);
			}
			if(FD_ISSET(fdr,&rdset))
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
				printf("%s\n",buf);
			}
				
		}

	}	//	}sleep(10);
//	char *p="I am shuai ge";
//    int ret=write(fd,p,strlen(p));
//	printf("ret=%d\n",ret);
//	while(1);//卡住;
		return 0;
}
