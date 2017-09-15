#ifndef _UTIL_H_
#define _UTIL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <wiringPi.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define MENU "input State :  #1> bad #2> normal #3> good #4> exit\n >>"

#define BIFF_PIN 21

typedef enum{
	RED_LED=19,
	YELLOW_LED=5,
	GREEN_LED =6
}ledColor_t;

typedef enum{
	BAD=1,
	NORMAL,
	GOOD,
	EXIT
}status_t;

typedef struct sock_info{
	int sock;
	struct sockaddr_in addr;
	int addr_size;
}sock_info;

void error_handling(const char* msg);
int initSocketTCPServer(uint16_t port);
int initSocketTCPConnect(const char* ip,  uint16_t port);

void initLED(void);
void singleLedOn(const int pin);

void initBIFF(void);
#endif
