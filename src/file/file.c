#include<AEDI/file.h>
#include<AEDI/arranjo.h>
#include<stdlib.h>

Arquivo* abrirArquivo(const char* nomeArquivo)
{
    Arquivo* novoArquivo = NULL;

    if (nomeArquivo == NULL)
    {
        printf("Nome do arquivo invalido");
        return novoArquivo;
    }

    novoArquivo = (Arquivo*) calloc(1,sizeof(Arquivo));
    novoArquivo->arquivo = fopen(nomeArquivo, "wt");

    if (novoArquivo->arquivo == NULL)
    {
        printf("Erro ao tentar abrir arquivo");
        return novoArquivo;
    }

    novoArquivo->nome = nomeArquivo;

    return novoArquivo;
}


void fecharDesalocar(Arquivo* arquivo)
{
    fclose(arquivo->arquivo);
    free(arquivo);
}


void gravarArranjoArquivo(Arranjo* arranjo, const char* nomeArquivo)
{
    if (arranjo == NULL || arranjo->array == NULL)
    {
        printf("[file]: arranjo nullo\n");
        return;
    }
    
    Arquivo* arquivo = abrirArquivo(nomeArquivo);

    fprintf(arquivo, "%d\n", arranjo->tamanho);


    switch (arranjo->tipo)
    {
        case INTEIRO:
            int* array = (int*) arranjo->array;
            for(int indice = 0; indice < arranjo->tamanho; indice++)
            {
                fprintf(arquivo, "%d\n", array[indice]);
            }
            break;
    }
    
}
