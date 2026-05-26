CC = gcc
CPP = g++

CFLAGS = -Iinclude/

SRC = src/eds/ed09.c \
 $(wildcard src/arranjo/*.c) \
 $(wildcard src/file/*.c) \
 $(wildcard src/matriz/*.c) \
 $(wildcard src/utils/*.c)


ed09 = ed09
ed10 = ed10
ed11 = ed11

DEBUG = debug

OBJ = obj


$(ed09): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o ./$(OBJ)/$(ed09).o


$(ed11):
	$(CC) $(CFLAGS) $(SRC) -o ./$(OBJ)/$(ed09).o 


$(DEBUG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -g -o $(DEBUG).o



.PHONY: clean
clean:
	rm -f $(OUT)
