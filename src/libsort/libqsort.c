#include "../liblib/includes/aLib.h"

void libPartition(int left, int right, int *i, int *j, Library *library, long long *count, long long *moves){
  aText pivo, aux;
  *i = left; *j=right;
  pivo = library->texts[(*i+*j)/2];
  do{
    while(pivo.size > library->texts[*i].size) (*i)++;
    while(pivo.size < library->texts[*j].size) (*j)--;
    if(*i <= *j){
      ++(*count);
      aux = library->texts[*i]; ++(*moves);
      library->texts[*i] = library->texts[*j]; ++(*moves);
      library->texts[*j] = aux; ++(*moves);
      (*i)++; (*j)--;
    }
  } while(*i <= *j);
}

void libOrdena(int left, int right, Library *library, long long *count, long long *moves){
  int i, j;
  libPartition(left, right, &i, &j, library, count, moves);
  if(left<j){
    libOrdena(left, j, library, count, moves);
    ++(*count);
  } 
  if(i<right){
    libOrdena(i, right, library, count, moves);
    ++(*count);
  } 
}

void libQuicksort(Library *library, long long *count, long long *moves){
  libOrdena(0, library->size-1, library, count, moves);
}
