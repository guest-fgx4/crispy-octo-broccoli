#include<AEDI/arranjo.h>
#include<AEDI/utils.h>
#include "validarArranjos.h"

// TODO: depois olhar a comparacao por tipos
short validar_arranjosDiferentes(Arranjo* arranjo1, Arranjo* arranjo2)
{
    short erro = 0;

    if (arranjo1 == NULL || arranjo2 == NULL)
    {
        ERROR_LINHA("Arranjo nullo");
        erro = 1;
    }
    else if (arranjo1->tamanho != arranjo2->tamanho)
    {
        ERROR_LINHA("Tamanhos diferentes");
        erro = 1;
    }
    else if (arranjo1->tamanho < 0 || arranjo2-> tamanho < 0)
    {
        ERROR_LINHA("Arranjo com tamanho invalido");
        erro = 1;
    }

    return erro;
}

short validar_arranjo(Arranjo* arranjo)
{
    short erro = 0;

    if (arranjo == NULL || arranjo->array == NULL || arranjo->tamanho < 0)
    {
        ERROR_LINHA("Arranjo nullo");
        erro = 1;
    }

    return erro;
}