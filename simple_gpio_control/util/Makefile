CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall 
CFLAGS += -lwiringPi -lpthread

###################################
	
all : $(OBJS)
	$(CC) -c -o $@ $^ $(CFLAGS)
	cp -f $^ ../
clean :
	rm -rf *.o
	cd ../ && rm -rf *.o 
