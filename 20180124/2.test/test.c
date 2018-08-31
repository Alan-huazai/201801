#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("errpr args\n");
		return -1;
	}

	FILE *fp;
	fp=popen(argv[1],"r");
	
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}
	char buf[128]={0};
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);
	return 0;

}
