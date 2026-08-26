CC = gcc
CXX = g++

CXX_FLAGS = -std=c++11

CFLAGS = -Iinclude/ -Lobj/
OBJ_DIR = obj
OBJS = arranjo.o file.o matriz.o utils.o
CC_OBJS = ./obj/arranjo.o ./obj/file.o ./obj/matriz.o ./obj/utils.o ./obj/arranjoHelper.o ./obj/matrizHelpers.o 
OBJS_CXX = ./obj/arranjoCXX.o

ARRANJO = ./src/arranjo/arranjo.c
FILE = ./src/file/file.c
MATRIZ = ./src/matriz/matriz.c
UTILS = ./src/utils/utils.c

DEBUG = debug



arranjo.o: $(ARRANJO) | $(OBJ_DIR)
	@echo "Compilando arranjo"
	$(CC)  $(CFLAGS) -c ./src/arranjo/validarArranjos.c -o $(OBJ_DIR)/arranjoHelper.o
	$(CXX)  $(CFLAGS) -c ./src/arranjo/arranjo.cpp -o $(OBJ_DIR)/arranjoCXX.o
	$(CC)  $(CFLAGS) -c $(ARRANJO) -o $(OBJ_DIR)/arranjo.o

file.o: $(FILE)
	@echo "Compilando arquivo"
	$(CC) $(CFLAGS) -c  $(FILE)  -o $(OBJ_DIR)/file.o

matriz.o: $(MATRIZ)
	@echo "Compilando matriz"
	$(CC) $(CFLAGS) -c  ./src/matriz/matrizHelpers.c -o $(OBJ_DIR)/matrizHelpers.o
	$(CC) $(CFLAGS) -c  $(MATRIZ) -o $(OBJ_DIR)/matriz.o
	
utils.o: $(UTILS)
	@echo "Compilando utils"
	$(CC) $(CFLAGS) -c $(UTILS) -o $(OBJ_DIR)/utils.o

ed09: $(OBJS) | $(OBJ_DIR)
	$(CC) ./src/eds/ed09.c $(CFLAGS) $(OBJS) -o ./ed09

ed10: $(OBJS) | $(OBJ_DIR)
	$(CC) ./src/eds/ed10.c $(CFLAGS) $(OBJS) -o ./ed10

ed11: $(OBJS) | $(OBJ_DIR)
	$(CXX) ./src/eds/ed11.cpp $(CFLAGS)  $(CC_OBJS) $(OBJS_CXX) -o ./ed11



$(DEBUG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -g -o $(DEBUG).o


$(OBJ_DIR):
	mkdir $@

.PHONY: clean
clean:
	rm -f $(OUT)
