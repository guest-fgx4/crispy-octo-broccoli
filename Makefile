CC = gcc
CFLAGS = -Iinclude/
SRC = src/ed09.c \
 $(wildcard src/arranjo/*.c) \
 $(wildcard src/file/*.c) \
 $(wildcard src/matriz/*.c) \
 $(wildcard src/utils/*.c)
OUT = out
DEBUG = debug
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT).o

$(DEBUG) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -g -o $(DEBUG).o

.PHONY: clean
clean:
	rm -f $(OUT)