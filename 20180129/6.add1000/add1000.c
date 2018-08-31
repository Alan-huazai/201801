#include "func.h"
#define N 50000000
long  j=0;//全局变量
typedef struct{
	long total;	
	pthread_mutex_t mutex;
}data;
void* thread_func(void *p)
{
	data *t=(data*)p;
	int i;
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&t->mutex);//枷锁
		//t->total=t->total+1;
		j++;
		pthread_mutex_unlock(&t->mutex);//枷锁
	}
	pthread_exit(NULL);
}
int main()
{
	data t;
	pthread_t pthid;
	int ret=pthread_create(&pthid,NULL,thread_func,(void*)&t);
	if(ret!=0)
	{
		printf("pthread_create\n");
		return -1;
	}
	int i;
	t.total=0;
	ret=pthread_mutex_init(&t.mutex,NULL);
	if(ret!=0)
	{
		printf("pthread");
	}
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&t.mutex);//枷锁
		//t.total=t.total+1;
		j++;
		pthread_mutex_unlock(&t.mutex);//枷锁
	}
	
	//printf("I am main thread,j=%ld\n",t.total);
	pthread_join(pthid,NULL);
	printf("I am main thread,j=%ld\n",j);
	pthread_mutex_destroy(&t.mutex);
	return 0;
}
