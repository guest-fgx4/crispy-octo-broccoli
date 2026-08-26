#pragma once

#include<fstream>
#include "ed11Arranjo.hpp"


template <typename T>
class ArquivoClass
{
private:
    T tipo;
    std::ofstream gravar;
    std::ifstream leitura;
    std::string nomeArquivo;

public:
    ArquivoClass(std::string nome, T init)
    {
        if (!nome.empty())
        {
            tipo = init;
            nomeArquivo = nome;
        }
    }
    

    void gravarArranjoArquivo(ArranjoClasse<T> arranjo)
    {

        gravar.open(nomeArquivo);

        if (!arranjo.estaVazio())
        {
            gravar << arranjo.pegarTamanho() << std::endl;

            for (int i = 0; i < arranjo.pegarTamanho(); i++)
            {
                gravar << arranjo.get(i) << std::endl;
            }
            
        }

        gravar.close();
    }

    ArranjoClasse<T> lerArranjoArquivo()
    {
        leitura.open(nomeArquivo);
        int tamanho = 0;

        leitura >> tamanho;

        if (tamanho < 0)
        {
            std::cout << "Tamanho invalidio" << std::endl;
            leitura.close();
            ArranjoClasse<int> x(0,0);
            return x;
        }
        else
        {
            ArranjoClasse<int> arranjo(tamanho, 0);
            
            int valor = 0;

            for (int indice = 0; indice < tamanho; indice++)
            {
                leitura >> valor;
                arranjo.set(indice, valor);
            }
            
            leitura.close();

            return arranjo;
        }
    }
};
