#include "../util/util.h"

int main(int argc, char *argv[])
{
	sock_info serv;
	char buffer[BUFF_SIZE];
	int recv_byte, send_byte;

	if(4!=argc)
		error_handle("usage : <ip> <port> <message>\n ");

	serv.sock = init_TCP_socket_client(argv[1],atoi(argv[2]));

  	send_byte=write(serv.sock, argv[3], strlen(argv[3]));
  	if(strncmp(argv[3],END_MSG,strlen(END_MSG)))
  	{
    		printf("To server : %s\n",argv[3]);
  		recv_byte=read(serv.sock, buffer, send_byte);
  		printf("From server : %s -%dbyte\n",buffer,recv_byte);
  	}
  	close(serv.sock);
	return 0;
}
