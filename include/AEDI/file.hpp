#include <cstdlib>
#include <string>

#include <AEDI/file.h>

#pragma once

template<typename T>
class ArquivoClass
{
private:
    T tipo;
    Arquivo* arquivo;
    std::string nomeArquivo;

public:
    ArquivoClass(std::string nome, T init, OpArquivo operacao);
};
