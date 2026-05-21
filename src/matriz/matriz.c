#include<stdlib.h>
// #include<stdio.h>

#include<AEDI/matriz.h>
#include<AEDI/utils.h>

void* criarMatriz(int linha, int coluna, enum tiposMatriz tipo)
{
    if (linha < 0 || coluna < 0)
    {
        ERROR_LINHA("Valores linha ou coluna invalidos");
    }
    else
    {
        switch (tipo)
        {
        case mINTEIRO:
                Matriz* matriz = NULL;

                matriz = (Matriz*) malloc (1*sizeof(Matriz));

                if (matriz == NULL)
                {
                    ERROR_LINHA("Erro ao criar a matriz");
                    return matriz;
                }

                matriz->dados = (int**) malloc (linha * S_PTR_INT);

                if (matriz->dados == NULL)
                {
                    ERROR_LINHA("erro ao criar dados da matriz");
                    return matriz;
                }

                
                for (int indice = 0; indice < linha; indice++)
                {
                    matriz->dados[indice] = (int*) malloc(coluna * S_INT);
                }
                

                matriz->coluna = coluna;
                matriz->linha = linha;
            break;

        case mDOUBLE:
                DMatriz* Dmatriz = NULL;

                Dmatriz = (DMatriz*) malloc (1*sizeof(DMatriz));

                if (Dmatriz == NULL)
                {
                    ERROR_LINHA("Erro ao criar a matriz");
                    return Dmatriz;
                }

                Dmatriz->dados = (double**) malloc (linha * S_PTR_DOUBLE);

                if (Dmatriz->dados == NULL)
                {
                    ERROR_LINHA("erro ao criar dados da matriz");
                    return Dmatriz;
                }

                
                for (int indice = 0; indice < linha; indice++)
                {
                    Dmatriz->dados[indice] = (double*) malloc(coluna * S_DOUBLE);
                }
                

                Dmatriz->coluna = coluna;
                Dmatriz->linha = linha;

                return Dmatriz;
        break;
        
        default:
            ERROR_LINHA("Nao foi possivel encontrar o tipo da matriz");
            break;
        }
    }
}

Matriz* transporMatriz(Matriz* matriz)
{
    if (matriz == NULL || matriz->linha < 0 || matriz->coluna < 0 || matriz->dados == NULL)
    {
        ERROR_LINHA("Matriz invalida");
        return NULL;
    }

    Matriz* matriz_t = (Matriz*) criarMatriz(matriz->coluna, matriz->linha, mINTEIRO);

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

int compararMatriz(Matriz* matriz1, Matriz* matriz2)
{
    int resposta = 1;

    if (
        matriz1 != NULL || matriz2 != NULL ||
        matriz1->dados != NULL || matriz2->dados != NULL)
    {
        if (matriz1->coluna == matriz2->coluna || matriz1->linha == matriz2->linha)
        {
            for (int indiceLinha = 0; (indiceLinha < matriz1->linha) && resposta; indiceLinha++)
            {
                int indiceColuna = 0;
                while (indiceColuna < matriz1->coluna && resposta)
                {
                    resposta = (matriz1->dados[indiceLinha][indiceColuna] == matriz2->dados[indiceLinha][indiceColuna]);
                    indiceColuna++;
                }
            }
        }
        else
        {
            resposta = 0;
        }
    }
    else
    {
        resposta = 0;
    }

    return resposta;
}

int somarConstanteMatriz(Matriz* matriz1, int constante, Matriz* matriz2)
{
    int soma = 0;

    if (
        matriz1 != NULL || matriz2 != NULL ||
        matriz1->dados != NULL || matriz2->dados != NULL)
    {
        if (matriz1->coluna == matriz2->coluna || matriz1->linha == matriz2->linha)
        {
            for (int indiceLinha = 0; indiceLinha < matriz1->linha; indiceLinha++)
            {
                for (int indiceColuna = 0; indiceColuna < matriz1->coluna; indiceColuna++)
                {
                    soma = soma + (matriz1->dados[indiceLinha][indiceColuna] + (constante * matriz2->dados[indiceLinha][indiceColuna]));
                }
            }
        }
        else
        {
            soma = 0xffff;
        }
    }
    else
    {
        soma = 0xffff;
    }

    return soma;
}

Matriz* produtoMatriz(Matriz* matriz1, Matriz* matriz2)
{
    Matriz* produto = NULL;

    if (
        matriz1 != NULL || matriz2 != NULL ||
        matriz1->dados != NULL || matriz2->dados != NULL)
    {
        if (matriz1->coluna == matriz2->linha)
        {
            produto = (Matriz* ) criarMatriz(matriz1->linha, matriz2->coluna, mINTEIRO);

            if (produto)
            {
                int somatorio = 0;
                const int tamanhoSomatorio = matriz1->coluna;

                for (int indiceLinha = 0; indiceLinha < produto->linha; indiceLinha++)
                {
                    for (int indiceColuna = 0; indiceColuna < produto->coluna; indiceColuna++)
                    {
                        // soma = (matriz1->dados[indiceLinha][indiceColuna] + (constante * matriz2->dados[indiceLinha][indiceColuna]));
                        for (int i = 0; i < tamanhoSomatorio; i++)
                        {
                            somatorio = somatorio + (matriz1->dados[indiceLinha][i] * matriz2->dados[i][indiceColuna]);
                        }
                        produto->dados[indiceLinha][indiceColuna] = somatorio;
                        somatorio = 0;
                    }
                }
            }
        }
    }

    return produto;
}