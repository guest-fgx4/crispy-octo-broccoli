#include<AEDI/file.h>
#include<stdlib.h>

typedef struct Arquivo{

    const* char nome;
    FILE* Arquivo;
} Arquivo;


Arquivo* abrirArquivo(const* char nomeArquivo)
{
    Arquivo* novoArquivo = NULL;

    if (nomeArquivo == NULL)
    {
        printf("Nome do arquivo invalido");
        return novoArquivo;
    }

    novoArquivo = fopen(nomeArquivo, "wt");

    if (novoArquivo == NULL)
    {
        printf("Erro ao tentar abrir arquivo");
        return novoArquivo;
    }

    novoArquivo->nome = nomeArquivo;

    return novoArquivo;
}
