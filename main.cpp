#include <iostream>
#include <stdlib.h>
#include "Terminal\Terminal.hpp"
#include "Clases\Sprite.hpp"
#include <windows.h>
#include <conio.h>

int main(){

	/*Main de pruebas*/
	Terminal t(50,10,'-','|','Q');
	Sprite jugador(1,1,2,2,"prueba",false);
	bool salida = true;
	t.pintarLimites();


	while(salida){

	t.ocultarCursor();
		if(kbhit()){
			
			char tecla = getch();

			jugador.mover(tecla,&t);

			if(tecla == 'c'){
				salida = false;
			}
		}
		jugador.mostrar(&t);
	}
	return 0;
}