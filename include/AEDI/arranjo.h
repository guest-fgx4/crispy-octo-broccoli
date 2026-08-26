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
    aINTEIRO             = 0,
    aDOUBLE,
    ACARACTERE
};

typedef struct Arranjo{
    int tamanho;
    enum tipoArranjo tipo;
    void *array;
} Arranjo;

#ifdef __cplusplus
extern "C" {
#endif

Arranjo* criarArranjo(int tamanho, enum tipoArranjo tipo);
void preencherArranjoAleatorio(Arranjo* arranjo, int limiteInf, int limiteSup);
int buscarIntArranjo(Arranjo* arranjo, int valor);
int comprarArranjos(Arranjo* arranjo1, Arranjo* arranjo2);
int somarArranjo(Arranjo* arranjo1, int constante, Arranjo* arranjo2);
int estaDecrescente(Arranjo* arranjo);

#ifdef __cplusplus
}
#endif

#endif
