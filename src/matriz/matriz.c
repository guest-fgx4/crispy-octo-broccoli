#include<stdlib.h>
// #include<stdio.h>

#include<AEDI/matriz.h>
#include<AEDI/utils.h>

Matriz* criarMatriz(int linha, int coluna)
{
    Matriz* matriz = NULL;

    if (linha < 0 || coluna < 0)
    {
        ERROR_LINHA("Valores linha ou coluna invalidos");
        return matriz;
    }

    matriz = (Matriz*) malloc (1*sizeof(Matriz));

    if (matriz == NULL)
    {
        ERROR_LINHA("Erro ao criar a matriz");
        return matriz;
    }

    matriz->dados = (int**) malloc (linha * sizeof(int*));

    if (matriz->dados == NULL)
    {
        ERROR_LINHA("erro ao criar dados da matriz");
        return matriz;
    }

    
    for (int indice = 0; indice < linha; indice++)
    {
        matriz->dados[indice] = (int*) malloc(coluna * sizeof(int));
    }
    

    matriz->coluna = coluna;
    matriz->linha = linha;

    return matriz;

}

Matriz* transporMatriz(Matriz* matriz)
{
    if (matriz == NULL || matriz->linha < 0 || matriz->coluna < 0 || matriz->dados == NULL)
    {
        ERROR_LINHA("Matriz invalida");
        return NULL;
    }

    Matriz* matriz_t = criarMatriz(matriz->coluna, matriz->linha);

    if (matriz_t != NULL)
    {
        for (int indiceLinha = 0; indiceLinha < matriz_t->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz_t->coluna; indiceColuna++)
            {
                matriz_t->dados[indiceLinha][indiceColuna] = matriz->dados[indiceColuna][indiceLinha];
            }
        }
    }

    return matriz_t;
}

int matrizZero(Matriz* matriz)
{
    if (matriz == NULL || matriz->linha < 0 || matriz->coluna < 0 || matriz->dados == NULL)
    {
        ERROR_LINHA("Matriz invalida");
        return 0;
    }

    int resposta = 1;

    for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
    {
        for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
        {
            if (matriz->dados[indiceLinha][indiceColuna] != 0)
            {
                resposta = 0;
            }
        }
    }

    return resposta;
}


void mostrarMatriz(Matriz* matriz)
{
    if (matriz != NULL)
    {
        for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
            {
                printf("%d ", matriz->dados[indiceLinha][indiceColuna]);
            }
            printf("\n");
        }
    }
}

void desalocarMatriz(Matriz* matriz)
{
    for (int indice = 0; indice < matriz->linha; indice++)
    {
        free(matriz->dados[indice]);
    }
    free(matriz);
}