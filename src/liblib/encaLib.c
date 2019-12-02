#include "includes/encaLib.h"
void IniciaLibery(Libery *biblio){
    biblio->initial=NULL;
    biblio->end=NULL;
    biblio->Tamanho_da_Biblioteca=0;
}
void InsereLibery(Libery *biblio,Text *texto) {
    if(biblio->end==NULL){
        biblio->end=(Ponteiro)malloc(sizeof(Tccel));
        biblio->initial=biblio->end;
    }
    else{
        biblio->end->prox=(Ponteiro)malloc(sizeof(Tccel));
        biblio->end=biblio->end->prox;
    }
    biblio->end->texto=*texto;
    biblio->end->prox = NULL;
    biblio->Tamanho_da_Biblioteca++;
}
int RemoveLibery(Libery *biblio){
    Tccel *aux;
    aux = biblio -> initial;
    if (biblio -> Tamanho_da_Biblioteca == 1){
        free(biblio -> initial);
        biblio -> initial = NULL;
        biblio -> Tamanho_da_Biblioteca--;
    }
    while (aux -> prox -> prox != NULL)
        aux = aux -> prox;
    free(aux -> prox);
    aux -> prox = NULL;
    biblio -> Tamanho_da_Biblioteca--;
    return 0;
}
void PrintLibery(Libery *biblio){
    int contador=1;
    Ponteiro aux;
    aux=biblio->initial;
    printf("Biblioteca:\n");
    while(aux != NULL){
        printf("[%d] ",contador);
        PrintTexto(&aux->texto);
        aux=aux->prox;
        contador++;
    }
}
void Tamanho_da_biblioteca(Libery *biblio){
    printf("Tamanho da biblioteca:%d",biblio->Tamanho_da_Biblioteca);
}
