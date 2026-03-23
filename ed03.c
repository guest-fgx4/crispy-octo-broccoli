#include<stdio.h>
#include<stdlib.h>

#define erro_print() printf("%s%d", "Erro na linha: ", __LINE__);
#define STR_LENGTH  40


void methodo_0311()
{
    printf("Metodo 0331\n");

    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();


    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
        }
        index++;
    }
    

    free(string);
}


void methodo_0312()
{
    printf("Metodo 0312\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            quantidade++;
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }
        index++;
    }
    

    free(string);
}

void methodo_0313()
{
    printf("Metodo 0313\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras maiusculas menores que K\n");

    int index = 0;

    for(; string[index] != '\0'; index++);

    while ( index >= 0 )
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] < 'K')
        {
            quantidade++;
            printf("%s%c\n", "Letra maiuscula e menor que K: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }
        index--;
    }
    

    free(string);
}



void methodo_0314()
{
    printf("Metodo 0314\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando as letras\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= 'A' && string[index] <= 'Z')
        {
            quantidade++;
            printf("%s%c\n", "Letra maiuscula: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }

        if (string[index] >= 'a' && string[index] <= 'z')
        {
            quantidade++;
            printf("%s%c\n", "Letra minuscula: ", string[index]);
            printf("%s%d\n", "Contador: ", quantidade);
        }
        index++;
    }
    

    free(string);
}

void methodo_0315()
{
    printf("Metodo 0315\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando os digitos pares\n");

    int index = 0;

    for(; string[index] != '\0'; index++);

    while ( index >= 0 )
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= '0' && string[index] <= '9')
        {
            if (((int)string[index]) % 2 == 0)
            {
                quantidade++;
                printf("%s%c\n", "Digito: ", string[index]);
                printf("%s%d\n", "Contador: ", quantidade);
            }
        }
        index--;
    }
    

    free(string);
}


//FIXME: Fix the disgusting if statement on line 252
void methodo_0316()
{
    printf("Metodo 0316\n");

    int quantidade = 0;
    char *string = (char*)malloc(STR_LENGTH * sizeof(char));

    if (string == NULL)
    {
        erro_print()
        return;
    }

    printf("Digitar uma palavra (Max 40 caracteries): ");
    scanf("%s", &string[0]);
    getchar();
    printf("\n%s%s\n", "Palavra digitada: ", string);

    printf("Mostrando tudo que nao for digito par e tambem nao letra\n");

    int index = 0;
    while (string[index] != '\0' && index < STR_LENGTH)
    {
        // printf("%s%c\n", "char atual: ", string[index]);

        if (string[index] >= '0' && string[index] <= '9')
        {
            if (!( ((int)string[index]) % 2 == 0 ))
            {
                quantidade++;
                printf("%s%c\n", "Numero impar: ", string[index]);
                printf("%s%d\n", "Contador: ", quantidade);
            }
        }
        else
        {
            if (
                ! (
                    (string[index] >= 'a' && string[index] <= 'z')
                    ||
                    (string[index] >= 'A' && string[index] <= 'Z')
                )
            )
            {
                quantidade++;
                printf("%s%c\n", "Nao letra: ", string[index]);
                printf("%s%d\n", "Contador: ", quantidade);
            }
        }
        index++;
    }
    

    free(string);
}

void methodo_0317()
{
    printf("Metodo 0317\n");

    int limiteInferior = 0;
    int limiteSuperior = 0;
    int quantidade = 0;

    int contador = 0;
    
    printf("Digite o limite inferior: ");
    scanf("%d", &limiteInferior);
    getchar();

    printf("Digite o limite Superior: ");
    scanf("%d", &limiteSuperior);
    getchar();

    
    if (limiteInferior > limiteSuperior)
    {
        printf("O valor do limite inferior nao pode ser maior que o limite inferior\n");
        return;
    }

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    getchar();
    
    if (quantidade < 0 || quantidade > 10)
    {
        printf("Pera la amigo, o valor da quantidade nao poder ser negativo ou acima de 10\n");
        return;
    }

    int *conjuntoTest = (int*)malloc(quantidade * sizeof(int));

    if (conjuntoTest == NULL)
    {
        erro_print()
        return;
    }

    printf("Valor do intervalo: [%d, %d] => quantidade: %d\n", limiteInferior, limiteSuperior, quantidade);


    for(int i = 0; i < quantidade; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &conjuntoTest[i]);
        getchar();
    }

    for (int i = 0; i < quantidade; i++)
    {
        if (conjuntoTest[i] >= limiteInferior && conjuntoTest[i] <= limiteSuperior)
        {
            if (conjuntoTest[i] % 5 == 0)
            {
                contador++;
                printf("Valor no intervalo e multiplo de 5: %d\n", conjuntoTest[i]);
                printf("Contador: %d\n", contador);
            }
        }
    }
    

    free(conjuntoTest);
}

