#include "func.h"

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	FILE *fp;
	fp=popen(argv[1],"r");
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}
	fread(buf,sizeof(char),strlen(buf),fp);
	pclose(fp);
	return 0;

}
