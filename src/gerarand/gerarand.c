#include "Text.h"
#include "Liblib.h"
#include <time.h>
TWord geraPalavra(int max_size_pal){
    TWord minhaWord;
    Inicializa(&minhaWord);
    int sizePalavra =  rand() % max_size_pal+1;
    // gera caracteres da tabela ASCII com letra minuscula,
    // 97 e 122 representam respectivamente 'a' e 'z'
    for (int i = 0; i < sizePalavra; i++){
        char randChar = (rand() % (122 + 1 - 97) + 97);
        AddNoFim(&minhaWord,randChar);
    }
    return minhaWord;
}

Text geraTexto(int size_texto,int max_size_pal){
    Text meuTexto;
    Inicia(&meuTexto);
    for (int i = 0; i < size_texto; i++){
        TWord novaWord = geraPalavra(max_size_pal);
        InsereTexto(&meuTexto,&novaWord);
    }
    return meuTexto;
}
Libery geraBiblioteca(int tamanho_da_biblioteca,int max_size_text,int max_size_palavra){
    Libery biblio;
    IniciaLibery(&biblio);
    for(int i=0;i<tamanho_da_biblioteca;i++){
        Text novotexto=geraTexto(max_size_text,max_size_palavra);
        InsereLibery(&biblio,&novotexto);
    }
    return biblio;
}