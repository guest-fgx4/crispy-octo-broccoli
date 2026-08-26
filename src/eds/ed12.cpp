#include <iostream>
#include "ed12Matriz.hpp"
#include "ed12Arquivo.hpp"

void metodo_011()
{
    std::cout << "Metodo 01" << std::endl;


    int linha = 0;
    int coluna = 0;

    std::cout << "Inserir quantidade linha: " << std::endl;
    std::cin >> linha;

    std::cout << "Inserir quantidade coluna: " << std::endl;
    std::cin >> coluna;

    MatrizClasse<int> matriz(linha, coluna);
    matriz.preencherAleatorio();

    ArquivoClass<decltype(matriz.getTipo())> arquivo ("ED12_DADOS.TXT", 0);
    arquivo.gravarMatriz(&matriz);
    
}

void metodo_012()
{
    std::cout << "Metodo 02" << std::endl;

    ArquivoClass<int> arquivo ("ED12_DADOS.TXT", 0);
    auto matriz = arquivo.lerMatriz();

    std::cout << "Matriz Original" << std::endl;
    matriz.print();
    
    auto matriz2 = matriz.escalar(10);
    std::cout << "Matriz Escalar" << std::endl;
    matriz2.print();
}

void metodo_013()
{
    std::cout << "Metodo 03" << std::endl;

    ArquivoClass<int> arquivo ("ED12_DADOS.TXT", 0);
    auto matriz = arquivo.lerMatriz();

    if (matriz.identidade())
    {
        std::cout << "Matriz indentidade" << std::endl;
    }
    else
    {
        std::cout << "Matriz nao indentidade" << std::endl;
    }
}

void metodo_014()
{
    std::cout << "Metodo 04" << std::endl;


    ArquivoClass<int> arquivo ("ED12_DADOS.TXT", 0);
    auto matriz = arquivo.lerMatriz();
    auto matriz2 = arquivo.lerMatriz();

    if (matriz == matriz2)
    {
        std::cout << "matrizes sao iguals" << std::endl;
    }
    else
    {
        std::cout << "matrizes nao sao iguals" << std::endl;
    }
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
