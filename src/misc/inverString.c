#include<stdio.h>


int main()
{
    const int tamMax = 1000;
    char inversao[tamMax];
    int endedloop = 0;

    while (!endedloop)
    {
        fgets(inversao, tamMax, stdin);
        
        if (inversao[0] == 'F' && inversao[1] == 'I' && inversao[2] == 'M' && ( inversao[3] == '\n'|| inversao[3] == '\0'))
        {
            endedloop = 1;
        }
        else
        {
            int index = 0;
            for(int x = 0; x < tamMax && inversao[x] != '\n'; x++, index = x);

            int i = 0;
            int j = index - 1;
            char aux = ' ';
            while (i < j)
            {
                aux = inversao[i];
                inversao[i] = inversao[j];
                inversao[j] = aux;
                i++;
                j--;
            }

            printf("%s", inversao);
        }
    }

    return 0;
}
