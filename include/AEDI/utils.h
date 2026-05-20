#ifndef AEDI_UTILS_
#define AEDI_UTILS_

#include<stdio.h>

#define BOOL 1
#define CHAR sizeof(char)
#define PTR_CHAR sizeof(char*)
#define INT sizeof(int)
#define PTR_INT sizeof(int*)
#define FLOAT sizeof(float)
#define PTR_FLOAT sizeof(float*)
#define DOUBLE sizeof(double)
#define PTR_DOUBLE sizeof(double*)


#define ERROR_LINHA(string) \
    printf("Error: %s:%d - %s\n",__FILE__, __LINE__, string )

int randIntIntervalo(int limiteInf, int limiteSup);
int lerIntTeclado(const char* string);
char* lerLinhaTeclado(const char* string);

#endif
