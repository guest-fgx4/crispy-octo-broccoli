// #include<stdio.h>
// #include<stdlib.h>
// #include <string.h>

// #ifndef CONTAINER_H
// #define CONTAINER_H

// #include <stddef.h>

// // Publicly exposed handle representation
// typedef void* ContainerHandle;

// // Lifecycle and manipulation functions
// ContainerHandle container_create(size_t element_size);
// void            container_destroy(ContainerHandle handle);
// int             container_push(ContainerHandle handle, const void* data);
// const void*     container_get(ContainerHandle handle);

// #endif // CONTAINER_H


// // The user never sees this internal layout
// typedef struct {
//     void*  raw_data;     // Points to dynamically allocated storage
//     size_t elem_size;    // Remembers the size of the underlying type
//     int    count;        // Tracks active elements
// } SecretContainer;

// ContainerHandle container_create(size_t element_size) {
//     SecretContainer* ctx = malloc(sizeof(SecretContainer));
//     if (!ctx) return NULL;

//     ctx->raw_data  = malloc(element_size * 10); // Arbitrary buffer capacity
//     ctx->elem_size = element_size;
//     ctx->count     = 0;
//     return (ContainerHandle)ctx; // Implicitly converts to void*
// }

// int container_push(ContainerHandle handle, const void* data) {
//     if (!handle || !data) return 0;
    
//     // Cast the generic handle back to the concrete internal struct type
//     SecretContainer* ctx = (SecretContainer*)handle;
    
//     // Use memcpy because void* has no size information for a direct assignment
//     void* target_address = (char*)ctx->raw_data + (ctx->count * ctx->elem_size);
//     memcpy(target_address, data, ctx->elem_size);
    
//     ctx->count++;
//     return 1;
// }

// void container_destroy(ContainerHandle handle) {
//     if (!handle) return;
//     SecretContainer* ctx = (SecretContainer*)handle;
//     free(ctx->raw_data);
//     free(ctx);
// }

// const void* container_get(ContainerHandle handle) {
//     // 1. Guard against null pointer handles
//     if (!handle) return NULL;
    
//     // 2. Cast opaque handle back to the concrete private struct
//     SecretContainer* ctx = (SecretContainer*)handle;
    
//     // 3. Ensure the container actually has elements to return
//     if (ctx->count == 0) return NULL;
    
//     // 4. Calculate the byte offset of the most recent element
//     // Formula: base_address + ((count - 1) * element_size)
//     const void* target_address = (const char*)ctx->raw_data + ((ctx->count - 1) * ctx->elem_size);
    
//     return target_address;
// }

// typedef struct Matriz
// {
//     int linha;
//     int coluna;
//     unsigned int tamamhoTipo;
//     const char* format;
//     void** dados;
// } Matriz;

// void* transporMatriz(Matriz* matriz)
// {
//     if (matriz == NULL || matriz->linha < 0 || matriz->coluna < 0 || matriz->dados == NULL)
//     {
//         return NULL;
//     }

//     Matriz* matriz_t = malloc(sizeof(Matriz));
//     matriz_t->linha = 2;
//     matriz_t->coluna = 2;

//     matriz_t->dados = malloc(sizeof(int*) * 2);

//     for (size_t i = 0; i < matriz_t->coluna; i++)
//     {
//         matriz_t->dados = malloc(sizeof(int)*2);
//     }

//     if (matriz_t != NULL)
//     {
//         for (int indiceLinha = 0; indiceLinha < matriz_t->linha; indiceLinha++)
//         {
//             for (int indiceColuna = 0; indiceColuna < matriz_t->coluna; indiceColuna++)
//             {
//                 // matriz_t->dados[indiceLinha][indiceColuna] = matriz->dados[indiceColuna][indiceLinha];
//                 void* target_1 = (char*)matriz_t->dados + (matriz_t->tamamhoTipo * indiceLinha + matriz_t->tamamhoTipo * indiceColuna);
//                 void* target_2 = (char*)matriz->dados + (matriz->tamamhoTipo * indiceLinha + matriz_t->tamamhoTipo * indiceColuna);
//             }
//         }
//     }

//     return matriz_t;
// }

