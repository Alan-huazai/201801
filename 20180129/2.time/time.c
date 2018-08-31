#include <stdio.h>
#include <time.h>
int main()
{
	time_t t;//
	time(&t);//把当前秒数存进来
	struct tm *p;
	p=gmtime(&t);
	printf("%04d-%02d-%02d\n",p->tm_year+1900,p-> tm_mon+1,p->tm_yday);
	return 0;
}

