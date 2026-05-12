#include<AEDI/utils.h>
#include<stdlib.h>
#include<stdio.h>

int randIntIntervalo(int limiteInf, int limiteSup)
{
    int resposta = 0;

    if (limiteInf > limiteSup)
    {
        resposta = -1;
        return resposta;
        printf("Limite inferior maior que superior\n");
        // TODO: Olhar como fazer o error handling better
    }

    resposta = (Rand() % limiteSup) + 1;

    if (resposta < limiteInf)
    {
        resposta = resposta + (limiteInf - resposta);
    }

    return resposta;
}
