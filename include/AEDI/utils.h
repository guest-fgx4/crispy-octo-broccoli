#ifndef AEDI_UTILS_
#define AEDI_UTILS_


#define BOOL 1
#define CHAR sizeof(char)
#define INT sizeof(int)
#define FLOAT sizeof(float)
#define DOUBLE sizeof(DOUBLE)

#define ERROR_LINHA(string) \
    printf("Error: %s:%d - %s",__FILE__, __LINE__, string )

int randIntIntervalo(int limiteInf, int limiteSup);
int lerIntTeclado(const char* string);

#endif
