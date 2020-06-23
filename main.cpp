#include <iostream>
#include <stdlib.h>
#include "Terminal\Terminal.hpp"
#include "Clases\Sprite.hpp"
#include <windows.h>
#include <conio.h>

int main(){

	/*Main de pruebas*/
	Terminal t(50,10,'-','|','Q');
	Sprite jugador(3,3,2,2,"prueba",true);
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

			if(tecla == 'q'){
				jugador.disparar(&t,DERECHA,'>');
			}
		}
		jugador.mostrar(&t);
		jugador.moverBala(&t);

		Sleep(10);
	}
	return 0;
}