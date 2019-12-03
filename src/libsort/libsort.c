#include "../liblib/includes/aLib.h"

void libSelectionSort(Library *library, int *count, int *moves){
  int i, j, min;
  aText aux;
  for(i=0; i< library->size -1; i++){
    min =i;
    for(j = i+1; j< library->size; j++)
    if(library->texts[j].size < library->texts[min].size){
      min = j;
      ++(*count);
    } 
    aux = library->texts[min]; ++(*moves);
    library->texts[min] = library->texts[i]; ++(*moves);
    library->texts[i] = aux; ++(*moves);
  }
}
