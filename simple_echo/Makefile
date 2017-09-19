CC = gcc
CLIENT_OBJ = client.o util.o
SERVER_OBJ = server.o util.o
CFLAGS = -Wall 
CFLAGS += -I../util

VPATH = echo_server util
###################################
	
all : serv clnt

serv : $(SERVER_OBJ)
	$(CC) -o $@ $^

clnt : $(CLIENT_OBJ)
	$(CC) -o $@ $^

clean :
	rm -rf *.o serv clnt
