.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01signal 02signal
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)

