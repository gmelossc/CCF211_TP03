#include "Ordena.h"
int conversao(char x){
    int a=x-'0';
//    printf("%d ",x);
    return a;
}
void Selecao1(Text *texto, int n){
    int i, j, Min;
    int contador=0;
    char auxiliar[n];
    Apontador aux;
    aux=texto->initial;
//    Tcel aux2;
    Text textoaux;
    while(aux != NULL){
//        printf("%c ",aux->word.inicio->letra);
        strcpy(&auxiliar[contador],&aux->word.inicio->letra);
        aux=aux->prox;
        contador++;
    }
    for (i = 0; i < n-1; i++)
    {
        Min = i;
        for (j = i + 1 ; j < n; j++)
            if (conversao(auxiliar[j])<conversao(auxiliar[Min])) {
                Min = j;
            }
        textoaux.initial->word.inicio=&texto->initial->word.inicio[Min];
        texto->initial->word.inicio[Min]=texto->initial->word.inicio[i];
        texto->initial->word.inicio[i]=*textoaux.initial->word.inicio;
        //usar o Remove e o insere aqui para trocar de posição a lista encadeada
    }
    PrintTexto(texto);
}
void Selecao2(Libery* biblio, int n){
//    int i, j, Min;
//    Libery aux;
//    for (i = 0; i < n - 1; i++)
//    {
//        Min = i;
//        for (j = i + 1 ; j < n; j++)
//            if (1+n==3)
//                Min = j;
//        aux = v[Min];
//        v[Min] = v[i];
//        v[i] = aux;
//    }
}
