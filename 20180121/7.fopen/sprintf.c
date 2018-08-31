#include <stdio.h>
#include <string.h>

typedef struct student{
	int num;
	char name[20];
	float score;
}stu;
int main(int argc,char* argv[])
{
	stu s={1001,"xiongda",88.5};
	memset(&s,0,sizeof(s));
	//char buf[128]={0};
	char buf[128]="1002 xionger 88";
	//scanf("%d%s%f",&s.num,s.name,&s.score);

	sscanf(buf,"%d%s%f",&s.num,s.name,&s.score);
	printf("%d %s %5.2f\n",s.num,s.name,s.score);
	//sprintf(buf,"%d %s %5.2f",s.num,s.name,s.score);
	//puts(buf);
	return 0;
}

