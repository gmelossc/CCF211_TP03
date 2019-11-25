#ifndef TP3_EXECUTAVEL_TEXT_H
#define TP3_EXECUTAVEL_TEXT_H
#include "encaWord.h"

typedef struct cel* Apontador;

typedef struct cel {
    struct cel *prox;
    char palavra[20];
} Tcel;

typedef struct{
    Apontador initial;
    Apontador end;
    int tamanhotexto;
}Text;

void Inicia(Text *texto);
void InsereTexto(Text *texto,char text[20]);
int RemoveTexto(Text *texto,char palavra[20]);
void PrintTexto(Text *texto);
void TamanhoTexto(Text *texto);

#endif