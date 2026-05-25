#include<stdlib.h>
#include<string.h>

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

void gravarMatrizArquivo(Matriz* matriz, const char* nomeArquivo)
{
    if (matriz == NULL || matriz->dados == NULL)
    {
        ERROR_LINHA("Matriz Invalida");
        return;
    }
    
    Arquivo* arquivo = abrirArquivo(nomeArquivo, ESCREVER);

    fprintf(arquivo->arquivo, "%d\n", matriz->tipo);
    fprintf(arquivo->arquivo, "%d\n", matriz->linha);
    fprintf(arquivo->arquivo, "%d\n", matriz->coluna);

    for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
    {
        for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
        {
            void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceLinha*2) + matriz->tamamhoTipo * indiceColuna);
            
            switch (matriz->tipo)
            {
            case mINTEIRO:
                fprintf(arquivo->arquivo,"%d\n", *((int*)target));
                break;

            case mDOUBLE:
                fprintf(arquivo->arquivo, "%lf\n", *((double*)target));
                break;

            default:
                break;
            }
        }
        printf("\n");
    } 

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
        case aINTEIRO:
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

    arranjo = criarArranjo(tamanho, aINTEIRO);

    if (arranjo == NULL)
    {
        ERROR_LINHA("Falha ao criar um arranjo");
        fecharDesalocar(arquivo);
        return arranjo;
    }


    switch (arranjo->tipo)
    {
        case aINTEIRO:
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

void* buscarMatrizArquivo(const char* nomeArquivo)
{
    int linha = 0;
    int coluna = 0;
    int format;
    void* numero = 0;
    Matriz* matriz = NULL;

    Arquivo* arquivo = abrirArquivo(nomeArquivo, LER);
    if(arquivo != NULL)
    {
        fscanf(arquivo->arquivo, "%d", &format);
        fscanf(arquivo->arquivo, "%d", &linha);
        fscanf(arquivo->arquivo, "%d", &coluna);

        matriz = (Matriz*) criarMatriz(linha, coluna, format);

        if (matriz != NULL)
        {
            
            for (int indiceLinha = 0; indiceLinha < linha; indiceLinha++)
            {
                for (int indiceColuna = 0; indiceColuna < coluna; indiceColuna++)
                {
                    // fscanf(arquivo->arquivo, "%d", &matriz->dados[indiceLinha][indiceColuna]);
                    void* target = (char*)matriz->dados + (indiceLinha*2 * matriz->tamamhoTipo + indiceColuna * matriz->tamamhoTipo);
                    fscanf(arquivo->arquivo, matriz->format, &numero);

                    memcpy(target, (const void*)&numero, matriz->tamamhoTipo);
                }
                
            }
            
        }
    }

    fecharDesalocar(arquivo);
    return (matriz);
}