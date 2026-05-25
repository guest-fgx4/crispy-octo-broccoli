#ifndef AEDI_MATRIZ_
#define AEDI_MATRIZ_


enum tiposMatriz
{
    mINTEIRO = 0,
    mDOUBLE
};

typedef enum _padraoPrint
{
    DIAGONAL_PRINCIPAL,
    DIAGONAL_SECUNDARIA,
    TRIANGULO_INFERIOR_PRINCIPAL,
    TRIANGULO_SUPERIOR_PRINCIPAL,
    TRIANGULO_INFERIOR_SECUNDARIA,
    TRIANGULO_SUPERIOR_SECUNDARIA,
} PadraoPrint;

typedef struct Matriz
{
    int linha;
    int coluna;
    unsigned int tamamhoTipo;
    enum tiposMatriz tipo;
    const char* format;
    void* dados;
} Matriz;

int matrizZero(Matriz* matriz);
int compararMatriz(Matriz* matriz1, Matriz* matriz2);
int somarConstanteMatriz(Matriz* matriz1, int constante, Matriz* matriz2);
int matrizZeroFuncao(Matriz* matriz, PadraoPrint padrao);
void mostrarMatriz(Matriz* matriz);
void mostrarMatrizFuncao(Matriz* matriz, PadraoPrint padrao);
void desalocarMatriz(Matriz* matriz);
void* lerMatirzTeclado(int linha, int coluna, enum tiposMatriz tipo);
void* criarMatriz(int linha, int coluna, enum tiposMatriz tipo);
void* transporMatriz(Matriz* matriz);
void* produtoMatriz(Matriz* matriz1, Matriz* matriz2);


#endif

