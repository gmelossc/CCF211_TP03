#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genrand(int max_size_pal, int max_size_texto){
	int contaTexto = max_size_texto;
	srand(time(NULL));

	while (contaTexto > 1){
		// gera caracteres da tabela ASCII com letra minuscula,
		// 97 e 122 representam respectivamente 'a' e 'z' 
		int sizePalavra =  rand() % max_size_pal+1;
		for (int i = 0; i < sizePalavra; i++){
			char randChar = (rand() % (122 + 1 - 97) + 97);
			printf("%c",randChar);
		} printf("%d\n",sizePalavra);
		contaTexto--;
	}
}