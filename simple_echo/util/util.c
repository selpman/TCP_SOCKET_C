#include "util.h"

void error_handle(const char* msg)
{
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}

int init_TCP_socket_server(int port)
{
	sock_info serv;

	//make socket
	serv.sock = socket(PF_INET,SOCK_STREAM,0);
	if( -1 == serv.sock )
		error_handle("sock() error");

	serv.addr.sin_family = AF_INET;
	serv.addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv.addr.sin_port = htons(port);	
	if( -1 == bind(serv.sock, (struct sockaddr*)&serv.addr,sizeof(serv.addr)))
		error_handle("bind() error");

	if( -1 == listen(serv.sock,5))
		error_handle("listen() error");

	return serv.sock;
}

int init_TCP_socket_client(const char* ip, int port)
{
	sock_info serv;

	serv.sock = socket(PF_INET,SOCK_STREAM,0);
	if( -1 == serv.sock)
		error_handle("sock() error");

	serv.addr.sin_family = AF_INET;
	serv.addr.sin_addr.s_addr = inet_addr(ip);
	serv.addr.sin_port = htons(port);

	if( -1 == connect(serv.sock,(struct sockaddr*)&serv.addr,sizeof(serv.addr)))
		error_handle("connect() error");

	return serv.sock;
}
