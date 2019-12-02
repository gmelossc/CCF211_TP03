#include "includes/aText.h"

void initText(aText *aText, Size length){
  Size MAX[] = {10, 100, 1000, 10000, 100000};
  (aText->words) = (Word*) malloc(MAX[length-1]*sizeof(Word));

  for(int i = 0; i< MAX[length - 1]; i++) initWord(&(aText->words[i]));
  aText->size =0;
  aText->capacity = MAX[length-1];
}

void insertWord(aText *aText, Word toAdd){
  for(int i =0; i<toAdd.size; i++)
    if(aText->size < aText->capacity){  
      insertChar(&(aText->words[aText->size]), toAdd.letters[i]);
    }
    ++aText->size;
}

void removeWord(aText *aText){
  for(int i =0; i<aText->words[aText->size - 1].size; i++) removeChar(&(aText->words[aText->size - 1]));
  freeWord(&(aText->words[aText->size - 1]));
  --aText->size;
}

void printText(aText aText){
  for(int i =0; i< aText.size; ++i){
    for(int j = 0; aText.words[i].letters[j] != '\0'; ++j){
      printf("%c", aText.words[i].letters[j]);
    }
    printf(" ");
  }
  printf("\n");
}

int TextSize(aText aText){
  return aText.size;
}

void freeText(aText *aText){
  for(int i =0; i<aText->capacity; i++)
    freeWord(&(aText->words[i]));
  free(aText->words);
  aText->size = 0;
  aText->capacity = 0;
}
