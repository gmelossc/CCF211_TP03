#include "text.h"

void Inicia(Text *texto){
    texto->initial=NULL;
    texto->end=NULL;
    texto->tamanhotexto=0;
}
void InsereTexto(Text *texto,char text[20]) {
    if(texto->end==NULL){
        texto->end=(Apontador)malloc(sizeof(Tcel));
        texto->initial=texto->end;
    }
    else{
        texto->end->prox=(Apontador)malloc(sizeof(Tcel));
        texto->end=texto->end->prox;
    }
    strcpy(texto->end->palavra,text);
    texto->end->prox = NULL;
    texto->tamanhotexto++;
}
int RemoveTexto(Text *texto,char palavra[20]){
    Tcel *aux;
    if(texto->initial==texto->end){
        return 0;
    }
    strcpy(palavra,texto->initial->palavra);
    aux=texto->initial;
    texto->initial=texto->initial->prox;
    free(aux);
    texto->tamanhotexto--;
    if(texto->initial==NULL){
        texto->end=NULL;
    }
    return 1;
}
void PrintTexto(Text *texto){
    Apontador aux;
    aux=texto->initial;
    printf("Texto:");
    while(aux != NULL){
        printf("%s ", aux->palavra);
        aux = aux->prox;
    }
}
void TamanhoTexto(Text *texto){
    printf("\nTamanho do texto:%d",texto->tamanhotexto);
}