#include <iostream>

void metodo_011()
{
    std::cout << "Metodo 01" << std::endl;
}

void metodo_012()
{
    std::cout << "Metodo 02" << std::endl;
}

void metodo_013()
{
    std::cout << "Metodo 03" << std::endl;
}

void metodo_014()
{
    std::cout << "Metodo 04" << std::endl;
}

void metodo_015()
{
    std::cout << "Metodo 05" << std::endl;
}

void metodo_016()
{
    std::cout << "Metodo 06" << std::endl;
}

void metodo_017()
{
    std::cout << "Metodo 07" << std::endl;
}

void metodo_018()
{
    std::cout << "Metodo 08" << std::endl;
}

void metodo_019()
{
    std::cout << "Metodo 09" << std::endl;
}

void metodo_020()
{
    std::cout << "Metodo 10" << std::endl;
}

int main(void)
{
    int opcao = 0;

    std::cout << "Metodo Main" << std::endl;

    do
    {
        std::cout << "Entrar com opcao para selecionar metodo (1-10)" << std::endl;
        std::cin >> opcao;

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
            std::cout << "Metodo invalido, Selecionar metodos de 1 ate 10" << std::endl;
            std::cout << "Ou pressione 0 para sair" << std::endl;
            break;
        }
    } while (opcao != 0);

    std::cout << "Saindo do programa main..." << std::endl;
    return 0;
}
