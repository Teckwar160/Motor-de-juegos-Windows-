/**!<Bibliotecas necesarias*/
#include "Sprite.hpp"
#include "..\Terminal\Terminal.hpp"

/***************************************
 *	Métodos privados
 **************************************/
void Sprite::liberaBala(Sprite *B){
	delete B;
}

void Sprite::borrar(Terminal *cursor){
	cursor -> gotoxy(this -> pX,this -> pY);

	for(int i = 0; i<this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			cursor -> gotoxy(this -> sprite[i][j].getX(),this -> sprite[i][j].getY());
			std::cout <<" ";
		}
	}	
}

bool Sprite::combrobadorDeLimites(Terminal *tablero){

	for(int i = 0; i<this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			if(this -> sprite[i][j].getX() >= tablero -> getLargo() || this -> sprite[i][j].getX() == 0){
				return true;
			}

			if(this -> sprite[i][j].getY() >= tablero -> getAlto() || this -> sprite[i][j].getY() == 0){
				return true;
			}			
		}
	}

	return false;
}


/***************************************
 * 	Métodos publicos
 **************************************/

Sprite::Sprite(int x, int y, int pX, int pY, std::string nombre, bool disparo, bool flechas, char ignorar, char fondo){

	/*Guardamos datos basicos*/
	this -> x = x;
	this -> y = y;
	this -> pX = pX;
	this -> pY = pY;
	this -> nombre = nombre;
	this -> disparo = disparo;
	this -> flechas = flechas;
	this -> direccion = "Sprites\\"+ nombre + ".txt";

	/*Si se desea que tenga la capacidad de disparar*/
	if(this -> disparo){
		this -> contenedor = new DLL<Sprite*>();
	}
	

	/*Variable que leé el Sprite*/
	std::ifstream sprite;

	sprite.open(direccion,std::ios::in);

	char tmp;

	if(!sprite.fail()){
		/*Creamos al contenedor del Sprite*/
		this -> sprite = new Pixel*[this -> y];

		for(int i = 0; i<y; i++){
			this -> sprite[i] = new Pixel[x];
		}

		for(int i = 0; i<y; i++){
			for(int j = 0; j<x; j++){
				sprite >> tmp;
				this ->sprite[i][j].setPixel(tmp);  
			}
		}		
	}else{
		std::cout << "Fallo #0" << std::endl;
	}

	sprite.close();

	/*Ahora quitamos el fondo del sprite*/
	for(int i = 0; i< this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			if(this -> sprite[i][j].getPixel() == ignorar){
				this -> sprite[i][j].setPixel(fondo);
			}
		}
	}

	/*Definimos las coordenadas de cada pixel*/
	for(int i = 0; i< this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			this -> sprite[i][j].setX(pX +j);
			this -> sprite[i][j].setY(pY+i);
		}
	}
}

Sprite::~Sprite(){
	/*Liberamos la memoria solicitada*/
	for(int i = 0; i< this -> y; i++){
		delete this -> sprite[i];
	}

	delete[] this -> sprite;

	if(this -> disparo){

		if(this -> contenedor -> Len() > 0){
			this -> contenedor -> Traverse(this -> liberaBala);
		}

		delete contenedor;
	} 
}

void Sprite::mostrar(Terminal *cursor){

	cursor -> gotoxy(this -> pX,this -> pY);

	/*Muestar el sprite en pantalla*/
	for(int i = 0; i<this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			cursor -> gotoxy(this -> sprite[i][j].getX(),this -> sprite[i][j].getY());
			std::cout << this -> sprite[i][j].getPixel();
		}
		std::cout << std::endl;
	}
}


void Sprite::mover(char Tecla,Terminal *tablero){

	/*Borra al viejo sprite*/
	this -> borrar(tablero);

	/*Guardamos las coordenadas del sprite*/
	int x = this -> sprite[0][0].getX();
	int y = this -> sprite[0][0].getY();

	int tmpX = x;
	int tmpY = y;

	/*Controles del Sprite*/
	this -> movimiento(Tecla,&x,&y,this -> flechas);


	/*Actualiza la posición*/
	for(int i = 0; i< this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			this -> sprite[i][j].setX(x +j);
			this -> sprite[i][j].setY(y+i);
		}
	}
	
	/*Evita que se salga de los limites del tablero*/
	if(this -> combrobadorDeLimites(tablero)){
		for(int i = 0; i< this -> y; i++){
			for(int j = 0; j< this -> x; j++){
				this -> sprite[i][j].setX(tmpX +j);
				this -> sprite[i][j].setY(tmpY+i);
			}
		}		
	}

}

void Sprite::setDireccion(char direccion){
	this -> direc = direccion;
}

char Sprite::getDireccion(){
	return this -> direc;
}

void Sprite::disparar(Terminal *tablero, char direccion, char pDisparo){

	/*Obtener el lugar de disparo*/
	int x;
	int y;
	

	/*Localizamos el punto o los puntos que dispararan*/
	for(int i = 0; i< this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			if(this -> sprite[i][j].getPixel() == pDisparo){

				switch(direccion){
					case DERECHA:
						x = this -> sprite[i][j].getX() +1;
						y = this -> sprite[i][j].getY();
						break;
				}

				/*Creamos a la bala*/
				Sprite *B = new Sprite(1,1,x,y,"Bala");

				/*Le damos una dirección*/
				B -> setDireccion(direccion);

				/*Mostramos la bala*/
				B -> mostrar(tablero);

				/*La agregamos al contenedor*/
				this -> contenedor -> InsertBack(B);
				
			}
		}
	}
}

void Sprite::moverBala(Terminal *tablero){

	/*Variables necesarias*/
	Sprite *tmp;
	int x;
	int y;
	int tmpX;
	int tmpY;

	/*Nos colocamos en la primer bala*/
	this -> contenedor -> CursorFirst();

	/*Recorremos todas las balas*/
	for(int i = this -> contenedor -> Len(); i> 0; i--){

		/*Obtenemos la bala*/
		this -> contenedor -> Peek(&tmp);

		/*La borramos*/
		tmp -> borrar(tablero);

		/*Guardamos su posición*/
		x = tmpX = tmp -> sprite[0][0].getX();
		y = tmpY = tmp -> sprite[0][0].getY();

		/*Actualizamos su posición dependiendo la dirección*/
		this -> movimientoDeObjetos(&x,&y,tmp -> getDireccion());

		/*Actualizamos a la bala*/
		tmp -> sprite[0][0].setX(x);
		tmp -> sprite[0][0].setY(y);

		/*Evita que se salga de los limites del tablero*/
		if(tmp -> combrobadorDeLimites(tablero)){

			/*La regresamos (Solo para evitar que borre los limites del tablero)*/
			tmp -> sprite[0][0].setX(tmpX);
			tmp -> sprite[0][0].setY(tmpY);	

			/*La borramos*/
			tmp -> borrar(tablero);	
			this -> contenedor -> Remove(&tmp);
			delete tmp;

			break;

		}else{

			/*Si sigue en el tablero la mostramos*/
			tmp -> mostrar(tablero);
		}

		/*Pasamos a la siguiente bala*/
		this -> contenedor -> CursorNext();
	}

}
