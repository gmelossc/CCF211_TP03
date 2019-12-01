#include "includes/aWord.h"

void allocWord(char **letters){
  (*letters) = (char*) malloc(MAXW*sizeof(char));
}

void initWord(Word *W){
  allocWord(&(W->letters));
  W->size = 0;
}

int insertCharToWord(char **letters, char toAdd, int pos){
  (*letters)[pos] = toAdd;
  (*letters)[++pos] = '\0';
  return pos;
}


void insertChar(Word *W, char toAdd){
    W->size = insertCharToWord(&(W->letters), toAdd, W->size);
}

void removeChar(Word *W){
  if(W->size > 0){
  W->size--;
  W->letters[W->size] = '\0';
  }
  else printf("Não há caracteres para remover\n");
}

int wordSize(Word W){
  return W.size;
}

void printWord(Word W){
  for(int i=0; W.letters[i]!='\0' ; i++) printf("%c", W.letters[i]);
  printf("\n");
}

void freeWord(Word *W){
  W->size = 0;
  free(W->letters);
}
