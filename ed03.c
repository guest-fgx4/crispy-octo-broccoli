#include<stdio.h>
#include<stdlib.h>

#define SENTA_E_CHORA() printf("%s%d", "Erro na linha: ", __LINE__);
#define STR_LENGTH  40


void methodo_0311()
{
    printf("Metodo 0331\n");

    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        SENTA_E_CHORA()
        return;
    }

    printf("Digitar uma palavra: ");
    scanf("%s", &string[0]);
    // getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
        }
        index++;
    }
    

    free(string);
}


void methodo_0312()
{
    printf("Metodo 031g2\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        SENTA_E_CHORA()
        return;
    }

    printf("Digitar uma palavra: ");
    scanf("%s", &string[0]);
    // getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            quantidade++;
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }
        index++;
    }
    

    free(string);
}

void methodo_0313()
{
    printf("Metodo 0313\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        SENTA_E_CHORA()
        return;
    }

    printf("Digitar uma palavra: ");
    scanf("%s", &string[0]);
    // getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;

    for(; string[index] != '\0'; index++);

    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            quantidade++;
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }
        index++;
    }
    

    free(string);
}



int main (void)
{

    methodo_0313();

    return 0;
}