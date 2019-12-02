#include "../liblib/includes/aLib.h"

void Partition(int left, int right, int *i, int *j, Library *library){
  aText pivo, aux;
  *i = left; *j=right;
  pivo = library->texts[(*i+*j)/2];
  do{
    while(pivo.size > library->texts[*i].size) (*i)++;
    while(pivo.size < library->texts[*j].size) (*j)--;
    if(*i <= *j){
      aux = library->texts[*i];
      library->texts[*i] = library->texts[*j];
      library->texts[*j] = aux;
      (*i)++; (*j)--;
    }
  } while(*i <= *j);
}

void ordena(int left, int right, Library *library){
  int i, j;
  Partition(left, right, &i, &j, library);
  if(left<j) ordena(left, j, library);
  if(i<right) ordena(i, right, library);
}

void quicksort(Library *library){
  ordena(0, library->size-1, library);
}
