#include "includes/aLib.h"

int main(){
  Library library;

  initLib(&library, 1);
  insertText(&library);
  printLib(library);
  freeLib(&library);
  initLib(&library, 1);
  insertText(&library);
  printLib(library);
  freeLib(&library);
  return 0;
}
