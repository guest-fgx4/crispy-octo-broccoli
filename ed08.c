#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


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

void gravarParesPositivos(int n, int* arranjo)
{ 
    const char * arquivoNovo = "ed08_metodo2.txt";
    FILE * gravar = fopen(arquivoNovo, "wt");

    fprintf(gravar, "%d\n", n);

    for(int i = 0; i < n; i++)
    {
        fprintf(gravar, "%d\n", arranjo[i]);
    }

    printf("Valor total do arranjo: %d", n);

    for(int i = 0; i < n; i++)
    {
        printf("Valor do arranjo na posicao %d: [%d]\n", i, arranjo[i]);
    }

    fclose(gravar);
}


void metodo_012()
{
    FILE * arquivo = fopen("ed08_data_2.data", "rt");
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

    gravarParesPositivos(quantidade, arranjo);

    fclose(arquivo);
}

int gerarInt(int limiteInferior, int limiteSuperior)
{
    int random = rand();
    random = random % (limiteSuperior - 1);
    return (random < limiteInferior)? random + limiteInferior : random;
}

void metodo_013()
{
    int limiteInf = 0;
    int limiteSup = 0;
    int quantidade = 0;

    printf ("Inserir limite inferior: ");
    scanf("%d", &limiteInf); getchar();

    printf ("Inserir limite superior: ");
    scanf("%d", &limiteSup); getchar();

    if (limiteInf > limiteSup) return;

    printf ("Inserir quantidade: ");
    scanf("%d", &quantidade); getchar();

    if (quantidade < 0) return;

    int arranjo[quantidade] = {};

    for(int i = 0; i < quantidade; i++)
    {
        arranjo[i] = gerarInt(limiteInf, limiteSup);
    }

    FILE* arquivo = fopen("dados8.txt", "wt");

    fprintf(arquivo, "%d\n", quantidade);

    for(int i = 0; i < quantidade; i++)
    {
        fprintf(arquivo, "%d\n", arranjo[i]);
    }

    fclose(arquivo);
}

typedef struct Arranjo
{
    int tamanho;
    int* array;
}Arranjo;

Arranjo* lerArquivo(const char* nomeArquivo)
{
    FILE* arquivo = fopen(nomeArquivo, "rt");

    int quantidade = 0;

    fscanf(arquivo, "%d", &quantidade);

    Arranjo* arranjo = (Arranjo*) calloc(1,sizeof(Arranjo));
    arranjo->array = (int*) calloc(quantidade, sizeof(int));
    arranjo->tamanho = quantidade;
    int valorAtual = 0;

    for(int i = 0; i < quantidade; i++)
    {
        fscanf(arquivo, "%d", &valorAtual);
        arranjo->array[i] = valorAtual;
    }

    fclose(arquivo);

    return arranjo;
}

int acharMenorPar(Arranjo* arranjo)
{
    int menorPar = INT_MAX;
    for(int i = 0; i < arranjo->tamanho; i++)
    {
        if (arranjo->array[i] < menorPar && arranjo->array[i] % 2 == 0)
        {
            menorPar = arranjo->array[i];
        }
    }

    return (menorPar == INT_MAX) ? 0 : menorPar;
}

void metodo_014()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");

    int menorPar = acharMenorPar(arranjo);

    free(arranjo);

    printf("Menor par achado: %d\n", menorPar);
}


int acharMenorParDivisivelPorTres(Arranjo* arranjo)
{
    int menor = INT_MAX;
    for(int i = 0; i < arranjo->tamanho; i++)
    {
        if (
                arranjo->array[i] < menor &&
                arranjo->array[i] % 3 == 0 &&
                arranjo->array[i] % 5 != 0
           )
        {
            menor = arranjo->array[i];
        }
    }

    return (menor == INT_MAX) ? 0 : menor;
}

void metodo_015()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");

    int menorPar = acharMenorParDivisivelPorTres(arranjo);

    free(arranjo);

    printf("Menor par divisel por 3 e nao por 5 achado: %d\n", menorPar);

}

