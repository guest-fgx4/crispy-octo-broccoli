#include<stdio.h>
#include<AEDI/matriz.h>
#include<AEDI/file.h>


void metodo_011()
{
    printf("Metodo 01\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    mostrarMatriz(matriz);

    desalocarMatriz(matriz);
}

void metodo_012()
{
    printf("Metodo 02\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Antes de gravar em arquivo\n");
    mostrarMatriz(matriz);

    gravarMatrizArquivo(matriz, "dadosMatriz.txt");
    matriz = (Matriz*) buscarMatrizArquivo("dadosMatriz.txt");

    printf("Depois de gravar em arquivo\n");
    mostrarMatriz(matriz);

    desalocarMatriz(matriz);
}


void metodo_013()
{
    printf("Metodo 03\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, DIAGONAL_PRINCIPAL);
    
    desalocarMatriz(matriz);
}

void metodo_014()
{
    printf("Metodo 04\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, DIAGONAL_SECUNDARIA);

    desalocarMatriz(matriz);
}

void metodo_015()
{
    printf("Metodo 05\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, TRIANGULO_INFERIOR_PRINCIPAL);

    desalocarMatriz(matriz);
}

void metodo_016()
{
    printf("Metodo 06\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, TRIANGULO_SUPERIOR_PRINCIPAL);

    desalocarMatriz(matriz);
}

void metodo_017()
{
    printf("Metodo 07\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, TRIANGULO_INFERIOR_SECUNDARIA);

    desalocarMatriz(matriz);
}

void metodo_018()
{
    printf("Metodo 08\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    printf("\nMatriz resultade da funcao: \n");
    mostrarMatrizFuncao(matriz, TRIANGULO_SUPERIOR_SECUNDARIA);

    desalocarMatriz(matriz);
}

void metodo_019()
{
    printf("Metodo 09\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);

    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    if (matrizZeroFuncao(matriz, TRIANGULO_INFERIOR_PRINCIPAL))
    {
        printf("valores abaixo da diagonal principal igual a zero!\n");
    }
    else
    {
        printf("valores abaixo da diagonal principal nao igual a zero!\n");
    }

    desalocarMatriz(matriz);
}

void metodo_020()
{
    printf("Metodo 10\n");

    Matriz* matriz = (Matriz*) lerMatirzTeclado(2,2, mDOUBLE);


    printf("Matriz lida do teclado: \n");
    mostrarMatriz(matriz);

    // printf("Chegou aqui");

    if (matrizZeroFuncao(matriz, TRIANGULO_SUPERIOR_PRINCIPAL))
    {
        printf("valores acima da diagonal principal igual a zero!\n");
    }
    else
    {
        printf("valores acima da diagonal principal nao igual a zero!\n");
    }

    desalocarMatriz(matriz);
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
    case 3:
      metodo_013();
      break;
    case 4:
      metodo_014();
      break;
    case 5:
      metodo_015();
      break;
    case 6:
      metodo_016();
      break;
    case 7:
      metodo_017();
      break;
    case 8:
      metodo_018();
      break;
    case 9:
      metodo_019();
      break;
    case 10:
      metodo_020();
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
