#ifndef TP3_EXECUTAVEL_TEXT_H
#define TP3_EXECUTAVEL_TEXT_H
#include "encaWord.h"

typedef struct Celula *Apontador;

typedef struct Celula{
    struct Celula *prox;
    char texto;
}Tcel;

typedef struct{
    Tcel *initial;
    int tamanho;
}Text;

void Inicializa(Text *texto);
void InsereTexto(Text *texto,char texto);
void RemoveTexto(Text *texto);
void PrintTexto(Text *texto);
void TamanhoTexto(Text *texto);

#endif