int acharMedia(Arranjo* arranjo)
{
    int soma = 0;

    for(int i = 0; i < arranjo->tamanho; i++)
    {
        soma = soma + arranjo->array[i];
    }

    return (soma/arranjo->tamanho);
}


void metodo_016()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");

    int media = acharMedia(arranjo);

    FILE* menorMedia = fopen("menorMedia.txt", "wt");
    FILE* maiorMedia = fopen("maiorMedia.txt", "wt");

    for(int i = 0; i < arranjo->tamanho; i++)
    {
        if(arranjo->array[i] >= media)
        {
            fprintf(maiorMedia, "%d\n", arranjo->array[i]);
        }
        else
        {
            fprintf(menorMedia, "%d\n", arranjo->array[i]);
        }
    }

    free(arranjo);
    fclose(menorMedia);
    fclose(maiorMedia);
}


int verificarOrdenadoDesc(Arranjo* arranjo)
{
    int resultado = 1;
    int i = 0;

    while(resultado && (i < arranjo->tamanho - 1))
    {
        if(arranjo->array[i] < arranjo->array[i+1])
        {
            resultado = 0;
        }
    }

    return resultado;
}

void metodo_017()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");

    if(verificarOrdenadoDesc(arranjo))
    {
        printf("O arranjo esta ordenado em ordem descrescente\n");
    }
    else
    {
        printf("O arranjo nao esta ordenado em ordem descrescente\n");
    }

    free(arranjo);
}

int procurarValor(int posicaoInicial, int valorProcurar, Arranjo* arranjo)
{
    int resultado = 0;

    for(int i = posicaoInicial; i < arranjo->tamanho; i++)
    {
        if(arranjo->array[i] == valorProcurar)
        {
            resultado = 1;
        }
    }

    return resultado;
}


void metodo_018()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");
    int numeroProcurar = 0;
    int posicaoInicial = 0;

    printf ("Inserir numero a procurar: ");
    scanf("%d", &numeroProcurar); getchar();

    printf ("Inserir posicao inicial: ");
    scanf("%d", &posicaoInicial); getchar();

    if(procurarValor(posicaoInicial, numeroProcurar, arranjo))
    {
        printf("Valor encontrado\n");
    }
    else
    {
        printf("Valor nao encontrado\n");
    }

    free(arranjo);
}

int procurarPosicao(int posicaoInicial, int valorProcurar, Arranjo* arranjo)
{
    int resultado = 0;

    for(int i = posicaoInicial; i < arranjo->tamanho; i++)
    {
        if(arranjo->array[i] == valorProcurar)
        {
            resultado = 1;
            printf("Valor %d achado na posicao %d\n", valorProcurar, i);
        }
    }

    return resultado;
}


void metodo_019()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");
    int numeroProcurar = 0;
    int posicaoInicial = 0;

    printf ("Inserir numero a procurar: ");
    scanf("%d", &numeroProcurar); getchar();

    printf ("Inserir posicao inicial: ");
    scanf("%d", &posicaoInicial); getchar();

    procurarPosicao(posicaoInicial, numeroProcurar, arranjo);

    free(arranjo);
}


int acharQuantos(int posicaoInicial, int valorProcurar, Arranjo* arranjo)
{
    int resultado = 0;
    int quantidade = 0;

    for(int i = posicaoInicial; i < arranjo->tamanho; i++)
    {
        if(arranjo->array[i] == valorProcurar)
        {
            resultado = 1;
            quantidade++;
        }
    }
    printf("Foram achados %d valores para: %d", quantidade, valorProcurar);

    return resultado;
}


void metodo_020()
{
    Arranjo* arranjo = lerArquivo("dados8.txt");
    int numeroProcurar = 0;
    int posicaoInicial = 0;

    printf ("Inserir numero a procurar: ");
    scanf("%d", &numeroProcurar); getchar();

    printf ("Inserir posicao inicial: ");
    scanf("%d", &posicaoInicial); getchar();

    acharQuantos(posicaoInicial, numeroProcurar, arranjo);

    free(arranjo);
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
