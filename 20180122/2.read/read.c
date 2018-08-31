#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
//	write(STDOUT_FILENO,"hello",5);
	printf("\n");
	close(1);//关闭标准输出
    int fd1;
	fd1=dup(fd);
//	close(fd);
	printf("fd=%d,fd1=%d\n",fd,fd1);//打印不出来，因为标准输出被关闭了
	//打印到file1里面去了
	//	int ret;
//	char buf[128]={0};
//	ret=read(fd1,buf,sizeof(buf));
//	printf("ret=%d,buf=%s\n",ret,buf);
	return 0;
}
