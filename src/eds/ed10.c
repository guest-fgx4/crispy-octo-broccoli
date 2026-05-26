#include<stdio.h>
#include<stdlib.h>

#include<AEDI/arranjo.h>
#include<AEDI/file.h>
#include<AEDI/utils.h>
#include<AEDI/matriz.h>

void metodo_011()
{
    printf("Metodo 01\n");

    int limiteInf = 0;
    int limiteSup = 0;
    int quantidade = 0;

    limiteInf = lerIntTeclado("Inserir o limite Inferior: ");
    limiteSup = lerIntTeclado("Inserir o limite Supeior: ");
    quantidade = lerIntTeclado("Inserir a quantidade: ");



    Arranjo* arranjo = criarArranjo(quantidade, aINTEIRO);
    preencherArranjoAleatorio(arranjo, limiteInf, limiteSup);

    Arquivo* arquivo = abrirArquivo("dados.txt", ESCREVER);
    gravarArranjoArquivo(arranjo, "dados.txt");

    fecharDesalocar(arquivo);
    free(arranjo);
}

void metodo_012()
{
    printf("Metodo 02\n");

    int valor = 0;

    Arranjo* arranjo = buscarArranjoArquivo("dados.txt");

    valor = lerIntTeclado("Indique o valor a ser procurado: ");

    if (buscarIntArranjo(arranjo, valor))
    {
        printf("Valor achado!\n");
    }
    else
    {
        printf("Valor nao achado\n");
    }

    free(arranjo);
}


void metodo_013()
{
    printf("Metodo 03\n");

    // TODO: parametrizar o nome do arquivo a ser procurado
    Arranjo* arranjo1 = buscarArranjoArquivo("dados.txt");
    Arranjo* arranjo2 = buscarArranjoArquivo("dados.txt");

    if (comprarArranjos(arranjo1, arranjo2))
    {
        printf("Arranjos iguals!\n");
    }
    else
    {
        printf("Arranjos nao iguals!\n");
    }

    free(arranjo1);
    free(arranjo2);
}

void metodo_014()
{
    printf("Metodo 04\n");

    Arranjo* arranjo1 = buscarArranjoArquivo("dados.txt");
    Arranjo* arranjo2 = buscarArranjoArquivo("dados.txt");

    int soma = somarArranjo(arranjo1, 2, arranjo2);

    printf("Valor da soma dos arranjos 1 e 2: %d", soma);

    free(arranjo1);
    free(arranjo2);
}

void metodo_015()
{
    printf("Metodo 05\n");

    Arranjo* arranjo = buscarArranjoArquivo("dados.txt");

    if (estaDecrescente(arranjo))
    {
        printf("Arranjo esta ordenado de forma decrescente!\n");
    }
    else
    {
        printf("Arranjo nao esta ordenado de forma decrescente!\n");
    }

    free(arranjo);
}

void metodo_016()
{
    printf("Metodo 06\n");

    Matriz* matriz = (Matriz*) buscarMatrizArquivo("dados.txt");

    if (matriz != NULL)
    {
        mostrarMatriz(matriz);
        Matriz* matriz_t = transporMatriz(matriz);
        printf("\n");
        mostrarMatriz(matriz_t);

        desalocarMatriz(matriz);
        desalocarMatriz(matriz_t);
    }
}

void metodo_017()
{
    printf("Metodo 07\n");

    Matriz* matriz = (Matriz*) buscarMatrizArquivo("dados.txt");

    if (matriz != NULL)
    {
        if (matrizZero(matriz))
        {
            printf("Matriz so tem valores igual a 0\n");
        }
        else
        {
            printf("Matriz nao somente tem valores igual a 0\n");
        }

        desalocarMatriz(matriz);
    }
}

void metodo_018()
{
    printf("Metodo 08\n");

    Matriz* matriz1 = (Matriz*) buscarMatrizArquivo("dados.txt");
    Matriz* matriz2 = (Matriz*) buscarMatrizArquivo("dados.txt");

    if (matriz1 && matriz2)
    {
        if(compararMatriz(matriz1, matriz2))
        {
            printf("Matriz iguais!\n");
        }
        else
        {
            printf("Matriz nao iguais!\n");
        }
    }

    desalocarMatriz(matriz1);
    desalocarMatriz(matriz2);
}

void metodo_019()
{
    printf("Metodo 09\n");

    Matriz* matriz1 = (Matriz*) buscarMatrizArquivo("dados.txt");
    Matriz* matriz2 = (Matriz*) buscarMatrizArquivo("dados.txt");

    if (matriz1 && matriz2)
    {
        printf("Valor total da adicao entre matriz1 e matriz2: %d\n", somarConstanteMatriz(matriz1, -1, matriz2));
    }

    desalocarMatriz(matriz1);
    desalocarMatriz(matriz2);
}

void metodo_020()
{
    printf("Metodo 10\n");

    Matriz* matriz1 = (Matriz*) buscarMatrizArquivo("dados.txt");
    Matriz* matriz2 = (Matriz*) buscarMatrizArquivo("dados.txt");

    mostrarMatriz(matriz1);
    mostrarMatriz(matriz2);

    Matriz* produto = (Matriz*) produtoMatriz(matriz1, matriz2);

    if (produto)
    {
        mostrarMatriz(produto);
    }

    desalocarMatriz(matriz1);
    desalocarMatriz(matriz2);
    desalocarMatriz(produto);
}


int main(void)
{
  int opcao = 0;

  printf("Metodo Main\n");

  do
  {
    printf("Entrar com opcao para selecionar metodo (1-10)\n");

    scanf("%d", &opcao); 
    // getchar();

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
