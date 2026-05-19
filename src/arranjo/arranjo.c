#include<stdio.h>
#include<stdlib.h>

#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include "validarArranjos.h"


Arranjo* criarArranjo(int tamanho, enum tipoArranjo tipo)
{
    Arranjo* novoArranjo = NULL;

    if (tamanho > 0)
    {
        novoArranjo = (Arranjo*) malloc(tamanho * sizeof(Arranjo));
        
        switch(tipo)
        {
            case INTEIRO:
                novoArranjo->tipo = tipo;
                novoArranjo->array = malloc(tamanho * INT);
                if (novoArranjo->array != NULL)
                {
                    // adicionar tamanho apenas depois de alocar dados
                    novoArranjo->tamanho = tamanho;
                }
                break;
        }
    }
    else
    {
        ERROR_LINHA("[Arranjo]: tamanho invalido");
    }

    return novoArranjo;
}

void preencherArranjoAleatorio(Arranjo* arranjo, int limiteInf, int limiteSup)
{
    // Pensamento para metodos geneticos ->
    //      usar novamente um swtich para determinar o tipo
    //
    //
    if (arranjo == NULL)
    {
    }
    else
    {
       switch (arranjo->tipo)
       {
           case INTEIRO:
               int* array = (int*) arranjo->array;
               for(int indice = 0; indice < arranjo->tamanho; indice++)
               {
                   array[indice] = randIntIntervalo(limiteInf,limiteSup);
               }
               break;
       }
    }
}


// TODO: Verificar se tem como validar differentes tipos de dados ao
// inves de colocar apenas int
int buscarIntArranjo(Arranjo* arranjo, int valor)
{
    int resposta = 0;

    int* array = (int*) arranjo->array;

    for (int indice = 0; indice < arranjo->tamanho; indice++)
    {
        if (valor == array[indice])
        {
            resposta = 1;
        }
    }

    return resposta;
}

// TODO: Verificar se tem como validar differentes tipos de dados ao
// inves de colocar apenas int
int comprarArranjos(Arranjo* arranjo1, Arranjo* arranjo2)
{
    int resposta = 0;

    // Validar arranjos
    if (validar_arranjosDiferentes(arranjo1, arranjo2)) return resposta;

    int* array1 = (int*) arranjo1->array;
    int* array2 = (int*) arranjo2->array;

    int igual = 1;
    int posicao = 0;
    while (array1[posicao] == array2[posicao] && posicao < arranjo1->tamanho)
    {
        posicao++;
    }
    
    return (posicao == arranjo1->tamanho)? resposta = 1 : resposta;
}


int somarArranjo(Arranjo* arranjo1, int constante, Arranjo* arranjo2)
{
    int soma = 0;

    // validar arranjos
    if(validar_arranjosDiferentes(arranjo1, arranjo2)) return -1;

    int* array1 = (int*) arranjo1->array;
    int* array2 = (int*) arranjo2->array;

    for (int indice = 0; indice < arranjo1->tamanho; indice++)
    {
        soma = soma + (array1[indice] + (constante * array2[indice]));
    }
    

    return soma;
}