#include "libinterface/interface.c"

int main(){
	//Interface();
	IniSeed();
	aText novot; 
	Word novaw;
	Library noval;
	novaw = geraPalavraVet();
	novot = geraTextoVet(2);
	noval = geraLibraryVet(1,2);
	//printWord(novaw);
	//printText(novot);
	printf("Lib:\n");
	printLib(noval);
}
