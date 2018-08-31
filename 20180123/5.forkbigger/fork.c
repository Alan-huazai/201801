#include "func.h"
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1];O_RDWR);
	pid_t pid;
	int buf[128]={0};
	pid=fork();//：
	if(0==pid)
	{
		printf("I am child\n");
		ret=read(fd,buf,sizeof(buf));
		printf("ret=%d,
	
	}else{
		prinf("I am parent\n");


	}
