#include<stdlib.h>
#include<string.h>
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
    matriz = malloc (1*sizeof(Matriz));

    if (matriz == NULL)
    {
        ERROR_LINHA("Erro ao criar a matriz");
        return NULL;
    }

    switch (tipo)
    {
    case mINTEIRO:

            // README:  idea sugerida por AI para reduzir o numero de returns: 
            //          Usar um rotina de clearn up baseado em gotos. Para um programacao
            //          em C seria mais interessante?
            //          OBS: o proprio kernel do linux ja tem um metodo mais
            //          avancado para limpar ao retornar do sistema sem utilizar
            //          gotos (scope-based cleanup helper)

            matriz->dados = malloc ((linha * coluna) * S_INT);

            if (matriz->dados == NULL)
            {
                ERROR_LINHA("erro ao criar dados da matriz");
            }
            else
            {

                /*
                README: Pesando em alocamento em memoria com void* acho que pode ser feito
                        o alocamento direto apenas obtento o tamanho total ao inves de
                        fazer do metodo convencional (usando double**) ha alguma mudanca
                        significativa? 
                        Uma possivel mudanca pode ser na hora de desalocar, ja que e' 
                        nessesario desalocar de mesma forma que foi alocado anteriormente

                        ----- Metodo antigo abaixo -----
                */
                // matriz->dados = malloc ((linha * coluna) * S_INT);
                // for (int indice = 0; indice < linha; indice++)
                // {
                //     matriz->dados[indice] = malloc(coluna * sizeof(int*));
                // }   

                matriz->coluna = coluna;
                matriz->linha = linha;
                matriz->format = "%d";
                matriz->tipo = mINTEIRO;
                matriz->tamamhoTipo = S_INT;
            }
        break;

    case mDOUBLE:
            matriz->dados =  malloc ((linha * coluna) * S_DOUBLE);

            if (matriz->dados == NULL)
            {
                ERROR_LINHA("erro ao criar dados da matriz");
            }
            else
            {
                // for (int indice = 0; indice < linha; indice++)
                // {
                //     matriz->dados[indice] = (double*) malloc(coluna * S_DOUBLE);
                // }   
                
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

void* lerMatirzTeclado(int linha, int coluna, enum tiposMatriz tipo)
{
    void* dado = 0;

    Matriz* matriz = criarMatriz(linha, coluna,tipo);


    if (matriz != NULL && matriz->dados != NULL)
    {
        for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
            {
                // fscanf(arquivo->arquivo, "%d", &matriz->dados[indiceLinha][indiceColuna]);
                // void* target = (char*)matriz->dados + (indiceLinha*2 * matriz->tamamhoTipo + indiceColuna * matriz->tamamhoTipo);
                void* target = calcularOffset((char*)matriz->dados,matriz->tamamhoTipo, indiceLinha, indiceColuna);
                

                printf("Entrar com o valor para a matriz: ");
                scanf(matriz->format, &dado); getchar();

                memcpy(target, (const void*)&dado, matriz->tamamhoTipo);
            }
            
        }
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
    if (matriz != NULL && matriz->dados != NULL);
    {
        for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
            {
                // printf("Valor = %d\n", (2*indiceColuna+indiceLinha));
                // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceLinha*2) + matriz->tamamhoTipo * indiceColuna);
                void* target = calcularOffset((char*)matriz->dados, matriz->tamamhoTipo, indiceLinha, indiceColuna);
                
                switch (matriz->tipo)
                {
                case mINTEIRO:
                    printf("%d\t", *((int*)target));
                    break;

                case mDOUBLE:
                    printf("%lf\t", *((double*)target));
                    break;

                default:
                    ERROR_LINHA("Tipo de matriz nao achado");
                    break;
                }
            }
            printf("\n");
        }
    }
}

int escolherPadrao (int linha, int coluna, int tamanho, PadraoPrint padrao)
{
    int respota = 0;
    
    switch (padrao)
    {
    case  DIAGONAL_PRINCIPAL:
        if (linha == coluna)
        {
            respota = 1;
        }

        break;
    case  DIAGONAL_SECUNDARIA:
        if (linha == (tamanho - coluna - 1))
        {
            respota = 1;
        }
        
        break;
    case  TRIANGULO_INFERIOR_PRINCIPAL:
        if (linha > coluna)
        {
            respota = 1;
        }

        break;
    case  TRIANGULO_SUPERIOR_PRINCIPAL:
        if (linha < coluna)
        {
            respota = 1;
        }
        break;
    case  TRIANGULO_INFERIOR_SECUNDARIA:    
        if (linha > (tamanho - coluna - 1))
        {
            respota = 1;
        }
    
        break;
    case  TRIANGULO_SUPERIOR_SECUNDARIA:
        if (linha <(tamanho - coluna - 1))
        {
            respota = 1;
        }
        break;
        
    default:
        break;
    }

    return respota;
}

void mostrarMatrizFuncao(Matriz* matriz, PadraoPrint padrao)
{
    if (matriz != NULL && matriz->dados != NULL && matriz->coluna == matriz->linha);
    {
        for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
        {
            for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
            {
                if (escolherPadrao(indiceLinha, indiceColuna, matriz->coluna, padrao))
                {
                    // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceLinha*2) + matriz->tamamhoTipo * indiceColuna);
                    void* target = calcularOffset((char*)matriz->dados, matriz->tamamhoTipo, indiceLinha, indiceColuna);
                    
                    switch (matriz->tipo)
                    {
                    case mINTEIRO:
                        printf("%d\t", *((int*)target));
                        break;

                    case mDOUBLE:
                        printf("%.4lf\t", *((double*)target));
                        break;

                    default:
                        break;
                    }
                }
                else
                {
                    printf("X \t");
                }
            }
            printf("\n");
        }
    }
}

int matrizZeroFuncao(Matriz* matriz, PadraoPrint padrao)
{
    if (
        matriz == NULL
        || matriz->linha < 0
        || matriz->coluna < 0
        || matriz->dados == NULL
        || matriz->linha != matriz->coluna
    )
    {
        ERROR_LINHA("Matriz invalida");
        return 0;
    }

    int tamanho = matriz->tamamhoTipo;
    const void* zero;
    int resposta = 1;

    for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
    {
        for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
        {
            if (escolherPadrao(indiceLinha, indiceColuna, matriz->coluna, padrao))
            {
                // printf("Chegou aqui");
                // if (comprarElemento(matriz, NULL, ((indiceLinha*2) * tamanho + indiceColuna * tamanho)))

                if (*((double*)calcularOffset((char*)matriz->dados, tamanho, indiceLinha, indiceColuna)) != 0.0)
                {
                    resposta = 0;
                    indiceColuna = matriz->coluna;
                    indiceLinha = matriz->linha;
                }
            }
        }
    }
    
    return resposta;
}

void desalocarMatriz(Matriz* matriz)
{   
    void* target = 0;
    
    // for (int indice = 0; indice < matriz->linha; indice++)
    // {
    //     target = calcularOffset((char*)matriz->dados,sizeof(int*),0,(matriz->coluna* indice));
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
