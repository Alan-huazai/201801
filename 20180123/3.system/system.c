#include <stdio.h>
#include <stdlib.h>

int main()
{
	
		int ret;
		ret=system("ls -l");
		printf("ret=%d",ret);
		printf("after ls\n");
	return 0;
}
