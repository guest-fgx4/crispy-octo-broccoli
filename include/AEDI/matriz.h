#ifndef AEDI_MATRIZ_
#define AEDI_MATRIZ_

typedef struct Matriz
{
    int linha;
    int coluna;
    int** dados;
} Matriz;


Matriz* criarMatriz(int linha, int coluna);
void mostrarMatriz(Matriz* matriz);
void desalocarMatriz(Matriz* matriz);
Matriz* transporMatriz(Matriz* matriz);
int matrizZero(Matriz* matriz);


#endif

