#include "../gerarand.c"
#include "../libsort/textoEncaSelectionSort.c"
#include "../libsort/biblioEncaSelectionSort.c"
#include "../libsort/textoEncaQuickSort.c"
#include "../libsort/biblioEncaQuickSort.c"
#include "../libsort/textqsort.c"
#include "../libsort/textsort.c"
#include "../libsort/libqsort.c"
#include "../libsort/libsort.c"
#include <time.h>
#include <unistd.h>

Text makeTextoEnca(){
    int choice1,choice2,choice3,choice4;
    long long int comps=0;
    long long int movs=0;
    Text newTexto;
    double time_spent=0.0;

    system("clear");
    printf("CRIANDO TEXTO ENCADEADO\n\n");
    printf("Digite o número máximo e o número mínimo de palavras do texto:\n> ");
    scanf("%d %d",&choice1, &choice4);
    printf("Digite o número máximo de caracteres das palavras do texto:\n> ");
    scanf("%d",&choice2);
    system("clear");
    newTexto = geraTexto(choice1,choice2,choice4);
    printf("TEXTO CRIADO\n\n");
    PrintTexto(&newTexto);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n3- Comparação de Sorts\n> ");
    scanf("%d",&choice3);
    if (choice3 == 1){
        clock_t begin = clock();
        textoEncaSelectionSort(newTexto.initial,&comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        PrintTexto(&newTexto);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", movs);
    }
    else if (choice3 == 2){
        clock_t begin = clock();
        textoEncaQuickSort(newTexto.initial, &comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        PrintTexto(&newTexto);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", movs);
    }

    else if (choice3 == 3){
        clock_t begin = clock();
        textoEncaSelectionSort(newTexto.initial,&comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO SELECTION SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO SELECTION SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO SELECTION SORT: %lld\n", movs);
        time_spent = 0.0;
        comps = 0;
        movs = 0;
        begin = clock();
        textoEncaQuickSort(newTexto.initial, &comps,&movs);
        end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO QUICK SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO QUICK SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO QUICKSORT: %lld\n", movs);
    }
    return newTexto;
}

void makeTextoVetor(){
    int choice1, choice2, choice3; 
    long long comps, moves;
    aText newTexto;
    double time_spent;

    system("clear");
    printf("CRIANDO TEXTO COM VETOR\n\n");
    printf("Digite o número máximo de palavras do texto:\n");
    printf("1 - 100\n"); 
    printf("2 - 1000\n"); 
    printf("3 - 10000\n"); 
    printf("4 - 100000\n"); 
    printf("> ");
    scanf("%d",&choice1);
    printf("Digite o número mínimo de palavras do texto:\n> ");
    scanf("%d",&choice3);
    newTexto = geraTextoVet(choice1,choice3);
    printf("TEXTO CRIADO\n\n");
    printText(newTexto);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n3- Comparação de Sorts\n> ");
    scanf("%d", &choice2);
    if (choice2==1){
        comps = 0;
        moves = 0;
        time_spent = 0.0;
        clock_t begin = clock();
        selectionSort(&newTexto, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printText(newTexto);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", moves);
    }
    else if (choice2==2){
        comps = 0;
        moves = 0; 
        time_spent = 0.0;
        clock_t begin = clock();
        quicksort(&newTexto, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printText(newTexto);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", moves);
    }
    else if (choice2==3){
        aText aux = newTexto;
        comps =0;
        moves = 0;
        time_spent = 0.0;
        clock_t begin = clock();
        selectionSort(&newTexto, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO SELECTION SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO SELECTION SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO SELECTION SORT: %lld\n", moves);
        comps =0;
        moves = 0;
        time_spent = 0.0;
        begin = clock();
        quicksort(&aux, &comps, &moves);
        end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO SELECTION SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO SELECTION SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO SELECTION SORT: %lld\n", moves);
    }

}

Libery makeBiblioEnca(){
    int choice1,choice2,choice3,choice4,choice5;
    long long int comps=0;
    long long int movs=0;
    Libery newBib,extraBib1,extraBib2;
    double time_spent=0.0;

    system("clear");
    printf("CRIANDO BIBLIOTECA ENCADEADA\n\n");
    printf("Digite o número de textos de sua biblioteca:\n> ");
    scanf("%d",&choice1);
    printf("Digite o número máximo e o número mínimo de palavras nos textos de sua biblioteca:\n> ");
    scanf("%d %d",&choice2, &choice5);
    //printf("Digite o número de palavras dos textos da biblioteca:\n>");
    //scanf("%d",&choice2);
    printf("Digite o tamanho máximo das palavras dos textos da biblioteca:\n>");
    scanf("%d",&choice3);
    newBib = geraBiblio(choice1,choice2,choice3,choice5);
    PrintLibery(&newBib);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n3- Comparação de Sorts\n> ");
    scanf("%d",&choice4);
    if (choice4 == 1){
        clock_t begin = clock();
        extraBib1.initial = biblioEncaSelectionSort(newBib.initial,&comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        PrintLibery(&extraBib1);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", movs);
    }
    else if (choice4 == 2){
        clock_t begin = clock();
        extraBib1.initial = biblioEncaQuickSort(newBib.initial,&comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        PrintLibery(&extraBib1);
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", movs);

    }
    else if (choice4 == 3){
        clock_t begin = clock();
        extraBib1.initial = biblioEncaSelectionSort(newBib.initial,&comps,&movs);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO SELECTION SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO SELECTION SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO SELECTION SORT: %lld\n", movs);
        time_spent = 0.0;
        comps = 0;
        movs = 0;
        begin = clock();
        extraBib2.initial = biblioEncaQuickSort(newBib.initial,&comps,&movs);
        end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO QUICKSORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO QUICKSORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO QUICKSORT: %lld\n", movs);
    }
    return newBib;
}

void makeBiblioVetor(){
    Library newLib, aux;
    int choice1, choice2, choice3, choice4;
    long long comps, moves;
    double time_spent;
    system("clear");
    printf("Digite abaixo a quantidade de textos de sua biblioteca:\n");
    printf("1 - 100 textos\n");
    printf("2 - 100.000 textos\n> ");
    scanf("%d", &choice1);
    printf("Digite o número máximo de palavras do texto:\n");
    printf("1 - 100\n"); 
    printf("2 - 1000\n"); 
    printf("3 - 10000\n"); 
    printf("4 - 100000\n"); 
    printf("> ");
    scanf("%d",&choice2);
    printf("Digite o número mínimo de palavras do texto:\n> ");
    scanf("%d",&choice4); 
    newLib = geraLibraryVet(choice1,choice2,choice4);
    printf("Escolha seu método de sort:\n1- SelectionSort\n2- QuickSort\n3- Comparação de Sorts\n> ");
    scanf("%d", &choice3);

    if(choice3 == 1){
        comps =0;
        moves = 0;
        time_spent = 0.0;
        clock_t begin = clock();
        libSelectionSort(&newLib, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", moves);
     }
     else if(choice3 == 2){
        comps =0;
        moves = 0;
        time_spent = 0.0;
        clock_t begin = clock();
        libQuicksort(&newLib, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES: %lld\n", moves);

     }
     else if(choice3 == 3){
        aux = newLib;
        comps =0;
        moves = 0;
        time_spent = 0.0;
        clock_t begin = clock();
        libSelectionSort(&newLib, &comps, &moves);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO SELECTION SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES SELECTION SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES SELECTION SORT: %lld\n", moves);
        comps =0;
        moves = 0;
        time_spent = 0.0;
        begin = clock();
        libQuicksort(&aux, &comps, &moves);
        end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("\nTEMPO DE EXECUÇÃO DO QUICK SORT: %lfs\n", time_spent);
        printf("NUMERO DE COMPARAÇÕES DO QUICK SORT: %lld\n", comps);
        printf("NUMERO DE MOVIMENTAÇÕES DO QUICK SORT: %lld\n", moves);


     }


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
  Library library;
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
