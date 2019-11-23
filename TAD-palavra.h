#ifndef TP3_TAD_PALAVRA_H
#define TP3_TAD_PALAVRA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 1000
typedef struct{
    char palavra[MAXTAM];
}Word;

void Inicializa(Word *palavra);
InsereLetra();
RemoveLetra();
Imprime();
Tamanho();
void Interface();

#endif //TP3_TAD_PALAVRA_H
