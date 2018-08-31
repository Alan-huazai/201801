#include "func.h"

typedef struct{
	long mtype;
	char buf[64];
}MSG;
int main()
{	
	int ret;
	int msgid=msgget(1234,IPC_CREAT|0600);//创建消息队列
	MSG msg;//定义后需初始化
	bzero(&msg,sizeof(msg));
	msg.mtype=1;//??
	if(-1==msgid)
	{
		perror("msgget\n");
		return -1;
	}
	if(!fork())//子进程
	{
		ret=msgrcv(msgid,&msg,sizeof(msg.buf),1,0);//接受消息队列
		if(-1==ret)
		{
			perror("error msgrcv\n");
			return -1;
		}
		printf("I am child\n");
		printf("%s\n",msg.buf);
		return 0;
	}else{
		strcpy(msg.buf,"hello");
		ret=msgsnd(msgid,&msg,sizeof(msg.buf),0);//发送消息队列
		if(-1==ret)
		{
			perror("error msgsnd\n");
			return -1;
		}
		wait(NULL);
		ret=msgctl(msgid,IPC_RMID,NULL);
		if(-1==ret)
		{
			perror("msgctl\n");
			return -1;
		}
		return 0;
	}
}
