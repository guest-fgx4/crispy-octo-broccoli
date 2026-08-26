#include<stdio.h>


int main()
{
    int quant = 0;
    int n = 0;
    scanf("%d", &quant);

    for(int i = 0; i < quant; i++)
    {
        scanf("%d", &n);
        if ( n % 2 == 0)
        {
            printf("PAR\n");
        }
        else
        {
            printf("IMPAR\n");
        }
    }
    return 0;
}
