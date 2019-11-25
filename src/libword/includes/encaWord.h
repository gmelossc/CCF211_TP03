#ifndef TWORD
#define TWORD
#include <stdlib.h>
#include <stdio.h>

typedef struct Celula* Aponta;

typedef struct Celula {
	struct Celula *prox;
	char letra;
} TCelula;

typedef struct {
	TCelula *inicio;
	int tamanho;
} TWord;

#endif

void Inicializa(TWord *palavra);
void AddNoFim(TWord *palavra, char toAdd);
void RemDoFim(TWord *palavra);
void PrintPal(TWord *palavra);
void PrintTam(TWord *palavra);