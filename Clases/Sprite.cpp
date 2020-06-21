/**!<Bibliotecas necesarias*/
#include "Sprite.hpp"
#include "..\Terminal\Terminal.hpp"

Sprite::Sprite(int x, int y, int pX, int pY, std::string nombre, bool flechas, char ignorar, char fondo){

	/*Guardamos datos basicos*/
	this -> x = x;
	this -> y = y;
	this -> pX = pX;
	this -> pY = pY;
	this -> nombre = nombre;
	this -> flechas = flechas;
	this -> direccion = "Sprites\\"+ nombre + ".txt";

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

void Sprite::borrar(Terminal *cursor){
	cursor -> gotoxy(this -> pX,this -> pY);

	/*Muestar el sprite en pantalla*/
	for(int i = 0; i<this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			cursor -> gotoxy(this -> sprite[i][j].getX(),this -> sprite[i][j].getY());
			std::cout <<" ";
		}
		std::cout << std::endl;
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

void Sprite::mover(char Tecla,Terminal *tablero){

	/*Borra al viejo sprite*/
	this -> borrar(tablero);

	/*Guardamos las coordenadas del sprite*/
	int x = this -> sprite[0][0].getX();
	int y = this -> sprite[0][0].getY();

	int tmpX = x;
	int tmpY = y;

	/*Controles del Sprite*/
	if(flechas){
		switch(Tecla){
			case ARRIBA:
				y--;
				break;
			case IZQUIERDA:
				x--;
				break;
			case ABAJO:
				y++;
				break;
			case DERECHA:
				x++;
				break;
		}		
	}else{
		switch(Tecla){
			case 'w':
			case 'W':
				y--;
				break;
			case 'a': 
			case 'A':
				x--;
				break;
			case 's':
			case 'S':
				y++;
				break;
			case 'd': 
			case 'D':
				x++;
				break;
		}		
	}


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