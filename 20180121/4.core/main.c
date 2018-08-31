#include <stdio.h>
void print(int i)
{
	printf("print i=%d\n",i);
	i=5;
	printf("modify print i=%d\n",i);
}

int main(int argc,char *argv[])
{
	int j=10;
	for(j=0;j<argc;j++)
	{
		puts(argv[j]);
	}
	int a[5]={1,2,3,4,5};
	print(j);
	printf("j=%d\n",j);
	char *p=NULL;//制造崩溃
//	*p;
//	char c=*p;
	for(j=0;j<10;j++)
	{
		printf("j=%d\n",j);
	}
	return 0;
}
