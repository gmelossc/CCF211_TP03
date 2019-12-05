#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libword/encaWord.c"
#include "libword/aWord.c"
#include "libtext/encaText.c"
#include "libtext/aText.c"
#include "liblib/encaLib.c"
#include "liblib/aLib.c"

void IniSeed(){
	srand(time(NULL));
}

TWord *auxFunction(){
	TWord myword;
	TWord *pword;
	Inicializa(&myword);
	AddNoFim(&myword,97);
	pword = &myword;
	return pword;
}

TWord geraPalavra(int max_size_pal){
	TWord minhaWord;
	Inicializa(&minhaWord);
	int sizePalavra =  rand() % max_size_pal+1;
	// gera caracteres da tabela ASCII com letra minuscula,
	// 97 e 122 representam respectivamente 'a' e 'z' 
	for (int i = 0; i < sizePalavra; i++){
		char randChar = (rand() % (122 + 1 - 97) + 97);
		AddNoFim(&minhaWord,randChar);
	} 
	return minhaWord;
}

Text geraTexto(int max_size_texto,int max_size_pal,int min_size_texto){
	Text meuTexto;
	Inicia(&meuTexto);
	InsereTexto(&meuTexto,auxFunction());
	for (int i = 0; i < rand() % (max_size_texto+1-min_size_texto)+min_size_texto; i++){
		TWord novaWord = geraPalavra(max_size_pal);
		InsereTexto(&meuTexto,&novaWord);
	}
	return meuTexto;
}

Libery geraBiblio(int total_textos,int size_texto,int max_size_pal, int min_size_texto){
	Libery myLib;
	IniciaLibery(&myLib);
	for (int i = 0; i < total_textos; i++){
		Text novoTexto = geraTexto(size_texto,max_size_pal,min_size_texto);
		InsereLibery(&myLib,&novoTexto);
	}
	return myLib;
}

Word geraPalavraVet(){
	Word newWord;
	initWord(&newWord);
	for (int i = 0; i < rand() % 101; i++){
		char randChar = (rand() % (122 + 1 - 97) + 97);
		insertChar(&newWord,randChar);
	}
	return newWord;
}

aText geraTextoVet(int size_texto, int min_size_texto){
	aText newText;
	initText(&newText,size_texto);
	for (int i = 0; i < rand() % (newText.capacity+1-min_size_texto)+min_size_texto; ++i){
			Word randWord = geraPalavraVet();
			insertWord(&newText, randWord);
	}
	printf("Tamanho do texto: %d\n\n", newText.size);
	return newText;
}

Library geraLibraryVet(int index_textos, int size_texto, int min_size_texto){
	Library newLib;
	initLib(&newLib, index_textos);
	for (int i = 0; i < newLib.size; ++i){
		aText randText = geraTextoVet(size_texto, min_size_texto);
		printText(randText);
		insertText(&newLib,randText, i);
	}
	return newLib;
}
