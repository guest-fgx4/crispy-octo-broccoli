#pragma once

#include <iostream>
#include <iomanip>

int randIntIntervalo()
{
    return (rand() % 100);
}

template <typename T>
class MatrizClasse
{
private:
    int colunas;
    int linhas;
    T tipo;
    T **dados;

public:
    MatrizClasse()
    {
        this->colunas = 0;
        this->linhas = 0;
        this->dados = nullptr;
    }

    MatrizClasse(int linhas, int colunas)
    {
        if (linhas < 0 || colunas < 0)
        {
            std::cout << "Erro ao criar Matriz: Tamanho invalido" << std::endl;
            this->colunas = 0;
            this->linhas = 0;
            this->dados = nullptr;
        }
        else
        {
            this->colunas = colunas;
            this->linhas = linhas;

            bool test = true;

            dados = new T *[linhas];

            for (int indice = 0; indice < linhas; indice++)
            {
                dados[indice] = new T[colunas];
                test = test && dados[indice] != nullptr;
            }

            if (!test)
            {
                dados = nullptr;
            }
        }
    }

    MatrizClasse(MatrizClasse<T>& outro)
    {
        this->linhas = {outro.linhas};
        this->colunas = {outro.colunas};
        this->tipo = {outro.tipo};

        this->dados = {new T*[linhas]};

        bool test = true;

        for (int linha = 0; linha < this->linhas; linha++)
        {
            dados[linha] = new T[colunas];
            test = test && (dados[linha] != nullptr);
        }
        
        if (test)
        {
            for (int linha = 0; linha < linhas; linha++)
            {
                for (int coluna = 0; coluna < colunas; coluna++)
                {
                    dados[linha][coluna] = {outro.get(linha, coluna)};
                }
            }
        }
        else
        {
            dados = nullptr;
        }
        
    }

    ~MatrizClasse()
    {
        if (this->dados != nullptr)
        {
            for (int indice = 0; indice < linhas; indice++)
            {
                delete[] (this->dados[indice]);
            }

            delete[] (this->dados);

            this->dados = nullptr;
        }
    }


    void preencherAleatorio()
    {
        if (this->dados != nullptr)
        {
            for (int linha = 0; linha < this->linhas; linha++)
            {
                for (int coluna = 0; coluna < this->colunas; coluna++)
                {
                    dados[linha][coluna] = randIntIntervalo();
                }
            }
        }
    }

    void set(int linha, int coluna, T valor)
    {
        if (linha < 0 || coluna < 0 || linha > this->linhas || coluna > this->colunas)
        {
            std::cout << "posicao para settar invalido" << std::endl;
        }
        else
        {
            this->dados[linha][coluna] = valor;
        }
    }

    T getTipo() { return (this->tipo); }
    T getlinha() { return (this->linhas); }
    T** getDados() { return (this->dados); }
    T getColuna() { return (this->colunas); }
    T get(int linha, int coluna)
    {
        if (linha < 0 || coluna < 0)
        {
            std::cout << "Erro: Posicao invalida para busca" << std::endl;
            return tipo;
        }
        else
        {
            return dados[linha][coluna];
        }
    }

    void print()
    {
        if(this->dados != nullptr)
        {
            for (int linha = 0; linha < this->linhas; linha++)
            {
                for (int coluna = 0; coluna < this->colunas; coluna++)
                {
                    std::cout << std::setw(4) << this->dados[linha][coluna];
                }
                std::cout << std::endl;
            }
            
        }
    }

    MatrizClasse<T> escalar(int valor)
    {
        MatrizClasse<int> matriz2(this->linhas, this->colunas);

        for (int linha = 0; linha < this->linhas; linha++)
        {
            for (int coluna = 0; coluna < this->colunas; coluna++)
            {
                matriz2.set(linha, coluna, this->get(linha,coluna) * valor);
            }    
        }

        return matriz2;
    }

    bool identidade()
    {
        bool resp = true;

        for (int linha = 0; linha < this->linhas; linha++)
        {
            for (int coluna = 0; coluna < this->colunas; coluna++)
            {
                if (linha == coluna)
                {
                    resp = resp && dados[linha][coluna] == 1;
                }
                else
                {
                    resp = resp && dados[linha][coluna] == 0;
                }
            }    
        }

        return resp;
    }

    bool operator== (MatrizClasse<T>& other)
    {
        bool resp = true;
        if (
            other.getlinha() < 0 ||
            other.getColuna() < 0 ||
            this->linhas != other.getlinha() ||
            this->colunas != other.getColuna()
        )
        {
            std::cout << "Erro ao comprar duas matrizes" << std::endl;
        }
        else
        {
            int linha = 0;
            while (linha < this->linhas && resp)
            {
                int coluna = 0;
                while (coluna < this->colunas && resp)
                {
                    resp = resp && (dados[linha][coluna] == other.get(linha, coluna));

                    coluna++;
                }
                
                linha++;
            }
            
        }

        return resp;
    }
};