#include<stdio.h>


void cifraFn(char offset, char *array, int index)
{
    if(array[index] != '\n')
    {
        array[index] = array[index] + offset;
        cifraFn(offset, array, index + 1);
    }
    
}


int main()
{
    const int tamMax = 1000;
    char cifra[tamMax];
    int endedloop = 0;

    while (!endedloop)
    {
        fgets(cifra, tamMax, stdin);
        
        if (cifra[0] == 'F' && cifra[1] == 'I' && cifra[2] == 'M' && ( cifra[3] == '\n'|| cifra[3] == '\0'))
        {
            endedloop = 1;
        }
        else
        {
            const char offset = '\3';

            cifraFn(offset, cifra, 0);

            printf("%s", cifra);
        } 
    }

    return 0;
}
