#ifndef AEDI_FILE_
#define AEDI_FILE_
#include<stdio.h>
#include<AEDI/arranjo.h>
#include<AEDI/matriz.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef struct Arquivo{
    const char* nome;
    FILE* arquivo;
} Arquivo;

typedef enum _operacoes_arquivo
{
    LER = 0,
    ESCREVER,
    APPEND
} OpArquivo;

Arquivo* abrirArquivo(const char* nomeArquivo, enum operacoes_arquivo tipoOperacao);
void fecharDesalocar(Arquivo* arquivo);
void gravarMatrizArquivo(Matriz* matriz, const char* nomeArquivo);
void gravarArranjoArquivo(Arranjo* arranjo, const char* nomeArquivo);
Arranjo* buscarArranjoArquivo(const char* nomeArquivo);
void* buscarMatrizArquivo(const char* nomeArquivo);

#ifdef __cplusplus
}
#endif

#endif
