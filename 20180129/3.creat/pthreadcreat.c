#include "func.h"
//创建一个线程
void* thread_func(void *p)
{
	printf("I am thread\n")	;
	while(1);
}

int main()
{
	pthread_t pthid;
	int ret=pthread_create(&pthid,NULL,thread_func,NULL);//创建线程
	if(ret!=0)
	{
		printf("pthread_creat ret=%d\n",ret);
		return -1;
	}
}
