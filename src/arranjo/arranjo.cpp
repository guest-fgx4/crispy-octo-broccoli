#include <iostream>
#include <iomanip>
#include <AEDI/arranjo.hpp>
#include "arranjo.hpp"

template <typename T>
ArranjoClasse<T>::ArranjoClasse(int n, T initial)
{
    opitional = initial;
    tamamho = 0;
    dados = nullptr;

    if (n > 0)
    {
        tamamho = n;
        dados = new T [tamamho];
    }
};

template <typename T>
void ArranjoClasse<T>::free()
{
    if (dados != nullptr)
    {
        delete (dados);
        dados = nullptr;
    }
}

template <typename T>
void ArranjoClasse<T>::set(int posicao, T valor)
{
    if ( 0 <= posicao && posicao < tamamho)
    {
        dados[posicao] = valor;
    }
}

template <typename T>
void ArranjoClasse<T>::print()
{
    using namespace std;

    cout << endl;
    for (int i = 0; i < tamamho; i++)
    {
        cout << setw(3) << i << " : " << setw(9) << dados[i] << endl;
    }
    cout << endl;
}

template <typename T>
void ArranjoClasse<T>::preenpreencherArranjoAleatorio(int limiteInf, int limiteSup)
{
    if (dados != nullptr)
    {
        for (int i = 0; i < tamamho; i++)
        {
            dados [i] = randIntIntervalo(limiteInf,limiteSup);
        }
        
    }
}
