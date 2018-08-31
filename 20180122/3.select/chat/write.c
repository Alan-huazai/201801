#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//管道的写端
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		perror("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_WRONLY);//必须是O_WRONLY
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("I am pipe O_WRONLY\n");//管道能在这里卡住
//	sleep(10);
//	char *p="I am shuai ge";
//    int ret=write(fd,p,strlen(p));
//	printf("ret=%d\n",ret);
	char buf[128];
	
	while(1)//卡住
	{
		memset(buf,0,sizeof(buf));
		read(0,buf,sizeof(buf));//从标准输入读取
		write(fd,buf,strlen(buf)-1);
	}
	return 0;
}
