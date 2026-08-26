#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<AEDI/utils.h>
int lerIntTeclado(const char* string)
{
    int valor = 0;

    printf("%s\n",string);
    scanf("%d", &valor); getchar();

    return valor;
}

char* lerLinhaTeclado(const char* string)
{
    char* linha;

    printf("%s\n",string);
    fgets(linha, 80, stdin);

    return linha;
}

// void* lerDadoTeclado()
// {
//     void* dado = 0;

//     printf("%s\n",string);
//     scanf("%d", &valor); getchar();

//     return linha;
// }

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

    resposta = (rand() % limiteSup) + 1;

    if (resposta < limiteInf)
    {
        resposta = resposta + (limiteInf - resposta);
    }

    return resposta;
}

char* concatString(char* string1, char* string2)
{   
    return strncat(string1, string2, strlen(string2));
}

//extern "C" int sum(int x, int y)
int sum(int x, int y)
{
    return x + y;
}
