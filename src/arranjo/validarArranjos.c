#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include "validarArranjos.h"

// TODO: depois olhar a comparacao por tipos
int validar_arranjosDiferentes(Arranjo* arranjo1, Arranjo* arranjo2)
{
    int resposta = 0;
    if (arranjo1 == NULL || arranjo2 == NULL)
    {
        ERROR_LINHA("Arranjo nullo");
        return resposta;
    }
    else if (arranjo1->tamanho != arranjo2->tamanho)
    {
        ERROR_LINHA("Tamanhos diferentes");
        return resposta;
    }
}