#include "func.h"

int main(int argc,char*argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	FILE  *fp=popen(argv[1],"w");
	if(NULL==fp)
	{
		perror("fopen");
		return -1;
	}
	char buf[128]="3 4";
	fwrite(buf,sizeof(char),strlen(buf),fp);
	pclose(fp);
	return 0;
}
