#include <stdlib.h>
#include <stdio.h>
#include "word.h"

int main(){
	TWord palA,palB,palC;
	Inicializa(&palA);
	Inicializa(&palB);
	Inicializa(&palC);
	AddNoFim(&palA,'v');
	PrintTam(&palA);
	AddNoFim(&palA,'a');
	PrintTam(&palA);
	AddNoFim(&palA,'m');
	PrintTam(&palA);
	AddNoFim(&palA,'o');
	PrintTam(&palA);
	AddNoFim(&palA,'s');
	PrintTam(&palA);
	PrintPal(&palA);
	RemDoFim(&palA);
	PrintPal(&palA);
	RemDoFim(&palA);
	PrintPal(&palA);
}