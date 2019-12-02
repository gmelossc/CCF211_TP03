#include "../liblib/includes/aLib.h"

void selectionSort(Library *library){
  int i, j, min;
  aText aux;
  for(i=0; i< library->size -1; i++){
    min =i;
    for(j = i+1; j< library->size; j++)
    if(library->texts[j].size < library->texts[min].size) min = j;
    aux = library->texts[min];
    library->texts[min] = library->texts[i];
    library->texts[i] = aux;
  }
}
