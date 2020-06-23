/**!<Bibliotecas necesarias*/
#include "Controles.hpp"

void Controles::movimiento(char Tecla, int *x, int *y, bool flechas){

	if(flechas){
		switch(Tecla){
			case ARRIBA:
				*y-=1;
				break;
			case IZQUIERDA:
				*x-=1;
				break;
			case ABAJO:
				*y+=1;
				break;
			case DERECHA:
				*x+=1;
				break;
		}

	}else{
		switch(Tecla){
			case 'w':
			case 'W':
				*y-=1;
				break;
			case 'a': 
			case 'A':
				*x-=1;
				break;
			case 's':
			case 'S':
				*y+=1;
				break;
			case 'd': 
			case 'D':
				*x+=1;
				break;
		}		
	}
}

void Controles::movimientoDeObjetos(int *x, int *y, char direccion){
	switch(direccion){
		case ARRIBA:
			*y-=1;
			break;
		case IZQUIERDA:
			*x-=1;
			break;
		case ABAJO:
			*y+=1;
			break;
		case DERECHA:
			*x+=1;
			break;
	}
}