#include <stdio.h>
void print(int i)
{
	printf("print i=%d\n",i);
}

int main()
{
	int j=10;
	print(j);
	for(j=0;j<10;j++)
	{
		printf("j=%d\n",j);
	}
	return 0;
}
