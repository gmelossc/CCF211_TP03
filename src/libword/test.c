#include "includes/aWord.h"

int main(){
  t_word W;
  char toAdd;

  initWord(&W);
  while((scanf("%c", &toAdd) != EOF) && toAdd != '\n'){
    insertChar(&W, toAdd);
  }
  removeChar(&W);
  printWord(W);
  freeWord(&W);

  return 0;
}
