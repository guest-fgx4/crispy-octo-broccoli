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
			int resp = 1;
            while (inversao[i] != ' ' && resp)
            {
				if (inversao[i] >= 'A' && inversao[i] <= 'Z')
				{
					inversao[i] = (inversao[i] + '\40');
				}
				resp = 0;
				while (inversao[j] != ' ')
				{
					if (inversao[j] >= 'A' && inversao[j] <= 'Z')
					{
							inversao[j] = (inversao[j] +'\40');
					}
					if (inversao[j] == inversao[i])
					{
						resp = 1;
					}
                	j--;
				} 

                i++;
				j = index - 1;
            }

			if (resp)
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
