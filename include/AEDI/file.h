#ifndef AEDI_FILE_
#define AEDI_FILE_
#include<stdio.h>
#include<AEDI/arranjo.h>

typedef struct Arquivo{
    const char* nome;
    FILE* arquivo;
} Arquivo;


Arquivo* abrirArquivo(const char* nomeArquivo);
void fecharDesalocar(Arquivo* arquivo);
void gravarArranjoArquivo(Arranjo* arranjo, const char* nomeArquivo);

#endif
