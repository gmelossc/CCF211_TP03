#include "../libtext/includes/aText.h"

void selectionSort(aText *text){
  int i, j, min;
  Word aux;
  for(i=0; i<text->size -1; i++){
    min =i;
    for(j = i+1; j< text->size; j++)
    if(text->words[j].letters[0] < text->words[min].letters[0]) min = j;
    aux = text->words[min];
    text->words[min] = text->words[i];
    text->words[i] = aux;
  }
}
