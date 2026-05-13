#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include<stdio.h>

Arranjo* criarArranjo(int tamanho, tipoArranjo tipo)
{
    Arranjo* novoArranjo = NULL;

    if (tamanho > 0)
    {
        novoArranjo = (Arranjo*) calloc(tamanho,sizeof(Arranjo));
        novoArranjo->tamanho = tamanho;
        
        swtich(tipo)
        {
            case INTEIRO:
                novoArranjo->tipo = tipo;
                novoArranjo->array = (int*)calloc(tamanho, sizeof(int));
                break;
        }

    }
    else
    {
        printf("[Arranjo]: tamanho invalido\n");
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
       swtich (arranjo->tipo)
       {
           case INTEIRO:
               int* array = (int*) arranjo->array;
               for(int indice = 0; indice < arranjo->tamanho; indice+)
               {
                   array[indice] = randIntIntervalo(limiteInf,limiteSup)
               }
               break;
       }
    }
}
