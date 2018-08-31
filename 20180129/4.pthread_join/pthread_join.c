#include "func.h"
void* thread_func(void *p)
{
	//子线程
	
	printf("I am child thread，p=%p,j=%ld\n",p,(long)p);
	pthread_exit((void *)2);
	//return NULL;
}
int main()
{
	//创建线程
	pthread_t pthid;
	int ret=pthread_create(&pthid,NULL,thread_func,(void*)1);//传入参数1
	if(ret!=0)
	{
		printf("pthread_create\n");
		return -1;
	}
	void *p;
	int i=0;
	printf("&i=%p\n",&i);
	//线程回收子进程的返回值
	ret=pthread_join(pthid,(void**)&i);
	if(ret!=0)
	{
		printf("pthread_join ret=%d\n",ret);
		return -1;
	}
	printf("I am main thread,p=%p,i=%d\n",p,i);
	return 0;

}
