#include "func.h"
int main()

{
	if(!fork())
	{
		printf("I am child\n");
		int msgid=msgget(1234,IPC_CREAT|0600);
		if(-1==msgid)
		{
			perror("msgget\n");
			return -1;
		}
		return 0;
	}
	else{
		printf("I am parents\n");
		wait(NULL);
		return 0;
	}
}
