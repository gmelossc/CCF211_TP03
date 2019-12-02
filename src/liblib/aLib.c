#include "includes/aLib.h"

void initLib(Library *library, Size length){
  Size MAX[] = {2, 100, 100000};
  library->texts = (aText*) malloc(MAX[length-1]*sizeof(aText));
  for(int i =0; i< MAX[length - 1]; i++) initText(&(library->texts[i]), 1);
  library->size = MAX[length - 1];
}

void insertText(Library *library, aText toAdd, int thatText){
  for(int i =0; i<toAdd.size; i++) insertWord(&(library->texts[thatText]), toAdd.words[i]);
}

void removeText(Library *library){
  freeText(&(library->texts[library->size - 1]));
}

void printLib(Library library){
  for(int i =0; i<library.size; i++){
    printText(library.texts[i]);
    printf("\n");
  }
}

int libSize(Library library){
  return library.size;
}

void freeLib(Library *library){
  for(int i =0; i<library->size; i++) freeText(&(library->texts[i]));
  free(library->texts);
  library->size = 0;
}
