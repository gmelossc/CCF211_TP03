#include <stdio.h>
#include <stdlib.h>

#ifndef TAWORD_H_
#define TAWORD_H_

#define MAXW 100

typedef int Size;

typedef struct{
  char *letters;
  Size size;
}Word;

#endif

void allocWord(char **letters);
void initWord(Word *W);
int insertCharToWord(char **letters, char toAdd, int pos);
void insertChar(Word *W, char toAdd);
void removeChar(Word *W);
int wordSize(Word W);
void printWord(Word W);
void freeWord(Word *W);
