CC = gcc
BASE_OBJ = util.o led.o biff.o
CLIENT_OBJ := client.o $(BASE_OBJ)
SERVER_OBJ := server.o $(BASE_OBJ)
CFLAGS = -I../util
CFLAGS += -lwiringPi -lpthread

VPATH = wiringPi_server
###################################
	
all : compile serv clnt

compile : 
	cd util && make

serv : $(SERVER_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clnt : $(CLIENT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	cd util && make clean
	rm -rf *.o serv clnt
