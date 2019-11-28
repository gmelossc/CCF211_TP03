#include "gerarand.c"

int main(){
	Text meuText;
	meuText = geraTexto(10,10);
	PrintTexto(&meuText);
	TamanhoTexto(&meuText);
}
