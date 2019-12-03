#include "../libtext/includes/aText.h"

void selectionSort(aText *text, long long *comps, long long *moves){
  int i, j, min;
  Word aux;
  for(i=0; i<text->size -1; i++){
    min =i;
    for(j = i+1; j< text->size; j++)
    if(text->words[j].letters[0] < text->words[min].letters[0]){
      min = j;
      ++(*comps);
    } 
    aux = text->words[min]; ++(*moves);
    text->words[min] = text->words[i]; ++(*moves);
    text->words[i] = aux; ++(*moves);
  }
}
