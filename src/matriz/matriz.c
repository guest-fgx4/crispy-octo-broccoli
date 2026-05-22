#include<stdlib.h>
// #include<stdio.h>

#include<AEDI/matriz.h>
#include<AEDI/utils.h>
#include "matrizHelpers.h"

void* criarMatriz(int linha, int coluna, enum tiposMatriz tipo)
{
    if (linha < 0 || coluna < 0)
    {
        ERROR_LINHA("Valores linha ou coluna invalidos");
        return NULL;
    }

    Matriz* matriz = NULL;
    matriz = (Matriz*) malloc (1*sizeof(Matriz));

    if (matriz == NULL)
    {
        ERROR_LINHA("Erro ao criar a matriz");
        return NULL;
    }

    switch (tipo)
    {
    case mINTEIRO:

            // XXX: idea sugerida por AI para reduzir o numero de returns:
            //      Usar um rotina de clearn up baseado em gotos.
            //      OBS: o proprio kernel do linux ja tem um metodo mais
            //      avancado para limpar ao retornar do sistema sem utilizar
            //      gotos (scope-based cleanup helper)

            matriz->dados = malloc (linha * S_PTRR_INT);

            if (matriz->dados == NULL)
            {
                ERROR_LINHA("erro ao criar dados da matriz");
            }
            else
            {
                for (int indice = 0; indice < linha; indice++)
                {
                    matriz->dados[indice] = (int*) malloc(coluna * S_INT);
                }   

                matriz->coluna = coluna;
                matriz->linha = linha;
                matriz->format = "%d";
                matriz->tipo = mINTEIRO;
                matriz->tamamhoTipo = S_INT;
            }
        break;

    case mDOUBLE:
            matriz->dados =  malloc (linha * S_PTRR_DOUBLE);

            if (matriz->dados == NULL)
            {
                ERROR_LINHA("erro ao criar dados da matriz");
            }
            else
            {
                for (int indice = 0; indice < linha; indice++)
                {
                    matriz->dados[indice] = (double*) malloc(coluna * S_DOUBLE);
                }   
                
                matriz->coluna = coluna;
                matriz->linha = linha;
                matriz->format = "%lf";
                matriz->tipo = mDOUBLE;
                matriz->tamamhoTipo = S_DOUBLE;
            }
    break;
    
    default:
        ERROR_LINHA("Nao foi possivel encontrar o tipo da matriz");
        break;
    }

    return matriz;
}

void* transporMatriz(Matriz* matriz)
{
    if (matriz == NULL || matriz->linha < 0 || matriz->coluna < 0 || matriz->dados == NULL)
    {
        ERROR_LINHA("Matriz invalida");
        return NULL;
    }

    Matriz* matriz_t = (Matriz*) criarMatriz(matriz->coluna, matriz->linha, matriz->tipo);

    if (matriz_t != NULL)
    {
        for (int indiceLinha = 0; indiceLinha < matriz_t->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz_t->coluna; indiceColuna++)
            {
                // matriz_t->dados[indiceLinha][indiceColuna] = matriz->dados[indiceColuna][indiceLinha];

                // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceColuna*2) + matriz->tamamhoTipo * indiceLinha);
                // void* target2 = (char*)matriz_t->dados + (matriz_t->tamamhoTipo * (indiceLinha*2) + matriz_t->tamamhoTipo * indiceColuna);

                // void* target = calcularOffset((char*)matriz->dados,matriz->tamamhoTipo, indiceColuna, indiceLinha);
                // void* target2 = calcularOffset((char*)matriz_t->dados,matriz_t->tamamhoTipo, indiceLinha, indiceColuna);

                // memcpy(target2, (const void*)target, sizeof(int));

                setElementoMatriz(matriz_t, indiceLinha, indiceColuna, calcularOffset((char*)matriz->dados,matriz->tamamhoTipo, indiceColuna, indiceLinha));
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

    const short zero = 0;
    int resposta = 1;
    const int tamamhoMatriz = matriz->linha * matriz->coluna;
    int contador = 0;

    while (contador < tamamhoMatriz && resposta)
    {
        // printf("Valor %d\n", !comprarElemento(matriz, (const void*)&zero, contador));
        if (comprarElemento(matriz, (const void*)&zero, contador))
        {
            resposta = 0;
        }
        contador++;
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
                // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceLinha*2) + matriz->tamamhoTipo * indiceColuna);
                void* target = calcularOffset((char*)matriz->dados, matriz->tamamhoTipo, indiceLinha, indiceColuna);
                printf("%d ", *((int*)target));
            }
            printf("\n");
        }
    }
}

void desalocarMatriz(Matriz* matriz)
{   
    void* target = 0;
    // for (int indice = 0; indice < (matriz->linha * matriz->coluna); indice++)
    // {
    //     target = calcularOffset((char*)matriz->dados,matriz->tamamhoTipo,0,indice);
    //     free(target);
    // }
    free(matriz->dados);
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
            // for (int indiceLinha = 0; (indiceLinha < matriz1->linha) && resposta; indiceLinha++)
            // {
            //     int indiceColuna = 0;
            //     while (indiceColuna < matriz1->coluna && resposta)
            //     {
            //         resposta = (matriz1->dados[indiceLinha][indiceColuna] == matriz2->dados[indiceLinha][indiceColuna]);
            //         indiceColuna++;
            //     }
            // }

            const int tamamhoMatriz = matriz1->linha * matriz1->coluna;
            int contador = 0;
            while (contador < tamamhoMatriz && resposta)
            {
                // retorna um valor diferente de 0 se diferentes
                if (compararElementoPosicao(matriz1, matriz2, contador))
                {
                    resposta = 0;
                }
                contador++;
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
                    // soma = soma + (matriz1->dados[indiceLinha][indiceColuna] + (constante * matriz2->dados[indiceLinha][indiceColuna]));
                    // soma = soma + *((int*)calcularOffset((char*)matriz1->dados,matriz1->tamamhoTipo, indiceLinha, indiceColuna));
                    // soma = soma + (constante * (*((int*)calcularOffset((char*)matriz2->dados,matriz2->tamamhoTipo, indiceLinha, indiceColuna))));

                    soma = soma + (getElementoMatriz(matriz1, indiceLinha, indiceColuna));
                    soma = soma + (constante * getElementoMatriz(matriz2, indiceLinha, indiceColuna));
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

void* produtoMatriz(Matriz* matriz1, Matriz* matriz2)
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
                        // *((int*)calcularOffset((char*)matriz1->dados,matriz1->tamamhoTipo, indiceLinha, indiceColuna));
                        for (int i = 0; i < tamanhoSomatorio; i++)
                        {
                            // somatorio = somatorio + (matriz1->dados[indiceLinha][i] * matriz2->dados[i][indiceColuna]);
                            somatorio = somatorio + (getElementoMatriz(matriz1, indiceLinha, i) * getElementoMatriz(matriz2, i, indiceColuna));
                        }
                        // produto->dados[indiceLinha][indiceColuna] = somatorio;
                        setElementoMatriz(produto,indiceLinha, indiceColuna, (const void*)&somatorio);

                        somatorio = 0;
                    }
                }
            }
        }
    }

    return produto;
}