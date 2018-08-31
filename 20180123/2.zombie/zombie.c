#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
	//printf("Hello world\n");
	//return 0;
		pid_t pid=fork();
		if(0==pid)
		{
			exit(10);
		}
		else{
			wait(NULL);
			sleep(10);
		}
}
