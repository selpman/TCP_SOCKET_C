#include "util.h"

void error_handle(const char* msg)
{
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}

int init_TCP_socket_server(int port)
{
	int serv_sock;
	struct sockaddr_in serv_addr={0,};

	//make socket
	serv_sock = socket(PF_INET,SOCK_STREAM,0);
	if( -1 == serv_sock )
		error_handle("sock() error");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);	
	if( -1 == bind(serv_sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))
		error_handle("bind() error");

	if( -1 == listen(serv_sock,5))
		error_handle("listen() error");

	return serv_sock;
}

int init_TCP_socket_client(const char* ip, int port)
{
	int sock;
	struct sockaddr_in serv_addr={0,};

	sock = socket(PF_INET,SOCK_STREAM,0);
	if( -1 == sock)
		error_handle("sock() error");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = htons(port);

	if( -1 == connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))
		error_handle("connect() error");

	return sock;
}
