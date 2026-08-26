#pragma once

#include<fstream>
#include "ed12Matriz.hpp"


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

    ~ArquivoClass()
    {
        nomeArquivo = "";
    }
    
    void setNome(std::string string)
    {
        if (!string.empty())
        {
            nomeArquivo = string;
        }
    }

    void gravarMatriz(MatrizClasse<T>* matriz)
    {
        gravar.open(nomeArquivo);

        if (matriz->getDados() != nullptr)
        {
            gravar << matriz->getlinha() << std::endl;
            gravar << matriz->getColuna() << std::endl;

            for (int linha = 0; linha < matriz->getlinha(); linha++)
            {
                for (int coluna = 0; coluna < matriz->getColuna(); coluna++)
                {
                    gravar << matriz->get(linha, coluna) << std::endl;
                }   
            }
        }

        gravar.close();
    }

    MatrizClasse<T> lerMatriz()
    {
        leitura.open(nomeArquivo);
        int linhas = 0;
        int colunas = 0;

        leitura >> linhas;
        leitura >> colunas;

        if (linhas < 0 || colunas < 0)
        {
            std::cout << "Tamanho invalidio" << std::endl;
            leitura.close();
            MatrizClasse<int> x(0,0);
            return x;
        }
        else
        {
            MatrizClasse<int> matriz(linhas, colunas);

            int valor = 0;

            for (int linha = 0; linha < linhas; linha++)
            {
                for (int coluna = 0; coluna < colunas; coluna++)
                {
                    leitura >> valor;
                    matriz.set(linha, coluna, valor);
                }
            }
            
            leitura.close();

            return matriz;
        }
    }
};
