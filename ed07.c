#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void metodo_011()
{
    int quantidade = 0;
    FILE * arquivo = fopen("metodo_01.txt", "wt");

    
    printf ("Entrar quantidade: ");
    scanf("%d", &quantidade); getchar();
    printf("\n");

    for( int i = 1; i <= quantidade; i++)
    {
        fprintf(arquivo, "%d\n", (2*i-1)*5);
    }

    fclose(arquivo);

}

void metodo_012()
{
    int quantidade = 0;
    int valor = 0;
    FILE * arquivo = fopen("metodo_02.txt", "wt");

    
    printf ("Entrar quantidade: ");
    scanf("%d", &quantidade); getchar();
    printf("\n");

    for(int i = 1; i <= quantidade; i++)
    {
        valor = (2*i)*3;
    }

    while(valor >= 6)
    {
        fprintf(arquivo, "%d\n", valor);
        valor = valor - 6;
    }

    fclose(arquivo);

}

void metodo_013()
{
    int quantidade = 0;
    int expo = 1;
    FILE * arquivo = fopen("metodo_03.txt", "wt");

    printf ("Entrar quantidade: ");
    scanf("%d", &quantidade); getchar();
    printf("\n");

    fprintf(arquivo, "%d\n", 1);


    for(int i = 1; i < quantidade; i++)
    {
        expo = expo * 3;
        fprintf(arquivo, "%d\n", expo);
    }

    fclose(arquivo);

}

void metodo_014()
{
    int quantidade = 0;
    int valor = 1;
    FILE * arquivo = fopen("metodo_04.txt", "wt");

    
    printf ("Entrar quantidade: ");
    scanf("%d", &quantidade); getchar();
    printf("\n");

    for(int i = 1; i < quantidade; i++)
    {
        valor = valor * 5;
    }

    while(valor != 1)
    {
        fprintf(arquivo, "1/%d\n", valor);
        valor = valor / 5;
    }

    fprintf(arquivo, "%d\n", valor);
    fclose(arquivo);

}

void metodo_015()
{
    int quantidade = 0;
    int valor = 0;
    FILE * arquivo = fopen("metodo_05.txt", "wt");

    
    printf ("Entrar quantidade: ");
    scanf("%d", &quantidade); getchar();
    printf("\n");

    printf ("Entrar Numero: ");
    scanf("%d", &valor); getchar();
    printf("\n");

    fprintf(arquivo, "%d\n", 1);

    for(int i = 2; i <= quantidade; i++)
    {
       // fprintf(arquivo, "%lf\n", 1/pow(valor,(2*i-1));
       fprintf(arquivo, "1\%d^%d\n", valor, (2*i-1));
    }

    fclose(arquivo);

}



int main()
{

    metodo_015();
    return 0;
}
