#include "includes/encaText.h"


void Inicia(Text *texto){
    texto->initial=NULL;
    texto->end=NULL;
    texto->tamanhotexto=0;
}
void InsereTexto(Text *texto,TWord *word) {
    if(texto->end==NULL){
        texto->end=(Apontador)malloc(sizeof(Tcel));
        texto->initial=texto->end;
    }
    else{
        texto->end->prox=(Apontador)malloc(sizeof(Tcel));
        texto->end=texto->end->prox;
    }
    texto->end->word=*word;
    texto->end->prox = NULL;
    texto->tamanhotexto++;
}
int RemoveTexto(Text *texto){
    Tcel *aux;
    aux = texto -> initial;
    if (texto -> tamanhotexto == 1){
        free(texto -> initial);
        texto -> initial = NULL;
        texto -> tamanhotexto--;
    }
    while (aux -> prox -> prox != NULL)
        aux = aux -> prox;
    free(aux -> prox);
    aux -> prox = NULL;
    texto -> tamanhotexto--;
    return 0;
}
void PrintTexto(Text *texto){
    int contador=1;
    Apontador aux;
    aux=texto->initial;

    printf("Texto:");
    TamanhoTexto(texto);
    while(aux != NULL){
        PrintPal(&aux->word);
        printf(" ");
        aux=aux->prox;
        contador++;
    }
    printf("\n\n");
}
void TamanhoTexto(Text *texto){
    printf("\nTamanho: %d palavras\n\n",texto->tamanhotexto-1);
}
