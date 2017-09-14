#include "../util/util.h"

int main(int argc, char* argv[])
{
	int serv_sock;
	clnt_info clnt;
	int recv_byte, send_byte;
	char buffer[BUFF_SIZE];

	if( 2 != argc )
		error_handle("server <port>");

	serv_sock = init_TCP_socket_server(atoi(argv[1]));

	while(1)
	{
		clnt.clnt_addr_size = sizeof(clnt.clnt_addr);
		clnt.clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt.clnt_addr,&clnt.clnt_addr_size);

		recv_byte = read(clnt.clnt_sock,buffer,sizeof(buffer));
		if(!strncmp(buffer,END_MSG,strlen(END_MSG)))
			break;

		printf("[%s] connect\n",inet_ntoa(clnt.clnt_addr.sin_addr));
		printf("From client : %s -%dbyte\n",buffer,recv_byte);

		send_byte = write(clnt.clnt_sock,buffer,recv_byte);
		printf("To client : %s\n",buffer);

	}
	close(clnt.clnt_sock);
	close(serv_sock);

	return 0;
}
