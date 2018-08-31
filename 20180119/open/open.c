#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd;
	printf("O_RDWR=%x,O_CREAT=%x\n",O_RDWR,O_CREAT);
	fd=open(argv[1],O_RDWR|O_CREAT|O_EXCL,0666);//如何没有文件则创建，如果有则不创建
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("fd=%d\n",fd);
	return 0;
}
