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

void Controles::inversoDeMovimiento(char Tecla, int *x, int *y, bool flechas){
	if(flechas){
		switch(Tecla){
			case ARRIBA:
				this -> movimiento(ABAJO,x,y,flechas);
				break;
			case IZQUIERDA:
				this -> movimiento(DERECHA,x,y,flechas);
				break;
			case ABAJO:
				this -> movimiento(ARRIBA,x,y,flechas);
				break;
			case DERECHA:
				this -> movimiento(IZQUIERDA,x,y,flechas);
				break;
		}
	}else{
		switch(Tecla){
			case 'w':
			case 'W':
				this -> movimiento('s',x,y,flechas);
				break;
			case 'a':
			case 'A':
				this -> movimiento('d',x,y,flechas);
				break;
			case 's':
			case 'S':
				this -> movimiento('w',x,y,flechas);
				break;
			case 'd':
			case 'D':
				this -> movimiento('a',x,y,flechas);
				break;
		}
	}
}