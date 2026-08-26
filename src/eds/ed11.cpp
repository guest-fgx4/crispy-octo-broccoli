#include <iostream>
#include "ed11Arranjo.hpp"
#include "ed11Arquivo.hpp"

void metodo_011()
{
    std::cout << "Metodo 01" << std::endl;

    int limiteInf = 0;
    int limiteSup = 0;
    int quantidade = 0;

    std::cout << "Inserir quantidade elementos:" << std::endl;
    std::cin >> quantidade;

    std::cout << "Inserir limite inferior:" << std::endl;
    std::cin >> limiteInf;

    std::cout << "Inserir limite superior:" << std::endl;
    std::cin >> limiteSup;

    ArranjoClasse<int> arranjo(quantidade, 0);
    arranjo.preenpreencherArranjoAleatorio(limiteInf, limiteSup);

    ArquivoClass<int> arquivo("ED11_DADOS.TXT", 0);
    arquivo.gravarArranjoArquivo(arranjo);

}

void metodo_012()
{
    std::cout << "Metodo 02" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    arranjo.searchFirstOdd();
}

void metodo_013()
{
    std::cout << "Metodo 03" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    arranjo.searchFirstEvenx3();
}

void metodo_014()
{
    std::cout << "Metodo 04" << std::endl;
    
    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    int soma = arranjo.addInterval(2, 4);

    std::cout << "Valor total da soma: " << soma << std::endl;
}

void metodo_015()
{
    std::cout << "Metodo 05" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    int media = arranjo.mediaMovel(2,4);

    std::cout << "Valor total da soma: " << media << std::endl;
}

void metodo_016()
{
    std::cout << "Metodo 06" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    if (arranjo.positives())
    {
        std::cout << "Valores abaixo de 100 e positivos" << std::endl;
    }
    else
    {
        std::cout << "Valores nao abaixo de 100 e positivos" << std::endl;
    }
}

void metodo_017()
{
    std::cout << "Metodo 07" << std::endl;
    
    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    if (arranjo.deCrescente())
    {
        std::cout << "Arranjo decrescente" << std::endl;
    }
    else
    {
        std::cout << "Arranjo nao decrescente" << std::endl;
    }
}

void metodo_018()
{
    std::cout << "Metodo 08" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    if (arranjo.procurarInter(2,4,6))
    {
        std::cout << "Valor no intervalo" << std::endl;
    }
    else
    {
        std::cout << "Valor nao no intervalo" << std::endl;
    }
}

void metodo_019()
{
    std::cout << "Metodo 09" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    auto arranjo2 = arranjo.escalar(2,4,10);

    std::cout << "Primeiro Arranjo: " << std::endl;
    arranjo.print();

    std::cout << "Segundo Arranjo Escalar: " << std::endl;
    arranjo2.print();
}

void metodo_020()
{
    std::cout << "Metodo 10" << std::endl;

    ArquivoClass<int> arquivo ("ED11_DADOS.TXT", 0);
    auto arranjo = arquivo.lerArranjoArquivo();

    std::cout << "Arranjo sem sort: " << std::endl;
    arranjo.print();

    arranjo.sortDecresce();
    std::cout << "Arranjo com sort: " << std::endl;
    arranjo.print();

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