// void adicionaMatriz(Matriz* matriz)
// {
//     int num = 0;
//     if (matriz != NULL)
//     {
//         // int linha = 0;
//         // for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
//         // {
//         //     for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
//         //     {
//         //         num = matriz->tamamhoTipo * indiceColuna + matriz->tamamhoTipo * indiceLinha + linha * matriz->tamamhoTipo;
//         //         // printf("%d ", matriz->dados[indiceLinha][indiceColuna]);
//         //         // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * indiceLinha + matriz->tamamhoTipo * indiceColuna + linha * matriz->tamamhoTipo);
//         //         void* target = (char*)matriz->dados + (matriz->tamamhoTipo * indiceLinha + matriz->tamamhoTipo * indiceColuna);
//         //         memcpy(target, (const void*)&num, sizeof(int));
//         //     }
//         //     linha++;
//         // }

//         for (int i = 0; i < (matriz->coluna * matriz->linha); i++)
//         {
//             // printf("%d ", matriz->dados[indiceLinha][indiceColuna]);
//             // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * indiceLinha + matriz->tamamhoTipo * indiceColuna + linha * matriz->tamamhoTipo);
//             void* target = (char*)matriz->dados + (matriz->tamamhoTipo * i);
//             memcpy(target, (const void*)&i, sizeof(int));
//         }
//     }
// }

// void copyMatriz(Matriz* matriz1, Matriz* matriz2)
// {
//     if (matriz1 != NULL || matriz2 != NULL)
//     {
//         for (int indiceLinha = 0; indiceLinha < matriz1->linha; indiceLinha++)
//         {
//             for (int indiceColuna = 0; indiceColuna < matriz1->coluna; indiceColuna++)
//             {
//                 // printf("%d ", matriz->dados[indiceLinha][indiceColuna]);
//                 void* target = (char*)matriz1->dados + (matriz1->tamamhoTipo * (indiceColuna*2) + matriz1->tamamhoTipo * indiceLinha);
//                 void* target2 = (char*)matriz2->dados + (matriz2->tamamhoTipo * (indiceLinha*2) + matriz2->tamamhoTipo * indiceColuna);

//                 memcpy(target2, (const void*)target, sizeof(int));
//             }
//         }
//     }
// }


// void mostrarMatriz(Matriz* matriz)
// {
//     if (matriz != NULL)
//     {
//         for (int indiceLinha = 0; indiceLinha < matriz->linha; indiceLinha++)
//         {
//             for (int indiceColuna = 0; indiceColuna < matriz->coluna; indiceColuna++)
//             {
//                 void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (indiceLinha*2) + matriz->tamamhoTipo * indiceColuna);
//                 printf("%d ", *((int*)target));
//             }
//             printf("\n");
//         }
//     }

//     // for (int i = 1; i <= (matriz->coluna * matriz->linha); i++)
//     // {
//     //     // printf("%d ", matriz->dados[indiceLinha][indiceColuna]);
//     //     // void* target = (char*)matriz->dados + (matriz->tamamhoTipo * indiceLinha + matriz->tamamhoTipo * indiceColuna + linha * matriz->tamamhoTipo);
//     //     void* target = (char*)matriz->dados + (matriz->tamamhoTipo * (i - 1));
//     //     printf("%d ", *((int*)target));

//     //     if (i % matriz->coluna == 0)
//     //     {
//     //         printf("\n");
//     //     }
//     // }
// }


// int main()
// {

//     Matriz* m;

//     m = malloc(sizeof(Matriz));
//     m->linha = 2;
//     m->coluna = 2;
//     m->tamamhoTipo = sizeof(int);

//     m->dados = malloc(sizeof(int**) * 2);

//     for (size_t i = 0; i < m->coluna; i++)
//     {
//         m->dados = malloc(sizeof(int*)*2);
//     }

//     adicionaMatriz(m);
//     mostrarMatriz(m);

//     Matriz* b;

//     b = malloc(sizeof(Matriz));
//     b->linha = 2;
//     b->coluna = 2;
//     b->tamamhoTipo = sizeof(int);

//     b->dados = malloc(sizeof(int*) * 2);

//     for (size_t i = 0; i < b->coluna; i++)
//     {
//         b->dados = malloc(sizeof(int)*2);
//     }

//     copyMatriz(m, b);

//     mostrarMatriz(b);
    
    

//     return 0;
// }

