#include "../gerarand.c"
#include "../libsort/textoEncaSelectionSort.c"
#include "../libsort/biblioEncaSelectionSort.c"
#include "../libsort/textoEncaQuickSort.c"
#include "../libsort/biblioEncaQuickSort.c"

Text makeTextoEnca(){
    int choice1,choice2,choice3;
    int comps=0;
    Text newTexto;
    long int start;

    system("clear");
    printf("CRIANDO TEXTO ENCADEADO\n\n");
    printf("Digite o número máximo de palavras do texto:\n> ");
    scanf("%d",&choice1);
    printf("Digite o número máximo de caracteres das palavras do texto:\n> ");
    scanf("%d",&choice2);
    system("clear");
    newTexto = geraTexto(choice1,choice2);
    printf("TEXTO CRIADO\n\n");
    PrintTexto(&newTexto);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n> ");
    scanf("%d",&choice3);
    start = time(NULL);
    if (choice3 == 1){
        textoEncaSelectionSort(newTexto.initial,&comps);
        PrintTexto(&newTexto);
    }
    else if (choice3 == 2){
        textoEncaQuickSort(newTexto.initial, &comps);
        PrintTexto(&newTexto);
    }
    printf("Ordenado em %ld segundos\n", time(NULL)-start);
    printf("Total de comparações:%i\n", comps);
    return newTexto;
}

void makeTextoVetor(){
    
}

Libery makeBiblioEnca(){
    int choice1,choice2,choice3,choice4;
    int comps=0;
    Libery newBib,extraBib;
    long int start;

    system("clear");
    printf("CRIANDO BIBLIOTECA ENCADEADA\n\n");
    printf("Digite o número de textos de sua biblioteca:\n> ");
    scanf("%d",&choice1);
    printf("Digite o número de palavras dos textos da biblioteca:\n> ");
    scanf("%d",&choice2);
    printf("Digite o tamanho máximo das palavras dos textos da biblioteca:\n> ");
    scanf("%d",&choice3);
    newBib = geraBiblio(choice1,choice2,choice3);
    PrintLibery(&newBib);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n> ");
    scanf("%d",&choice4);
    start = time(NULL);
    if (choice4 == 1){
        extraBib.initial = biblioEncaSelectionSort(newBib.initial,&comps);
        PrintLibery(&extraBib);
    }
    else if (choice4 == 2){
        extraBib.initial = biblioEncaQuickSort(newBib.initial,&comps);
        PrintLibery(&extraBib);
    }
    printf("Ordenado em %ld segundos\n", time(NULL)-start);
    printf("Total de comparações:%i\n", comps);
    return newBib;
}

void makeBiblioVetor(){

}

void getTipoTexto(){
    int choice;
    system("clear");
    printf("Deseja utilizar TADs de texto baseados em:\n1- Listas Encadeadas\n2- Vetores\n>");
    scanf("%d",&choice);
    if (choice == 1){
        makeTextoEnca();
    }
    else if (choice == 2){
        makeTextoVetor();
    }
}

void getTipoBiblio(){
    int choice;
    system("clear");
    printf("Deseja utilizar TADs da biblioteca baseados em:\n1- Listas Encadeadas\n2- Vetores\n>");
    scanf("%d",&choice);
    if (choice == 1){
        makeBiblioEnca();
    }
    else if (choice == 2){
        makeBiblioVetor();
    }
}

void Interface(){
    IniSeed();// IniSeed TEM QUE ser chamada antes da criação de qualquer unidade pseudo-aleatória
    int choice;
    system("clear");
    printf("Deseja trabalhar com:\n1- Textos\n2- Bibliotecas\n> ");
    scanf("%d",&choice);
    if (choice == 1){
        getTipoTexto();
    }
    else if (choice == 2){
        getTipoBiblio();
    }
}