#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{
    int ano;
    int mes;
    int dia;

} Date;

typedef struct Car
{
    int id;
    char *marca;
    char *modelo;
    int ano;
    char *categoria;
    char **combustivel;
    int cilindros;
    double cilindrada;
    char *transmissao;
    char *tracao;
    double consumoCidade;
    double consumoEstrada;
    double co2;
    int turbo;
    Date date;

} Car;

void printCar(Car *car)
{
    // printf("[%d ## %s ## %s ## %d ## %s ## %s ## COMB ## %d ## %lf ## %s ## %s ## %lf ## %lf ## %lf ## %d ## DATA]",
    //     car->id, car->marca, car->modelo, car->ano, car->categoria,
    //     car->cilindros, car->cilindrada, car->transmissao, car->tracao,
    //     car->consumoCidade, car->consumoEstrada, car->co2, car->turbo
    // );

    printf("[%d ## %s ## %s ## %d ## %s ## COMB ## %d ## %.2lf ## %s ## %s ## %.2lf. ## %.2lf ## %.2lf ## ",
           car->id, car->marca, car->modelo, car->ano, car->categoria,
           car->cilindros, car->cilindrada, car->transmissao, car->tracao,
           car->consumoCidade, car->consumoEstrada, car->co2);

    char *turbo = (car->turbo) ? "true" : "false";

    printf("%s ## DATA]\n", turbo);
}

int length(char *line)
{
    if (line == NULL)
        return -1;

    int i = 0;

    while (line[i] != '\n' || line[i] != '\0')
    {
        i++;
    }

    return i;
}

Car *parseCar(char *line)
{
    Car *car;
    if (line != NULL)
    {
        car = (Car *)malloc(sizeof(Car));
        char *token = strtok(line, ",");

        car->id = atoi(token);
        // printf("%s\n", token);
        // printf("%d\n", car->id);

        token = strtok(0, ",");

        //XXX: DO NO ATTRIVUTE 
        car->marca = token;
        //printf("%s\n", token);
        //printf("%s\n", car->marca);

        token = strtok(0, ",");

        car->modelo = token;
        //printf("%s\n", token);
        //printf("%s\n", car->modelo);

        token = strtok(0, ",");

        sscanf(token, "%d", &car->ano);
        //printf("%s\n", token);
        //printf("%d\n", car->ano);

        token = strtok(0, ",");

        car->categoria = token;
        //printf("%s\n", token);
        //printf("%s\n", car->categoria);

        // TODO: SOLVE COMB
        token = strtok(0, ",");

        token = strtok(0, ",");

        car->cilindros = atoi(token);
        //printf("%s\n", token);
        //printf("%d\n", car->cilindros);

        token = strtok(0, ",");

        sscanf(token, "%lf", &car->cilindrada);
        //printf("%s\n", token);
        //printf("%lf\n", car->cilindrada);

        token = strtok(0, ",");

        // sscanf(token, "%lf", &car->cilindrada);
        car->transmissao = token;
        //printf("%s\n", token);
        //printf("%s\n", car->transmissao);

        token = strtok(0, ",");

        // sscanf(token, "%lf", &car->cilindrada);
        car->tracao = token;
        //printf("%s\n", token);
        //printf("%s\n", car->tracao);

        token = strtok(0, ",");

        sscanf(token, "%lf", &car->consumoCidade);
        // car->tracao = token;
        //printf("%s\n", token);
        //printf("%lf\n", car->consumoCidade);

        token = strtok(0, ",");

        sscanf(token, "%lf", &car->consumoEstrada);
        // car->tracao = token;
        //printf("%s\n", token);
        //printf("%lf\n", car->consumoEstrada);

        token = strtok(0, ",");

        sscanf(token, "%lf", &car->co2);
        // car->tracao = token;
        //printf("%s\n", token);
        //printf("%lf\n", car->co2);

        token = strtok(0, ",");

        if (!strcmp(token, "true"))
        {
            car->turbo = 1;
        }
        else
        {
            car->turbo = 0;
        }

        // sscanf(token, "%d", &car->turbo);
        // car->tracao = token;
        //printf("%s\n", token);
        //printf("%d\n", car->turbo);

        // TODO: SOLVE DATA
        token = strtok(0, ",");
    }

    return car;
}

int main()
{

    FILE *file = fopen("C:\\Users\\1135188\\Downloads\\crispy-octo-broccoli\\veiculos.csv", "rt");

    char *test = (char *)malloc(sizeof(char) * 200);

    if (file == NULL)
    {
        printf("ok\n");
    }

    Car* cars[500];

    fgets(test, 200, file);
    printf("%s", test);
    // fgets(test, 200, file);
    // printf("%s", test);

    // while (fgets)
    // {
    //     /* code */
    // }
    

    // for (size_t i = 0; i < 500; i++)
    // {
    //     fgets(test, 200, file);
    //     cars[i] = parseCar(test);
    //     printCar(cars[i]);
    // }

    
    fgets(test, 200, file);
    cars[0] = parseCar(test);
    printCar(cars[0]);

    
    fgets(test, 200, file);
    cars[1] = parseCar(test);
    printCar(cars[1]);

    printf("\n");
    printCar(cars[0]);




    fclose(file);

    free(test);
    return 0;
}