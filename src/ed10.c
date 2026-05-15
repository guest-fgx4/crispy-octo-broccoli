#include<stdio.h>
#include<AEDI/arranjo.h>
#include<AEDI/file.h>
#include<AEDI/utils.h>

void metodo_011()
{
    int limiteInf = 0;
    int limiteSup = 0;
    int quantidade = 0;

    limiteInf = lerIntTeclado("Inserir o limite Inferior: ");
    limiteSup = lerIntTeclado("Inserir o limite Supeior: ");
    quantidade = lerIntTeclado("Inserir a quantidade: ");

    Arranjo* arranjo = criarArranjo(quantidade, INTEIRO);
    preencherArranjoAleatorio(arranjo, limiteInf, limiteSup);

    Arquivo* arquivo = abrirArquivo("dados.txt", ESCREVER);
    gravarArranjoArquivo(arranjo, "dados.txt");

    fecharDesalocar(arquivo);
    // free(arranjo);
}

void metodo_012()
{
}


void metodo_013()
{
}

void metodo_014()
{
}

void metodo_015()
{
}

void metodo_016()
{
}

void metodo_017()
{
}

void metodo_018()
{
}

void metodo_019()
{
}

void metodo_020()
{
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
