#include<stdio.h>
//#define DEBUG
int main()
{
	#ifdef DEBUG
		printf("you can see log\n");
	#endif

	return 0;
}
