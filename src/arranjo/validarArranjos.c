#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include "validarArranjos.h"

// TODO: depois olhar a comparacao por tipos
int validar_arranjosDiferentes(Arranjo* arranjo1, Arranjo* arranjo2)
{
    if (arranjo1 == NULL || arranjo2 == NULL)
    {
        ERROR_LINHA("Arranjo nullo");
        return 1;
    }
    else if (arranjo1->tamanho != arranjo2->tamanho)
    {
        ERROR_LINHA("Tamanhos diferentes");
        return 1;
    }
    if (arranjo1->tamanho < 0 || arranjo2-> tamanho < 0)
    {
        ERROR_LINHA("Arranjo com tamanho invalido");
        return 1;
    }

    return 0;
}

int validar_arranjo(Arranjo* arranjo)
{
    if (arranjo == NULL || arranjo->array == NULL || arranjo->tamanho < 0)
    {
        ERROR_LINHA("Arranjo nullo");
        return 1;
    }

    return 0;
}