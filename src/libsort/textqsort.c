#include "../libtext/includes/aText.h"

void Partition(int left, int right, int *i, int *j, aText *text){
  Word pivo, aux;
  *i = left; *j=right;
  pivo = text->words[(*i+*j)/2];
  do{
    while(pivo.letters[0] > text->words[*i].letters[0]) (*i)++;
    while(pivo.letters[0] < text->words[*j].letters[0]) (*j)--;
    if(*i <= *j){
      aux = text->words[*i];
      text->words[*i] = text->words[*j];
      text->words[*j] = aux;
      (*i)++; (*j)--;
    }
  } while(*i <= *j);
}

void ordena(int left, int right, aText *text){
  int i, j;
  Partition(left, right, &i, &j, text);
  if(left<j) ordena(left, j, text);
  if(i<right) ordena(i, right, text);
}

void quicksort(aText *text){
  ordena(0, text->size - 1, text);
}
