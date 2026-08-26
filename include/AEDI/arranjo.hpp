#include <AEDI/arranjo.h>

#pragma once

template <typename T>
class ArranjoClasse
{
private:
    T opitional;
    int tamamho;
    T *dados;

public:
    ArranjoClasse(int n, T initial);
    void free();
    void set(int posicao, T valor);
    T get(int posicao);
    void print();
    void preenpreencherArranjoAleatorio(int limiteInf, int limiteSup);
};
