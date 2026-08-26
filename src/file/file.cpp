#include <AEDI/file.hpp>

template <typename T>
ArquivoClass<T>::ArquivoClass(std::string nome, T init, OpArquivo operacao)
{
    if (!nome.empty())
    {
        tipo = init;
        arquivo = abrirArquivo(nome.c_str(),operacao);
    }
};