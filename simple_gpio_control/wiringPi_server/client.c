#include "../util/util.h"

void* sock_write(void*);

int main(int argc, char*argv[])
{
	int sock;
	pthread_t sockWrite;

	if( 3 != argc)
	{
			error_handling("client <ip> <port>");
	}

	sock = initSocketTCPConnect(argv[1], atoi(argv[2]));
	pthread_create(&sockWrite,NULL,sock_write,(void*)&sock);
	pthread_join(sockWrite,NULL);

	return 0;

}

void* sock_write(void* arg)
{
	int select;
	int sock = *((int*)arg);
	char menu[]=MENU;
	char buffer[BUF_SIZE]={0,};

	while(1)
	{
		printf("%s :",menu);
		scanf("%d",&select);
		write(sock,&select,sizeof(int));
		if(4 == select)
			break;
	}

	close(sock);
	return NULL;
}
