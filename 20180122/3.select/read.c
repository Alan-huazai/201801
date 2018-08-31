#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//管道的读端
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		perror("error args\n");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDONLY);//必须是O_RDONLY
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("I am pipe O_RDONLY\n");//管道能在这里卡住
	char buf[128]={0};
	read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
	return 0;
}
