#ifndef AEDI_MHELPER_
#define AEDI_MHELPER_

#include<AEDI/matriz.h>

void* calcularOffset(char* base, unsigned int tamanho, int offset1, int offset2);
int compararElementoPosicao(Matriz* matri1, Matriz* matri2, int offset);
int comprarElemento(Matriz* matriz, const void* elemt, int offset);
int getElementoMatriz(Matriz* matriz, unsigned int x, unsigned int y);
void setElementoMatriz(Matriz* matriz, unsigned int x, unsigned int y, const void* elemt);


#endif