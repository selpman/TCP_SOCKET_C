#ifndef _UTIL_H_
#define _UTIL_H_

//C lib
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//unix lib
#include <unistd.h>

//socket & IPv4 lib
#include <arpa/inet.h>
#include <sys/socket.h>

//thread lib
#include <pthread.h>

#define BUFF_SIZE 1024
#define END_MSG "quit"

typedef struct client_info{
	struct sockaddr_in clnt_addr;
	int clnt_sock;
	int clnt_addr_size;
} clnt_info;

void error_handle(const char* msg);
int init_TCP_socket_server(int port);
int init_TCP_socket_client(const char* ip, int port);

#endif //util.h
