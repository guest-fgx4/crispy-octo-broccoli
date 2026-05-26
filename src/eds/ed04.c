#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 20

typedef enum Bool
{
  FALSE = 0,
  TRUE
} MyBool;

char *lerCadeiaTeclado()
{
  char *cadeia = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters (Max 20 characters): \n");
  scanf("%s", cadeia);
  getchar();

  return cadeia;
}

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

  // inicializar o arranjo
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

void contarLetras(const char *string)
{
  int contador = 0;

  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if ((string[x] > 'k') && (string[x] < 'p'))
    {
      contador++;
      printf("%c ,", string[x]);
    }
  }
  printf("\n");
  printf("A palavra inserida tem %d letras entre k e p\n", contador);
}

MyBool testarLetraLimite(const char letra, const char inferior, const char superior)
{
  MyBool resposta = FALSE;

  if ((letra > inferior) && (letra < superior))
  {
    resposta = TRUE;
  }

  return resposta;
}

void metodo_0412()
{
  printf("Metodo 0412\n");

  char *string = (char *)calloc(STR_SIZE, sizeof(char));
  int contador = 0;

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (testarLetraLimite(string[x], 'k', 'p'))
    {
      contador++;
      printf("%c ,", string[x]);
    }
  }
  printf("\n");
  printf("A palavra inserida tem %d letras entre k e p\n", contador);
  free(string);
}

void metodo_0413()
{
  printf("Metodo 0413\n");

  char *string = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  contarLetras(string);

  free(string);
}

void contarLetrasArray(const char *string)
{
  int contador = 0;

  char *newString = (char *)calloc(strlen(string), sizeof(char));
  newString[0] = '\0';

  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (testarLetraLimite(string[x], 'k', 'p'))
    {
      contador++;
      const char aux[2] = {string[x], '\0'};
      strcat(newString, aux);
    }
  }

  int index = 0;

  printf("Simbolos identificados: [");

  while (newString[index] != '\0')
  {
    printf("%c ", newString[index]);
    index++;
  }

  printf("]\n");

  printf("A palavra inserida tem %d letras entre k e p\n", contador);

  free(newString);
}

void metodo_0414()
{
  printf("Metodo 0414\n");

  char *string = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  contarLetrasArray(string);

  free(string);
}

void contarLetras2(const char *string)
{
  int contador = 0;

  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (testarLetraLimite(string[x], 'k', 'p') || testarLetraLimite(string[x], 'K', 'P'))
    {
      contador++;
    }
  }
  printf("A palavra inserida tem %d letras entre (k, p) e (K,P)\n", contador);
}

void metodo_0415()
{
  printf("Metodo 0415\n");

  char *string = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  contarLetras2(string);

  free(string);
}

void contarLetras_416(const char *string)
{
  int contador = 0;

  printf("[ ");
  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (testarLetraLimite(string[x], 'k', 'p') || testarLetraLimite(string[x], 'K', 'P'))
    {
      contador++;
      printf("%c ", string[x]);
    }
  }

  printf("]\n");
  printf("A palavra inserida tem %d letras entre k e p\n", contador);
}

void metodo_0416()
{
  printf("Metodo 0416\n");

  char *string = (char *)calloc(STR_SIZE, sizeof(char));

  printf("Entre com uma cadeia de characters: \n");
  scanf("%s", string);
  getchar();

  contarLetras_416(string);

  free(string);
}

void contarDigitos(const char *string)
{
  int contador = 0;

  printf("[ ");
  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (testarLetraLimite(string[x], '0', '9') && ((int)string[x] % 2 != 0))
    {
      contador++;
      printf("%c ", string[x]);
    }
  }

  printf("]\n");
  printf("A palavra inserida tem %d digitos impares\n", contador);
}

void metodo_0417()
{
  printf("Metodo 0417\n");

  char *string = lerCadeiaTeclado();

  contarDigitos(string);

  free(string);
}

int verficarAlfanumerico(const char x)
{
  int resposta = 0;

  if (
      testarLetraLimite(x, '/', ':') || // Intervalo [0:9]
      testarLetraLimite(x, '`', '{') || // Intervalo [a:z]
      testarLetraLimite(x, '@', '[')    // Intervalo [A:Z]
    )
    {
      resposta = 1;
    }

  return resposta;
}


void contarNaoAlfanumericos(const char *string)
{
  int contador = 0;

  printf("[ ");
  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (!verficarAlfanumerico(string[x]))
    {
      contador++;
      printf("%c ", string[x]);
    }
  }

  printf("]\n");
  printf("A palavra inserida tem %d characaters nao alfanumerias\n", contador);
}

void metodo_0418()
{
  printf("Metodo 0418\n");

  char *string = lerCadeiaTeclado();

  contarNaoAlfanumericos(string);

  free(string);
}

void contarAlfanumericos(const char *string)
{
  int contador = 0;

  printf("[ ");
  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (verficarAlfanumerico(string[x]))
    {
      contador++;
      printf("%c ", string[x]);
    }
  }

  
  printf("]\n");
  printf("A palavra inserida tem %d letras alfanumerias\n", contador);
}

void contarAlfa(const char *string, int *contador)
{
  int contadorLocal = 0;

  printf("[ ");
  for (int x = 0; (string[x] != '\0') && (x < STR_SIZE); x++)
  {
    if (verficarAlfanumerico(string[x]))
    {
      (*contador)++;
      contadorLocal++;
      printf("%c ", string[x]);
    }
  }

  
  printf("]\n");
  printf("A palavra inserida tem %d letras alfanumerias\n", contadorLocal);
}


void metodo_0419()
{
  printf("Metodo 0419\n");

  char *string = lerCadeiaTeclado();

  contarAlfanumericos(string);

  free(string);
}



void metodo_0420()
{
  printf("Metodo 0420\n");

  int quantidade = 0;
  int contador = 0;

  printf("Indique a quantidade de cadeias: \n");
  scanf("%d", &quantidade);
  getchar();

  char **matrixString = (char**)calloc(quantidade, sizeof(char *));

  for (size_t i = 0; i < quantidade; i++)
  {
    matrixString[i] = lerCadeiaTeclado();
  }
  
  for (size_t i = 0; i < quantidade; i++)
  {
    contarAlfa(matrixString[i], &contador);
  }
  

  for (size_t i = 0; i < quantidade; i++)
  {
    free(matrixString[i]);
  }

  free(matrixString);

  printf("Total de caracters alfanumericos: %d\n", contador);
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
      metodo_0411();
      break;
    case 2:
      metodo_0412();
      break;
    case 3:
      metodo_0413();
      break;
    case 4:
      metodo_0414();
      break;
    case 5:
      metodo_0415();
      break;
    case 6:
      metodo_0416();
      break;
    case 7:
      metodo_0417();
      break;
    case 8:
      metodo_0418();
      break;
    case 9:
      metodo_0419();
      break;
    case 10:
      metodo_0420();
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
