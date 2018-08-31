#include "func.h"
//read端
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		perror("error args\n");
		return -1;
	}
	int fdw,fdr;//先读后写
	fdr=open(argv[1],O_RDONLY);
	if(-1==fdr)
	{
		perror("open");
		return -1;
	}
	fdw=open(argv[2],O_WRONLY);
	if(-1==fdw)
	{
		perror("open");
		return -1;
	}
	printf("I am pipe O_B\n");//管道能在这里卡住
//	char buf[128]={0};
//	read(fd,buf,sizeof(buf));
//	printf("%s\n",buf);



	char buf[128]={0};
	fd_set rdset;//定义一个集合
	int ret;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(fdr,&rdset))//它在集合中，说明可读，如果管道可读就去读管道，如果管道中无数据则阻塞
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
			if(FD_ISSET(0,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(ret>0)
				{
					write(fdw,buf,strlen(buf)-1);
					
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
