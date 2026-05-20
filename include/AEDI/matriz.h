#ifndef AEDI_MATRIZ_
#define AEDI_MATRIZ_

enum tiposMatriz
{
    mINTEIRO = 0,
    mDOUBLE
};

typedef struct Matriz
{
    int linha;
    int coluna;
    int** dados;
} Matriz;

typedef struct DMatriz
{
    int linha;
    int coluna;
    double** dados;
} DMatriz;

Matriz* criarMatriz(int linha, int coluna);
void mostrarMatriz(Matriz* matriz);
void desalocarMatriz(Matriz* matriz);
Matriz* transporMatriz(Matriz* matriz);
int matrizZero(Matriz* matriz);
int compararMatriz(Matriz* matriz1, Matriz* matriz2);
int somarConstanteMatriz(Matriz* matriz1, int constante, Matriz* matriz2);
Matriz* produtoMatriz(Matriz* matriz1, Matriz* matriz2);


#endif

