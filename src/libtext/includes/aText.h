#include "../../libword/includes/aWord.h"

#ifndef TATEXT_H_
#define TATEXT_H_

typedef struct{
  Word *words;
  Size size;
  Size capacity;
}aText;

#endif

void initText(aText *text, Size length);
void insertWord(aText *aText, Word toAdd);
void removeWord(aText *text);
void printText(aText text);
int textSize(aText text);
void freeText(aText *text);
