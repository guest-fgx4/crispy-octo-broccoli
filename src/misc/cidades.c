#include<stdio.h>


int main()
{
    const int tamMax = 100;
    char cidades[tamMax];
    int endedloop = 0;
    int contador = 0;

    while (!endedloop)
    {
        fgets(cidades, tamMax, stdin);
        
        if (cidades[0] == 'F' && cidades[1] == 'I' && cidades[2] == 'M' && cidades[3] == '\n')
        {
            endedloop = 1;
        }
        else
        {
            for(int i = 0; i < tamMax && cidades[i] != '\n'; contador++, i++);

            printf("%d\n", contador);
            contador = 0;
        }
    }

    return 0;
}
