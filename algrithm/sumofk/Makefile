.PHONY:clean all
CC=g++
#CFLAGS=-Wall -save-temps -O1
CFLAGS=-Wall -g -save-temps #-std=c99
BIN= sumofknumber 
all:$(BIN)
%:%.c 
	$(CC) $(CFLAGS)   $< -o $@
	
clean:
	rm -f *.o $(BIN) *.s *.i
