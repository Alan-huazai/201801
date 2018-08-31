#include "func.h"
int main(int argc,char*argv[])
{
	int fds[2];
	pipe(fds);//创建无名管道
	if(!fork())
	{
		//子进程为写端，关闭读端fds[0]
		close(fds[0]);
		char buf[128]="hello";
		write(fds[1],buf,sizeof(buf));
		return 0;
	}else
	{
		//父进程为读端，关闭写端fds[1]
		close(fds[1]);
		char buf[128]={0};
		read(fds[0],buf,sizeof(buf));
		printf("I am parents,%s\n",buf);
		wait(NULL);
		return 0;
	}

}
