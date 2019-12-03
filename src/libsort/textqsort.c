#include "../libtext/includes/aText.h"

void Partition(int left, int right, int *i, int *j, aText *text, long long *comps, long long *moves){
  Word pivo, aux;
  *i = left; *j=right;
  pivo = text->words[(*i+*j)/2];
  do{
    while(pivo.letters[0] > text->words[*i].letters[0]) (*i)++;
    while(pivo.letters[0] < text->words[*j].letters[0]) (*j)--;
    if(*i <= *j){
      ++(*comps);
      aux = text->words[*i]; ++(*moves);
      text->words[*i] = text->words[*j]; ++(*moves);
      text->words[*j] = aux; ++(*moves);
      (*i)++; (*j)--;
    }
  } while(*i <= *j);
}

void ordena(int left, int right, aText *text, long long *comps, long long *moves){
  int i, j;
  Partition(left, right, &i, &j, text, comps, moves);
  if(left<j){
    ordena(left, j, text, comps, moves);
    ++(*comps);
  } 
  if(i<right) {
    ordena(i, right, text, comps, moves);
    ++(*comps);
  } 
}

void quicksort(aText *text, long long *comps, long long *moves){
  ordena(0, text->size - 1, text, comps, moves);
}
