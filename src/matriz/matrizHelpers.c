#include<string.h>

#include<AEDI/matriz.h>

void* calcularOffset(char* base, unsigned int tamanho, int offset1, int offset2)
{
    return base + (tamanho * (offset1*2) + tamanho * offset2);
}

int compararElementoPosicao(Matriz* matri1, Matriz* matri2, int offset)
{
    void* offset1 = calcularOffset((char*)matri1->dados,matri1->tamamhoTipo,0,offset);
    void* offset2 = calcularOffset((char*)matri2->dados,matri2->tamamhoTipo,0,offset);
    return memcmp(offset1, offset2, matri1->tamamhoTipo);
}

int comprarElemento(Matriz* matriz, const void* elemt, int offset)
{
    void* target = calcularOffset((char*)matriz->dados,matriz->tamamhoTipo,0,offset);
    return memcmp(target, elemt, matriz->tamamhoTipo);
}

int getElementoMatriz(Matriz* matriz, unsigned int x, unsigned int y)
{
    void* target = calcularOffset((char*)matriz->dados, matriz->tamamhoTipo, x, y);
    return *((int*)target);
}

void setElementoMatriz(Matriz* matriz, unsigned int x, unsigned int y, const void* elemt)
{
    void* target = calcularOffset((char*)matriz->dados,matriz->tamamhoTipo, x, y);

    memcpy(target, elemt, matriz->tamamhoTipo);
}