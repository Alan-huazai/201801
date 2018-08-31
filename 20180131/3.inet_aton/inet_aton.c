#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	struct in_addr addr;
	ret=inet_aton(argv[1],&addr);
	printf("ret=%d\n",ret);
	//将IP转换成十六进制
	printf("addr.s_addr=%x\n",addr.s_addr);
	printf("addr.s_addr=%x\n",inet_addr(argv[1]));
	//将ip地址转换成点分十进制
	printf("ip=%s\n",inet_ntoa(addr));
	return 0;
}
