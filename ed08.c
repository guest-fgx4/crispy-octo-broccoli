#include<stdio.h>
#include<stdlib.h>

void metodo_011()
{
    int tamanho = 0;
    int contador = 0;
    
    printf ("Inserir quantidade do teclado ");
    scanf("%d", &tamanho); getchar();

    if (tamanho < 0)
    {
        printf("Valor para tamanho invalido");
        return;
    }

    int arranjo[tamanho];

    while(contador < tamanho)
    {
        printf ("\nInserir valor do elemento: ");
        scanf("%d", &arranjo[contador]); getchar();

        if ( arranjo[contador] < 0 || arranjo[contador] % 2 != 0)
        {
            printf("Valor invalido, insira um valor nao nulo e par\n");
        }
        else
        {
            contador++;
        }
    }

    for(int i = 0; i < tamanho; i++)
    {
        printf("Valor do arranjo na posicao %d: [%d]\n", i, arranjo[i]);
    }
}

void metodo_012()
{
    FILE * arquivo = fopen("ed08_data_2.data", "rt");
    const char * arquivoNovo = "ed08_metodo2.txt";
    int quantidade = 0;

    int arranjo[80] = {};

    int contador = 0;
    int numeroAtual = 0;
    while(!feof(arquivo) && contador < 80)
    {
        fscanf(arquivo, "%d", &numeroAtual);

        if (numeroAtual < 0 || numeroAtual % 2 != 0) continue;

        arranjo[contador] = numeroAtual;
        contador++;
    }

    FILE * gravar = fopen(arquivoNovo, "wt");

    fprintf(gravar, "%d\n", contador);

    for(int i = 0; i < contador; i++)
    {
        fprintf(gravar, "%d\n", arranjo[i]);
    }

    printf("Valor total do arranjo: %d", contador);

    for(int i = 0; i < contador; i++)
    {
        printf("Valor do arranjo na posicao %d: [%d]\n", i, arranjo[i]);
    }
    
    fclose(arquivo);
    fclose(gravar);
}

int main(void)
{
  int opcao = 0;

  printf("Metodo Main\n");

  do
  {
    printf("Entrar com opcao para selecionar metodo (1-10)\n");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      metodo_011();
      break;
    case 2:
      metodo_012();
      break;
   // case 3:
   //   metodo_013();
   //   break;
   // case 4:
   //   metodo_014();
   //   break;
   // case 5:
   //   metodo_015();
   //   break;
   // case 6:
   //   metodo_016();
   //   break;
   // case 7:
   //   metodo_017();
   //   break;
   // case 8:
   //   metodo_018();
   //   break;
   // case 9:
   //   metodo_019();
   //   break;
   // case 10:
   //   metodo_020();
   //   break;
    default:
      printf("%s\n", "Metodo invalido, Selecionar metodos de 1 ate 10");
      printf("%s\n", "Ou pressione 0 para sair");
      break;
    }
  } while (opcao != 0);

  printf("Apertar ENTER para sair do programa main.");
  getchar();
  return 0;
}
