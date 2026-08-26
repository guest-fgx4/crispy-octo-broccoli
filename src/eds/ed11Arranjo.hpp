#pragma once

#include <iostream>
#include <iomanip>

int randIntIntervalo(int limiteInf, int limiteSup)
{
    int resposta = 0;

    if (limiteInf > limiteSup)
    {
        resposta = -1;
        std::cout << "Limite inferior maior que superior" << std::endl;
        return resposta;
    }

    resposta = (rand() % limiteSup) + 1;

    if (resposta < limiteInf)
    {
        resposta = resposta + (limiteInf - resposta);
    }

    return resposta;
}

template <typename T>
class ArranjoClasse
{
private:
    T opitional;
    int tamamho;
    T *dados;

public:
    ArranjoClasse(int n, T initial)
    {
        opitional = initial;
        tamamho = 0;
        dados = nullptr;

        if (n > 0)
        {
            tamamho = n;
            dados = new T[tamamho];
        }
    }

    ~ArranjoClasse()
    {
        if (dados != nullptr)
        {
            delete dados;
            dados = nullptr;
        }
    }

    void free()
    {
        if (dados != nullptr)
        {
            delete (dados);
            dados = nullptr;
        }
    }

    void set(int posicao, T valor)
    {
        if (0 <= posicao && posicao < tamamho)
        {
            dados[posicao] = valor;
        }
    }

    T get(int posicao)
    {
        if (posicao < 0 || posicao > tamamho - 1)
        {
            std::cout << "Posicao Invalida";
            return this->opitional;
        }
        else
        {
            return dados[posicao];
        }
    }

    void print()
    {
        using namespace std;

        cout << endl;
        for (int i = 0; i < tamamho; i++)
        {
            cout << setw(3) << i << " : " << setw(9) << dados[i] << endl;
        }
        cout << endl;
    }

    void preenpreencherArranjoAleatorio(int limiteInf, int limiteSup)
    {
        if (dados != nullptr)
        {
            for (int i = 0; i < tamamho; i++)
            {
                dados[i] = randIntIntervalo(limiteInf, limiteSup);
            }
        }
    }


    bool estaVazio()
    {
        bool resposta = true;

        if (this->dados != nullptr)
        {
            resposta = false;
        }

        return resposta;
    }

    int pegarTamanho()
    {
        return this->tamamho;
    }

    void searchFirstOdd()
    {
        int valor = -2;
        for (int indice = 0; indice < this->tamamho; indice++)
        {
            if (this->get(indice) % 2 != 0 && this->get(indice) > valor)
            {
                valor = this->get(indice);
            }
        }

        std::cout << "Maior valor impar: " << valor << std::endl;
    }

    void searchFirstEvenx3()
    {
        int valor = -2;
        for (int indice = 0; indice < this->tamamho; indice++)
        {
            if (this->get(indice) % 5 == 0 && this->get(indice) % 2 != 0 && this->get(indice) > valor)
            {
                valor = this->get(indice);
            }
        }

        if ( valor < 0)
        {
            std::cout << "Nao existe Valor aceitavel" << valor << std::endl;
        }
        else
        {
            std::cout << "Maior valor par mul de 5: " << valor << std::endl;
        }

    }

    int addInterval(int ini, int fin)
    {
        int soma = 0;
        for (int indice = ini; indice < fin; indice++)
        {
            soma += this->get(indice);
        }

        return soma;
    }

    int mediaMovel(int ini, int fin)
    {
        if (fin < ini || fin > this->tamamho || ini < 0) return -1;

        int soma = 0;
        for (int indice = ini; indice <= fin; indice++)
        {
            soma += this->get(indice);
        }

        return (soma /(fin - ini + 1));
    }

    bool positives()
    {
        bool res = true;

        for (int indice = 0; indice < this->tamamho; indice++)
        {
            if (this->get(indice) > 100 || this->get(indice) < 0)
            {
                res = false;
            }
        }

        return res;
    }

    bool deCrescente()
    {
        bool res = true;

        for (int indice = 0; indice < this->tamamho - 1; indice++)
        {
            if (this->get(indice) < this->get(indice + 1))
            {
                res = false;
            }
        }

        return res;
    }

    bool procurarInter(int ini, int fin, int valor)
    {
        if (fin < ini || fin > this->tamamho || ini < 0) return -1;

        bool res = false;
        for (int indice = ini; indice <= fin; indice++)
        {
            if (valor == this->get(indice))
            {
                res = true;
            }
        }

        return res;
    }

    ArranjoClasse<T> escalar(int ini, int fin, int escalar)
    {
        if (fin < ini || fin > this->tamamho || ini < 0)
        {
            ArranjoClasse<T> arranjo (0,0);
            return arranjo;
        }
        else
        {

            ArranjoClasse<T> arranjo (this->tamamho, this->opitional);
            
            for (int indice = 0; indice < this->tamamho; indice++)
            {
                arranjo.set(indice, this->get(indice));
            }

            for (int indice = ini; indice <= fin; indice++)
            {
                arranjo.set(indice, arranjo.get(indice) * escalar);
            }

            return arranjo;
        }
    }

    void sortDecresce()
    {
        int valor = 0;
        int pos = 0;
        int swap = 0;

        for (int i = 0; i < this->tamamho; i++)
        {
            for (int j = i; j < this->tamamho; j++)
            {
                if (this->get(j) > valor)
                {
                    valor = this->get(j);
                    pos = j;
                }
            }

            swap = this->get(i);
            this->set(i, valor);
            this->set(pos, swap);
            valor = 0;
        }

    }
};