#include "../../libword/includes/aWord.h"

#ifndef TATEXT_H_
#define TATEXT_H_

typedef struct{
  Word *words;
  Size size;
  Size capacity;
}Text;

#endif

void initText(Text *text, Size length);
void insertWord(Text *text);
void removeWord(Text *text);
void printText(Text text);
int textSize(Text text);
void freeText(Text *text);
