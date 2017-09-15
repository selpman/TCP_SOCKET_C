#include "../util/util.h"

void* clnt_main(void*);
void* biff_main(void*);

int biff_time=0xff;

int main(int argc, char *argv[])
{
	sock_info serv;
	sock_info clnt;

	pthread_t t_sock;
	pthread_t t_biff;

	if(2!=argc)
	{
		error_handling("server port");
	}

	serv.sock=initSocketTCPServer(atoi(argv[1]));

	initLED();
	initBIFF();

	pthread_create(&t_biff,NULL,biff_main,NULL);

	while(1)
	{
		clnt.addr_size = sizeof(struct sockaddr_in);
		clnt.sock=accept(serv.sock, (struct sockaddr*)&clnt.addr, &clnt.addr_size);

		if(-1 !=clnt.sock)
		{
			printf("client (%s) connect \n",inet_ntoa(clnt.addr.sin_addr),clnt.sock);
			pthread_create(&t_sock,NULL,clnt_main,(void*)&clnt);
		}

	}

	close(serv.sock);
}

void* clnt_main(void* arg)
{
	sock_info clnt = *((sock_info*)arg);
	int select;
	int stop=1;

	while(stop)
	{
		read(clnt.sock,&select,sizeof(int));

		switch(select)
		{
			case BAD:
				printf("%s > bad status!\n",inet_ntoa(clnt.addr.sin_addr));
				biff_time = 0x2f;
				singleLedOn(RED_LED);
			break;

			case NORMAL:
				printf("%s > normal status!\n",inet_ntoa(clnt.addr.sin_addr));
				biff_time = 0x7f;
				singleLedOn(YELLOW_LED);
			break;

			case GOOD:
				printf("%s > good status!\n",inet_ntoa(clnt.addr.sin_addr));
				biff_time = 0xff;
				singleLedOn(GREEN_LED);
			break;

			case EXIT:
				stop = 0;
			break;
		}
	}

	printf("client (%s) disconnect\n",inet_ntoa(clnt.addr.sin_addr));
	close(clnt.sock);

	return NULL;
}


void* biff_main(void* null)
{
	while(1)
	{
		delay(biff_time);
		digitalWrite(BIFF_PIN,HIGH);
		delay(biff_time);
		digitalWrite(BIFF_PIN,LOW);
	}
}
