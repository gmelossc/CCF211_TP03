#include "includes/aWord.h"

void allocWord(Word **word){
  (*word) = (Word*) malloc(MAXW*sizeof(Word));
}

void initWord(t_word *W){
  allocWord(&(W->word));
  W->size = 0;
}

int insertCharToWord(Word **word, char toAdd, int pos){
  (*word)[pos] = toAdd;
  (*word)[++pos] = '\0';
  return pos;
}


void insertChar(t_word *W, char toAdd){
    W->size = insertCharToWord(&(W->word), toAdd, W->size);
}

void removeChar(t_word *W){
  if(W->size > 0){
  W->size--;
  W->word[W->size] = '\0';
  }
  else printf("Não há caracteres para remover\n");
}

int wordSize(t_word W){
  return W.size;
}

void printWord(t_word W){
  for(int i=0; W.word[i]!='\0' ; i++) printf("%c", W.word[i]);
  printf("\n");
}
