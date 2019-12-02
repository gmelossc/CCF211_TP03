#include "includes/aText.h"

void initText(Text *text, Size length){
  Size MAX[] = {10, 100, 1000, 10000, 100000};
  (text->words) = (Word*) malloc(MAX[length-1]*sizeof(Word));

  for(int i = 0; i< MAX[length - 1]; i++) initWord(&(text->words[i]));
  text->size =0;
  text->capacity = MAX[length-1];
}

void insertWord(Text *text){
  char toAdd;
  while((scanf("%c", &toAdd) != EOF) &&(text->size < text->capacity)){
    if(toAdd == ' '){
      ++text->size;
      continue;
    }
    else if(toAdd == '\n'){
      ++text->size;
      break;
    }
    insertChar(&(text->words[text->size]), toAdd);
  }
}

void removeWord(Text *text){
  for(int i =0; i<text->words[text->size - 1].size; i++) removeChar(&(text->words[text->size - 1]));
  freeWord(&(text->words[text->size - 1]));
  --text->size;
}

void printText(Text text){
  for(int i =0; i< text.size; ++i){
    for(int j = 0; text.words[i].letters[j] != '\0'; ++j){
      printf("%c", text.words[i].letters[j]);
    }
    printf(" ");
  }
  printf("\n");
}

int textSize(Text text){
  return text.size;
}

void freeText(Text *text){
  text->size = 0;
  for(int i =0; i<text->size; i++)
    freeWord(&(text->words[i]));
  free(text->words);
}
