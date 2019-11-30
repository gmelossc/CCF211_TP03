#include "gerarand.c"

int main(){
#include "Text.h"
#include "Ordena.h"
    int main(){
        Text meuText;
        meuText = geraTexto(4,10);
        PrintTexto(&meuText);
        TamanhoTexto(&meuText);
        printf("\n");
        RemoveTexto(&meuText,0);
        PrintTexto(&meuText);
//    printf("\n");
//    Selecao1(&meuText,meuText.tamanhotexto);
//    Libery biblio;
//    biblio=geraBiblioteca(100,100,10);
//    PrintLibery(&biblio);
//    Tamanho_da_biblioteca(&biblio);
        return 0;
    }
}
