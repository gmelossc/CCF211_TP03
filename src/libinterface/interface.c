#include "encaWord.h"
#include "text.h"
#include "lib.h"
void Interface(){
    int escolha1;
    printf("[Escolha um dos TAD's encadeados abaixo]\n");
    printf("[1-TAD_palavra]\n");printf("[2-TAD_texto]\n");printf("[3-TAD_biblioteca]\n");printf("TAD->");
    scanf("%d",&escolha1);
    if(escolha1==1){
        int resposta;
        char letra;
        int controle=0;
        TWord word;
        Inicializa(&word);
        while(controle!=1){
            printf("Digite a letra que deseja inserir:");
            scanf("%c",&letra);
            AddNoFim(&word,letra);
            printf("1-Continuar\n2-Parar\nResposta->");
            scanf("%d",&resposta);
            if(resposta!=1){
                controle=1;
            }
        }
        printf("Sua palavra formada é:");
        PrintPal(&word);
    }
    else if(escolha1==2){
        char palavra[20];
        int resposta1;
        int controle1=0;
        Text texto;
        Inicia(&texto);
        while(controle1!=1){
            TWord word1;
            Inicializa(&word1);
            printf("Digite a palavra que deseja inserir no texto:\n");
            scanf("%s",palavra);
            for(unsigned int i=0;i<strlen(palavra);i++){
                AddNoFim(&word1,palavra[i]);
            }
            InsereTexto(&texto,&word1);
            printf("1-Continuar\n2-Parar\n");printf("Resposta->");
            scanf("%d",&resposta1);
            if(resposta1!=1)controle1=1;
        }
        PrintTexto(&texto);
    }
    else if(escolha1==3) {
        Libery biblio;
        IniciaLibery(&biblio);
        int controle3=0;
        int resposta2;
        while(1){
            char palavra[20];
            int resposta1;
            int controle2;
            Text texto;
            Inicia(&texto);
            while(1){
                TWord word1;
                Inicializa(&word1);
                printf("Digite a palavra que deseja inserir no texto:\n");
                scanf("%s",palavra);
                for(unsigned int i=0;i<strlen(palavra);i++){
                    AddNoFim(&word1,palavra[i]);
                }
                InsereTexto(&texto,&word1);
                printf("1-Continuar\n2-Parar\n");printf("Resposta->");
                scanf("%d",&resposta1);
                if(resposta1!=1)break;
            }
            InsereLibery(&biblio,&texto);
            printf("Deseja inserir mais um texto?:\n");
            printf("1-Continuar\n2-Parar\n");printf("Resposta->");
            scanf("%d",&controle2);
            if(controle2!=1){
                break;
            }
        }
        PrintLibery(&biblio);
    }
}