#ifndef AEDI_FILE_
#define AEDI_FILE_
#include<stdio.h>
#include<AEDI/arranjo.h>
#include<AEDI/matriz.h>

typedef struct Arquivo{
    const char* nome;
    FILE* arquivo;
} Arquivo;

enum operacoes_arquivo
{
    LER = 0,
    ESCREVER,
    APPEND
};

Arquivo* abrirArquivo(const char* nomeArquivo, enum operacoes_arquivo tipoOperacao);
void fecharDesalocar(Arquivo* arquivo);
void gravarArranjoArquivo(Arranjo* arranjo, const char* nomeArquivo);
Arranjo* buscarArranjoArquivo(const char* nomeArquivo);
Matriz* buscarMatrizArquivo(const char* nomeArquivo);


#endif
