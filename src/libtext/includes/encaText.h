#ifndef TP3_EXECUTAVEL_TEXT_H
#define TP3_EXECUTAVEL_TEXT_H

typedef struct cel* Apontador;

typedef struct cel {
    struct cel *prox;
    TWord word;
} Tcel;

typedef struct{
    Apontador initial;
    Apontador end;
    int tamanhotexto;
}Text;

void Inicia(Text *texto);
void InsereTexto(Text *texto,TWord *word);
int RemoveTexto(Text *texto);
void PrintTexto(Text *texto);
void TamanhoTexto(Text *texto);

#endif
