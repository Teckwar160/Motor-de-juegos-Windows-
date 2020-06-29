#include <iostream>
#include <stdlib.h>
#include "Terminal\Terminal.hpp"
#include "Clases\Sprite.hpp"
#include <windows.h>
#include <conio.h>

int main(){

	/*Main de pruebas*/
	Terminal t(50,10);
	Sprite jugador(3,3,2,2,"prueba",true);
	Sprite muro(3,3,10,2,"muro");
	bool salida = true;
	t.pintarLimites();

	//Sprite arreglo[10];
	
	while(salida){

	t.ocultarCursor();
		if(kbhit()){
			
			char tecla = getch();

			jugador.mover(tecla,&t);

			if(tecla == 'c'){
				salida = false;
			}
			#if 1
			if(tecla == 'q'){
				jugador.disparar(&t,DERECHA,'>');
			}
			#endif
		}

		jugador.pintar(&t);
		muro.pintar(&t);
		jugador.moverBala(&t,&muro);

		Sleep(20);
	}
	return 0;
}