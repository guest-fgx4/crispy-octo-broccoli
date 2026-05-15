#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include<stdio.h>
#include<stdlib.h>

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
