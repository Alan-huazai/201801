#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	FILE *fp;
	fp=fopen(argv[1],"ab+");
	if(NULL==fp)
	{
		perror("fopen");
		return -1;
	}
	char buf[128]={0};
	int ret;
//	ret=fread(buf,sizeof(char),sizeof(buf),fp);//读
//	if(ret<=0)
//	{
//		perror("fread");
//		return -1;
//	}
//	printf("ret=%d,buf=%s\n",ret,buf);
	strcpy(buf,"how are you");	
	ret=fwrite(buf,sizeof(char),strlen(buf),fp);//写
	fclose(fp);
	return 0;
}
