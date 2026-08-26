#ifndef AEDI_UTILS_
#define AEDI_UTILS_

#include<stdio.h>

#define S_BOOL 1
#define S_CHAR sizeof(char)
#define S_PTR_CHAR sizeof(char*)
#define S_PTRR_CHAR sizeof(char**)
#define S_INT sizeof(int)
#define S_PTR_INT sizeof(int*)
#define S_PTRR_INT sizeof(int**)
#define S_FLOAT sizeof(float)
#define S_PTR_FLOAT sizeof(float*)
#define S_PTRR_FLOAT sizeof(float**)
#define S_DOUBLE sizeof(double)
#define S_PTR_DOUBLE sizeof(double*)
#define S_PTRR_DOUBLE sizeof(double**)


#define ERROR_LINHA(string) \
    printf("Error: %s:%d - %s\n",__FILE__, __LINE__, string )

#ifdef __cplusplus
extern "C" {
#endif

int randIntIntervalo(int limiteInf, int limiteSup);
int lerIntTeclado(const char* string);
char* lerLinhaTeclado(const char* string);
char* concatString(char* string1, char* string2);
// extern "C" int sum(int x, int y);
int sum(int x, int y);

#ifdef __cplusplus
}
#endif


#endif
