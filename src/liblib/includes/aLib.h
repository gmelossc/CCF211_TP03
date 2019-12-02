#include "../../libtext/includes/aText.h"
#ifndef TALIB_H_
#define TALIB_H_

typedef struct{
  aText *texts;
  Size size;
}Library;

#endif

void initLib(Library *library, Size length);
void insertText(Library *library, aText toAdd, int thatText);
void removeText(Library *library);
void printLib(Library library);
int libSize(Library library);
void freeLib(Library *library);
