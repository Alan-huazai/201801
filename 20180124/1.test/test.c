#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	char *buf="hello";
	int i,j;
	i=sizeof(buf);
	j=strlen(buf);
	printf("sizeof（）= %d\n",i);
	printf("strlen()= %d\n",j);
	return 0;
}
