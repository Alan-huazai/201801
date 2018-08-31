#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
//实现ls -l 的效果
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	struct stat buf;
	memset(&buf,0,sizeof(buf));
	int ret=stat(argv[1],&buf);
	if(-1==ret)
	{
		perror("stat");
		return -1;
	}
	printf("%ld,%x,%ld,%s,%s,%ld,%s\n",buf.st_ino,buf.st_mode,buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,ctime(&buf.st_mtime));
	return 0;
}
