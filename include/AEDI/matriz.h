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
int compararMatriz(Matriz* matriz1, Matriz* matriz2);
int somarConstanteMatriz(Matriz* matriz1, int constante, Matriz* matriz2);
Matriz* produtoMatriz(Matriz* matriz1, Matriz* matriz2);


#endif

