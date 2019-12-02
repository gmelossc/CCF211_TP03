#include "includes/aText.h"

int main(){
  Text text;
  initText(&text, 1);
  insertWord(&text);
  printText(text);
  removeWord(&text);
  printText(text);
  freeText(&text);
  return 0;
}
