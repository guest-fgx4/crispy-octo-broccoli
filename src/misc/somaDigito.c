#include<stdio.h>


int main()
{
    int endedloop = 0;
    int long numero = 0;

    while (!endedloop)
    {
        scanf("%ld", &numero);
        
        if (numero <= 0)
        {
            endedloop = 1;
        }
        else
        {
            int soma = 0;
            while (numero > 0)
            {
                soma = soma + (numero % 10);
                numero = numero / 10;
            }

            printf("%d\n", soma);
        }
    }

    return 0;
}
