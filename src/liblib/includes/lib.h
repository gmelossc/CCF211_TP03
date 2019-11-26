#ifndef TP3_LIB_H
#define TP3_LIB_H

#include "text.h"
typedef struct ccel* Ponteiro;

typedef struct ccel {
    struct ccel *prox;
    Text texto;
} Tccel;

typedef struct{
    Ponteiro initial;
    Ponteiro end;
    int Tamanho_da_Biblioteca;
}Libery;

void IniciaLibery(Libery *biblio);
void InsereLibery(Libery *biblio,Text *texto);
int RemoveLibery(Libery *biblio);
void PrintLibery(Libery *biblio);
void Tamanho_da_biblioteca(Libery *biblio);
#endif //TP3_LIB_H