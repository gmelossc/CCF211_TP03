#include "gerarand.c"
#include "selectSorts.c"
#include "quickSorts.c"

int main(){
	IniSeed();// IniSeed TEM QUE ser chamada antes da criação de qualquer unidade pseudo-aleatória
	/*Text on;
	Inicia(&on);
	on = geraTexto(10000,10);
	on.initial = encaTextoSelectionSort(on.initial);
	PrintTexto(&on);*/
	Libery lib, sLib;
	Text t1,t2,t3,t4,t5;
	IniciaLibery(&lib);

	
	t1 = geraTexto(5,10);
	t2 = geraTexto(4,10);
	t3 = geraTexto(3,10);
	t4 = geraTexto(3,10);
	t5 = geraTexto(2,10);
	PrintTexto(&t1);
	encaQuickSort(t1.initial);
	PrintTexto(&t1);
	/*InsereLibery(&lib,&t1);
	InsereLibery(&lib,&t2);
	InsereLibery(&lib,&t3);
	InsereLibery(&lib,&t4);
	InsereLibery(&lib,&t5);
	sLib.initial = encaBiblioSelectionSort(lib.initial);
	//PrintLibery(&sLib);*/
}
