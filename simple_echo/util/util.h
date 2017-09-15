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

typedef struct sock_info{
	struct sockaddr_in addr;
	int sock;
	int addr_size;
}sock_info;

void error_handle(const char* msg);
int init_TCP_socket_server(int port);
int init_TCP_socket_client(const char* ip, int port);

#endif //util.h
