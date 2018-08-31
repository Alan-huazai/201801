#include "func.h"

//清理函数
void cleanup(void *p)
{
	printf("I am cleanup\n");
	free(p);
}
//线程
void* thread_func(void *args)
{
	char *p=(char*)malloc(20);//子进程申请内存
	printf("I am child thread\n");
	memset(p,0,10);
	strcpy(p,"hello");
	puts(p);
	int ret;
	pthread_cleanup_push(cleanup,p);
	pthread_cleanup_pop(1);
	pthread_exit(NULL);
}

int main()
{
	pthread_t pthid;
	pthread_create(&pthid,NULL,thread_func,(void *)123);//创建线程
	//pthread_join(pthid,NULL);
	pthread_cancel(pthid);
	sleep(1);
}
