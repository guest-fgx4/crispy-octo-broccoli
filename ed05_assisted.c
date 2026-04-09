#include <stdio.h>
#include <math.h>

// Funcao 0511: Gerar multiplos de 3
void gerar_multiplos_3(int n)
{
    printf("Multiplos de 3: { ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d", i * 3);
        if (i < n) printf(", ");
    }
    printf(" }\n");
}

void metodo_0511(void)
{
    int n;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    gerar_multiplos_3(n);
}

// Funcao 0512: Gerar multiplos de 3 e 5
void gerar_multiplos_3_5(int n)
{
    printf("Multiplos de 3 e 5: { ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d", i * 15);
        if (i < n) printf(", ");
    }
    printf(" }\n");
}

void metodo_0512(void)
{
    int n;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    gerar_multiplos_3_5(n);
}

// Funcao 0513: Gerar potencias de 3 em ordem decrescente
void gerar_potencias_3(int n)
{
    printf("Potencias de 3 (decrescente): { ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d", (int)pow(3, i));
        if (i > 0) printf(", ");
    }
    printf(" }\n");
}

void metodo_0513(void)
{
    int n;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    gerar_potencias_3(n);
}

// Funcao 0514: Gerar sequencia de inversos com denominadores multiplos de 3
void gerar_inversos_multiplos_3(int n)
{
    printf("Sequencia de inversos (denominadores multiplos de 3): { ");
    for (int i = 1; i <= n; i++)
    {
        printf("1/%d", i * 3);
        if (i < n) printf(", ");
    }
    printf(" }\n");
}

void metodo_0514(void)
{
    int n;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    gerar_inversos_multiplos_3(n);
}

// Funcao 0515: Gerar sequencia de inversos com potencias pares de x nos denominadores
void gerar_inversos_potencias_x(double x, int n)
{
    printf("Sequencia de inversos (potencias de x): { ");
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            printf("1");
        else
            printf("1/x%d", i * 2);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

void metodo_0515(void)
{
    double x;
    int n;
    printf("Digite um valor real (x): ");
    scanf("%lf", &x);
    printf("Digite uma quantidade inteira: ");
    scanf("%d", &n);
    gerar_inversos_potencias_x(x, n);
}

// Funcao 0516: Calcular soma de multiplos de 3 (nao multiplos de 5)
double soma_multiplos_3(int n)
{
    double soma = 0;
    int cont = 0;
    int multiplo = 3;
    
    while (cont < n)
    {
        if (multiplo % 5 != 0)
        {
            soma += multiplo;
            cont++;
        }
        multiplo += 3;
    }
    
    return soma;
}

void metodo_0516(void)
{
    int n;
    printf("Digite quantidade de valores: ");
    scanf("%d", &n);
    double resultado = soma_multiplos_3(n);
    printf("Soma dos primeiros %d multiplos de 3 (nao multiplos de 5): %.0f\n", n, resultado);
}

// Funcao 0517: Calcular soma de inversos de multiplos de 4 (nao multiplos de 5)
double soma_inversos_multiplos_4(int n)
{
    double soma = 0;
    int cont = 0;
    int multiplo = 4;
    
    while (cont < n)
    {
        if (multiplo % 5 != 0)
        {
            soma += 1.0 / multiplo;
            cont++;
        }
        multiplo += 4;
    }
    
    return soma;
}

void metodo_0517(void)
{
    int n;
    printf("Digite quantidade de valores: ");
    scanf("%d", &n);
    double resultado = soma_inversos_multiplos_4(n);
    printf("Soma de inversos dos primeiros %d multiplos de 4 (nao multiplos de 5): %.6f\n", n, resultado);
}

// Funcao 0518: Calcular soma de numeros naturais incrementais comecando em 5
double soma_incremento_5(int n)
{
    double soma = 0;
    int valor = 5;
    int incremento = 1;
    
    for (int i = 0; i < n; i++)
    {
        soma += valor;
        incremento++;
        valor += incremento;
    }
    
    return soma;
}

void metodo_0518(void)
{
    int n;
    printf("Digite quantidade de valores: ");
    scanf("%d", &n);
    double resultado = soma_incremento_5(n);
    printf("Soma de valores incrementais comecando em 5: %.0f\n", resultado);
}

// Funcao 0519: Calcular soma de quadrados de numeros naturais comecando em 9
double soma_quadrados_9(int n)
{
    double soma = 0;
    int valor = 9;
    
    for (int i = 0; i < n; i++)
    {
        soma += valor * valor;
        valor++;
    }
    
    return soma;
}

void metodo_0519(void)
{
    int n;
    printf("Digite quantidade de valores: ");
    scanf("%d", &n);
    double resultado = soma_quadrados_9(n);
    printf("Soma de quadrados comecando em 9: %.0f\n", resultado);
}

// Funcao 0520: Calcular soma de inversos de somas cumulativas terminando em 3
double soma_inversos_cumulativos(int n)
{
    double soma = 0;
    int cumulativo = 3;
    
    for (int i = 0; i < n; i++)
    {
        soma += 1.0 / cumulativo;
        cumulativo += (2 + i);
    }
    
    return soma;
}

void metodo_0520(void)
{
    int n;
    printf("Digite quantidade de valores: ");
    scanf("%d", &n);
    double resultado = soma_inversos_cumulativos(n);
    printf("Soma de inversos de somas cumulativas: %.6f\n", resultado);
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
      metodo_0511();
      break;
    case 2:
      metodo_0512();
      break;
    case 3:
      metodo_0513();
      break;
    case 4:
      metodo_0514();
      break;
    case 5:
      metodo_0515();
      break;
    case 6:
      metodo_0516();
      break;
    case 7:
      metodo_0517();
      break;
    case 8:
      metodo_0518();
      break;
    case 9:
      metodo_0519();
      break;
    case 10:
      metodo_0520();
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

