#include<stdio.h>


int main()
{
    const int tamMax = 1000;
    char palindromo[tamMax];
    int endedloop = 0;

    while (!endedloop)
    {
        fgets(palindromo, tamMax, stdin);
        
        if (palindromo[0] == 'F' && palindromo[1] == 'I' && palindromo[2] == 'M' && palindromo[3] == '\n')
        {
            endedloop = 1;
        }
        else
        {
            int index = 0;
            for(int x = 0; x < tamMax && palindromo[x] != '\n'; x++, index = x);

            int i = 0;
            int j = index - 1;
            int loop = 1;

            while (loop && i < j)
            {
                loop = loop && (palindromo[i] == palindromo[j]);
                i++;
                j--;
            }

            if (loop)
            {
                printf("SIM\n");
            }
            else
            {
                printf("NAO\n");
            }
        }
    }

    return 0;
}