void methodo_0318()
{
    printf("Metodo 0318\n");

    int limiteInferior = 0;
    int limiteSuperior = 0;
    int quantidade = 0;

    int contador = 0;
    
    printf("Digite o limite inferior: ");
    scanf("%d", &limiteInferior);
    getchar();

    printf("Digite o limite Superior: ");
    scanf("%d", &limiteSuperior);
    getchar();

    
    if (limiteInferior > limiteSuperior)
    {
        printf("O valor do limite inferior nao pode ser maior que o limite inferior\n");
        return;
    }

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    getchar();
    
        
    if (quantidade < 0 || quantidade > 10)
    {
        printf("Pera la amigo, o valor da quantidade nao poder ser negativo ou acima de 10\n");
        return;
    }

    int *conjuntoTest = (int*)malloc(quantidade * sizeof(int));

    if (conjuntoTest == NULL)
    {
        erro_print()
        return;
    }

    printf("Valor do intervalo: [%d, %d] => quantidade: %d\n", limiteInferior, limiteSuperior, quantidade);


    for(int i = 0; i < quantidade; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &conjuntoTest[i]);
        getchar();
    }

    for (int i = 0; i < quantidade; i++)
    {
        if (conjuntoTest[i] >= limiteInferior && conjuntoTest[i] <= limiteSuperior)
        {
            if (!(conjuntoTest[i] % 5 == 0) && (conjuntoTest[i] % 3 == 0))
            {
                contador++;
                printf("Valor no intervalo e multiplo de 3 e nao multiplo de 5: %d\n", conjuntoTest[i]);
                printf("Contador: %d\n", contador);
            }
        }
    }
    
    free(conjuntoTest);
}

void methodo_0319()
{
    printf("Metodo 0319\n");

    double limiteInferior = 0;
    double limiteSuperior = 0;
    int quantidade = 0;

    int contador = 0;
    
    printf("Digite o limite inferior: ");
    scanf("%lf", &limiteInferior);
    getchar();

    printf("Digite o limite Superior: ");
    scanf("%lf", &limiteSuperior);
    getchar();

    if ((limiteInferior > limiteSuperior))
    {
        printf("O valor do limite inferior nao pode ser maior que o limite superior\n");
        return;
    }

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    getchar();
    
    
    if (quantidade < 0 || quantidade > 10)
    {
        printf("Pera la amigo, o valor da quantidade nao poder ser negativo ou acima de 10\n");
        return;
    }

    double *conjuntoTest = (double*)malloc(quantidade * sizeof(double));

    if (conjuntoTest == NULL)
    {
        erro_print()
        return;
    }

    printf("Valor do intervalo: (%lf, %lf) => quantidade: %d\n", limiteInferior, limiteSuperior, quantidade);


    for(int i = 0; i < quantidade; i++)
    {
        printf("Digite um valor: ");
        scanf("%lf", &conjuntoTest[i]);
    }

    for (int i = 0; i < quantidade; i++)
    {
        if (conjuntoTest[i] > limiteInferior && conjuntoTest[i] < limiteSuperior)
        {
            if (((int)conjuntoTest[i] % 2 == 0) && ((int)conjuntoTest[i] < 6) )
            {
                contador++;
                printf("Valor no intervalo com a parte inteira par e menor que 6: %lf\n", conjuntoTest[i]);
                printf("Contador: %d\n", contador);
            }
        }
    }
    free(conjuntoTest);
}

void methodo_0320()
{
    printf("Metodo 0320\n");

    double limiteInferior = 0.0;
    double limiteSuperior = 0.0;
    int quantidade = 0;

    int contador = 0;
    
    printf("Digite o limite inferior: ");
    scanf("%lf", &limiteInferior);
    getchar();

    printf("Digite o limite Superior: ");
    scanf("%lf", &limiteSuperior);
    getchar();

    if ((limiteInferior > limiteSuperior))
    {
        printf("O valor do limite inferior nao pode ser maior que o limite superior\n");
        return;
    }

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    getchar();
    
    
    if (quantidade < 0 || quantidade > 10)
    {
        printf("Pera la amigo, o valor da quantidade nao poder ser negativo ou acima de 10\n");
        return;
    }

    double *conjuntoTest = (double*)malloc(quantidade * sizeof(double));

    if (conjuntoTest == NULL)
    {
        erro_print()
        return;
    }

    printf("Valor do intervalo: (%lf, %lf) => quantidade: %d\n", limiteInferior, limiteSuperior, quantidade);


    for(int i = 0; i < quantidade; i++)
    {
        printf("Digite um valor: ");
        scanf("%lf", &conjuntoTest[i]);
        getchar();
    }

    double fracionario = 0.0;

    for (int i = 0; i < quantidade; i++)
    {
        fracionario = conjuntoTest[i] - ((int)conjuntoTest[i]);
        if (fracionario > limiteInferior && fracionario < limiteSuperior)
        {
            contador++;
            printf("Valor fracionario dentro do limite: %lf\n", conjuntoTest[i]);
            printf("Contador: %d\n", contador);
        }
    }
    free(conjuntoTest);
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
            methodo_0311();
            break;
        case 2:
            methodo_0312();
            break;
        case 3:
            methodo_0313();
            break;
        case 4:
            methodo_0314();
            break;
        case 5:
            methodo_0315();
            break;
        case 6:
            methodo_0316();
            break;
        case 7:
            methodo_0317();
            break;
        case 8:
            methodo_0318();
            break;
        case 9:
            methodo_0319();
            break;
        case 10:
            methodo_0320();
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