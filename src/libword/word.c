#include <stdlib.h>
#include <stdio.h>
#include "word.h"

void Inicializa(TWord *palavra){
	palavra -> inicio = NULL;
	palavra -> tamanho = 0;
}

void AddNoFim(TWord *palavra, char toAdd){
	TCelula *novaCel = (Aponta) malloc(sizeof(TCelula));
	novaCel -> letra = toAdd;
	novaCel -> prox = NULL;

	if (palavra -> inicio == NULL){
		palavra -> inicio = novaCel;
	}

	else {
		TCelula *atualCel = palavra -> inicio;
		while (atualCel -> prox != NULL){
			atualCel = atualCel -> prox;
		}
		atualCel -> prox = novaCel;
	}
	palavra -> tamanho++;
}

void RemDoFim(TWord *palavra){
	// Trecho não completamente otimizado
	// If Else poderiam ser removidos
	// Com uma lógica específica
	// No entanto não há grande efeito
	// Na eficiência, pois está função não é
	// Utilizada em grandes loopś
	if (palavra -> tamanho > 1){
		TCelula *atualCel = palavra -> inicio;
		while (atualCel -> prox -> prox != NULL){
			atualCel = atualCel -> prox;
		}
		free(atualCel -> prox);
		atualCel -> prox = NULL;
		palavra -> tamanho--;
	}
	else if (palavra -> tamanho == 1){
		free(palavra -> inicio);
		palavra -> inicio = NULL;
		palavra -> tamanho--;
	}
	else return;
}

void PrintPal(TWord *palavra){
	if (palavra -> tamanho < 1){
		printf("Palavra sem caracteres\n");
		return;
	}
	TCelula *atualCel = palavra -> inicio;
	while (atualCel -> prox != NULL){
		printf("%c", atualCel -> letra);
		atualCel = atualCel -> prox;
	} printf("%c\n", atualCel -> letra);
}

void PrintTam(TWord *palavra){
	printf("Tamanho da palavra: %d\n", palavra -> tamanho);
}