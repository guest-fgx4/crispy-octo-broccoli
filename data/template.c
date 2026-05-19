void metodo_011()
{
    printf("Metodo 01\n");
}

void metodo_012()
{
    printf("Metodo 02\n");
}


void metodo_013()
{
    printf("Metodo 03\n");
}

void metodo_014()
{
    printf("Metodo 04\n");
}

void metodo_015()
{
    printf("Metodo 05\n");
}

void metodo_016()
{
    printf("Metodo 06\n");
}

void metodo_017()
{
    printf("Metodo 07\n");
}

void metodo_018()
{
    printf("Metodo 08\n");
}

void metodo_019()
{
    printf("Metodo 09\n");
}

void metodo_020()
{
    printf("Metodo 10\n");
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
