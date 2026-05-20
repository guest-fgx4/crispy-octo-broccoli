#include<stdio.h>
#include<stdlib.h>

enum tipoArranjo {
    INTEIRO             = 0,
    DUPLA_PRECISAO,
    CARACTERE
};

typedef struct Arranjo{
    int tamanho;
    enum tipoArranjo tipo;
    void *array;
} Arranjo;


void* criarArranjo(int tamanho, enum tipoArranjo tipo)
{
    Arranjo* novoArranjo = NULL;

    if (tamanho > 0)
    {
        novoArranjo = (Arranjo*) malloc(tamanho * sizeof(Arranjo));
        
        switch(tipo)
        {
            case INTEIRO:
                novoArranjo->tipo = tipo;
                novoArranjo->array = malloc(tamanho * sizeof(int));
                if (novoArranjo->array != NULL)
                {
                    // adicionar tamanho apenas depois de alocar dados
                    novoArranjo->tamanho = tamanho;

                    int* array = (int*) novoArranjo->array;

                    for (int i = 0; i < tamanho; i++)
                    {
                        array[i] = i;
                    }
                }
                
                break;
        }
    }

    return novoArranjo;
}

int main()
{
    Arranjo* arranjo = (Arranjo*) criarArranjo(3, INTEIRO);
    int* array = (int*) arranjo->array;

    for (int i = 0; i < 3; i++)
    {
        printf("Valor em %d: %d\n", i, array[i]);
    }

    free (arranjo);

    return 0;
    
}

