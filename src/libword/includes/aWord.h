#include <stdio.h>
#include <stdlib.h>
#ifndef TAWORD_H_
#define TAWORD_H_

#define MAXW 100

typedef char Word;
typedef int Size;

typedef struct{
  Word *word;
  Size size;
}t_word;

#endif

void allocWord(Word **word);
void initWord(t_word *W);
int insertCharToWord(Word **word, char toAdd, int pos);
void insertChar(t_word *W, char toAdd);
void removeChar(t_word *W);
int wordSize(t_word W);
void printWord(t_word W);
