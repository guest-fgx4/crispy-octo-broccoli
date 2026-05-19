#include<stdlib.h>

#include<AEDI/file.h>
#include<AEDI/arranjo.h>
#include<AEDI/matriz.h>
#include<AEDI/utils.h>

char* buscarOperacao(enum operacoes_arquivo tipoOperacao)
{
    switch(tipoOperacao)
    {
        case LER:
            return ("rt");
            break;

        case ESCREVER:
            return ("wt");
            break;

        case APPEND:
            return ("at");
            break;
    }
}


Arquivo* abrirArquivo(const char* nomeArquivo, enum operacoes_arquivo tipoOperacao) 
{
    Arquivo* novoArquivo = NULL;

    if (nomeArquivo == NULL || nomeArquivo == "")
    {
        ERROR_LINHA("Nome do arquivo invalido");
        return novoArquivo;
    }

    novoArquivo = (Arquivo*) calloc(1,sizeof(Arquivo));
    novoArquivo->arquivo = fopen(nomeArquivo,buscarOperacao(tipoOperacao));

    if (novoArquivo->arquivo == NULL || novoArquivo == NULL)
    {
        ERROR_LINHA("Erro ao tentar abrir arquivo");
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
    
    Arquivo* arquivo = abrirArquivo(nomeArquivo, ESCREVER);

    fprintf(arquivo->arquivo, "%d\n", arranjo->tamanho);


    switch (arranjo->tipo)
    {
        case INTEIRO:
            int* array = (int*) arranjo->array;
            for(int indice = 0; indice < arranjo->tamanho; indice++)
            {
                fprintf(arquivo->arquivo, "%d\n", array[indice]);
            }
            break;
    }
    
}


Arranjo* buscarArranjoArquivo(const char* nomeArquivo)
{
    int tamanho = 0;
    
    Arquivo* arquivo = abrirArquivo(nomeArquivo, LER);
    if (arquivo == NULL) return NULL;

    Arranjo *arranjo = NULL;

    fscanf(arquivo->arquivo, "%d", &tamanho);

    arranjo = criarArranjo(tamanho, INTEIRO);

    if (arranjo == NULL)
    {
        ERROR_LINHA("Falha ao criar um arranjo");
        fecharDesalocar(arquivo);
        return arranjo;
    }


    switch (arranjo->tipo)
    {
        case INTEIRO:
            int* array = (int*) arranjo->array;
            for(int indice = 0; indice < arranjo->tamanho; indice++)
            {
                fscanf(arquivo->arquivo, "%d", &array[indice]);
            }
            break;
    }
    fecharDesalocar(arquivo);
    return arranjo;
}

Matriz* buscarMatrizArquivo(const char* nomeArquivo)
{
    int linha = 0;
    int coluna = 0;
    Matriz* matriz = NULL;

    Arquivo* arquivo = abrirArquivo(nomeArquivo, LER);
    if(arquivo != NULL)
    {
        fscanf(arquivo->arquivo, "%d", &linha);
        fscanf(arquivo->arquivo, "%d", &coluna);

        matriz = criarMatriz(linha, coluna);

        if (matriz != NULL)
        {
            
            for (int indiceLinha = 0; indiceLinha < linha; indiceLinha++)
            {
                for (int indiceColuna = 0; indiceColuna < coluna; indiceColuna++)
                {
                    fscanf(arquivo->arquivo, "%d", &matriz->dados[indiceLinha][indiceColuna]);
                }
                
            }
            
        }
    }

    fecharDesalocar(arquivo);
    return (matriz);
}