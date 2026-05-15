#ifndef AEDI_ARRANJO_
#define AEDI_ARRANJO_

//#define arranjoTipoNome(a,b) a ## b
//#define arranjoTipo(tipo) \
//    typedef struct arranjoTipoNome(Arranjo,tipo) { \
//        int tamanho; \
//        tipo *array; \
//    } arranjoTipoNome(Arranjo,tipo); \
//
//#define listaTipos \
//    X(int) \
//    X(double) \
//    X(char) 
//
//#define X(tipo) arranjoTipo(tipo)
//    listaTipos
//#undef X

//typedef struct ArranjoInt{
//    int tamamho;
//    int *array;
//} ArranjoInt;


enum tipoArranjo {
    INTEIRO             = 0,
    DUPLA_PRECISAO,
    CARACTERE
};

typedef struct Arranjo{
    int tamanho;
    enum tipoArranjo tipo;
    void *array;
} Arranjo;

Arranjo* criarArranjo(int tamanho, enum tipoArranjo tipo);
void preencherArranjoAleatorio(Arranjo* arranjo, int limiteInf, int limiteSup);


#endif
