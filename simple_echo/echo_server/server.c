#include "../util/util.h"

int main(int argc, char* argv[])
{
	sock_info serv;
	sock_info clnt;
	int recv_byte;
	char buffer[BUFF_SIZE];

	if( 2 != argc )
		error_handle("server <port>");

	serv.sock = init_TCP_socket_server(atoi(argv[1]));

	while(1)
	{
		clnt.addr_size = sizeof(clnt.addr);
		clnt.sock = accept(serv.sock,(struct sockaddr*)&clnt.addr,&clnt.addr_size);

		recv_byte = read(clnt.sock,buffer,sizeof(buffer));
		if(!strncmp(buffer,END_MSG,strlen(END_MSG)))
			break;

		printf("[%s] connect\n",inet_ntoa(clnt.addr.sin_addr));
		printf("From client : %s -%dbyte\n",buffer,recv_byte);

		write(clnt.sock,buffer,recv_byte);
		printf("To client : %s\n",buffer);

	}
	close(clnt.sock);
	close(serv.sock);

	return 0;
}
