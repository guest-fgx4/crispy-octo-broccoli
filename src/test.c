#include<stdio.h>

#define ERROR_LINHA_(a,b) a ## b
#define ERROR_LINHA(string) \
    printf("Error: %s:%d - %s",__FILE__, __LINE__, string );



int main()
{
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of char: %d\n", sizeof(char));
    printf("Size of float: %d\n", sizeof(float));
    printf("Size of double: %d\n", sizeof(double));
    printf("Size of long: %d\n", sizeof(long));
    ERROR_LINHA("dados invalidos")
    return 0;


}

