#include<stdio.h>
#include<stdlib.h>

#define STR_SIZE 20



void metodo_0411()
{
  printf("Metodo 0411\n");

  // Ler dois valores reais para o intervalo
  double limiteInferior = 0.0;
  double limiteSuperior = 0.0;

  int quantidade = 0;

  printf("Inserir numero para o limite inferior: \n");
  scanf("%lf", &limiteInferior);
  getchar();

  printf("Inserir numero para o limite Superior: \n");
  scanf("%lf", &limiteSuperior);
  getchar();

  if (limiteInferior > limiteSuperior)
  {
    printf("Intervalo invalido! Limite inferior maior que o limite Superior!: \n");
    return;

  }

  printf("Inserir quantidade de numeros: \n");
  scanf("%d", &quantidade);
  getchar();

  if ((quantidade < 0) || (quantidade > 20))
  {
    printf("quantidade precisa ser positiva e menor que 20!: \n");
    return;

  }
 
  //inicializar o arranjo
  double *dados = (double *)calloc(quantidade, sizeof(double));
  
  for (int x = 0; x < quantidade; x++)
  {
    printf("Inserir numero: \n");
    scanf("%lf", &dados[x]);
  }


  int quantidadeDentro = 0;
  int qantidadeFora = 0;
  
  for (int x = 0; x < quantidade; x++)
  {
    if ((dados[x] >= limiteInferior) && (dados[x] <= limiteSuperior))
    {
      quantidadeDentro++;
    }
    else 
    {
      qantidadeFora++;
    }
  }

  printf("Quanttidade dentro do intervalo: %d\n", quantidadeDentro);
  printf("Quanttidade fore do intervalo: %d\n", qantidadeFora);

  free(dados);
}

void contarLetras(const char* string)
{

  int contador = 0;

  for(int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if ( (string[x] > 'k') && (string[x] < 'p'))
    {
      contador++;
    }
  }

  printf("A palavra inserida tem %d letras entre k e p\n", contador);
}

void metodo_0412()
{
  printf("Metodo 0412\n");


  char * string = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  contarLetras(string);

  free(string);
  
}

int main (void)
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
            metodo_0411();
            break;
        case 2:
            metodo_0412();
            break;
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
