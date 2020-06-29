/**!<Bibliotecas necesarias*/
#include "Sprite.hpp"
#include "..\Terminal\Terminal.hpp"

/***************************************
 *	Métodos privados
 **************************************/
void Sprite::liberaBala(Sprite *B){
	delete B;
}


bool Sprite::combrobadorDeLimites(Terminal *tablero){

	for(int i = 0; i< this -> tam; i++){
		if(this -> sprite[i].getX()>= tablero -> getLargo() || this -> sprite[i].getX() == 0){
			return true;
		}

		if(this -> sprite[i].getY() >= tablero -> getAlto() || this -> sprite[i].getY() == 0){
			return true;
		}
	}

	return false;
}

/***************************************
 * 	Métodos publicos
 **************************************/

Sprite::Sprite(int x, int y, int pX, int pY, std::string nombre, bool disparo, bool flechas, char ignorar, char fondo){

	/*Guardamos datos basicos*/
	this -> tam = x*y;
	this -> nombre = nombre;
	this -> disparo = disparo;
	this -> flechas = flechas;
	this -> ignorar = ignorar;
	this -> fondo = fondo;
	this -> direccion = "Sprites\\"+ nombre + ".txt";

	/*Si se desea que tenga la capacidad de disparar*/
	if(this -> disparo){
		this -> contenedor = new DLL<Sprite*>();
	}
	

	/*Variable que leé el Sprite*/
	std::ifstream sprite;

	sprite.open(direccion,std::ios::in);

	/*Varibales temporales*/
	char tmp;
	Pixel **sprite_tmp;


	if(!sprite.fail()){
		/*Creamos al contenedor del Sprite*/
		sprite_tmp = new Pixel*[y];

		for(int i = 0; i<y; i++){
			sprite_tmp[i] = new Pixel[x];
		}

		for(int i = 0; i<y; i++){
			for(int j = 0; j<x; j++){
				sprite >> tmp;
				sprite_tmp[i][j].setPixel(tmp);  
			}
		}		
	}else{
		std::cout << "Fallo #0" << std::endl;
	}

	sprite.close();

	/*Ahora quitamos el fondo del sprite*/
	for(int i = 0; i<y; i++){
		for(int j = 0; j<x; j++){
			if(sprite_tmp[i][j].getPixel() == ignorar){
				this -> tam-= 1;
			}
		}
	}

	/*Definimos las coordenadas de cada pixel*/
	for(int i = 0; i<y; i++){
		for(int j = 0; j<x; j++){
			sprite_tmp[i][j].setX(pX +j);
			sprite_tmp[i][j].setY(pY+i);
		}
	}

	/*Creamos el vector que contendra el sprite*/
	this -> sprite = new Pixel[this -> tam];

	/*Iterador*/
	int k=0;

	/*Pasamos de una matriz de R^2 a un vector de R*/
	for(int i = 0; i<y; i++){
		for(int j = 0; j<x; j++){
			if(sprite_tmp[i][j].getPixel() != ignorar){
				this -> sprite[k].setPixel(sprite_tmp[i][j].getPixel());
				this -> sprite[k].setX(sprite_tmp[i][j].getX());
				this -> sprite[k].setY(sprite_tmp[i][j].getY());
				k++;
			}
		}
	}

	/*Liberamos la memoria del sprite_tmp*/
	for(int i = 0; i< y; i++){
		delete sprite_tmp[i];
	}

	delete[] sprite_tmp;


}

Sprite::Sprite(bool disparo,bool flechas, char ignorar, char fondo){
	this -> disparo = disparo;
	this -> flechas = flechas;
	this -> ignorar = ignorar;
	this -> fondo = fondo;
}

Sprite::~Sprite(){

	delete[] this -> sprite;

	if(this -> disparo){

		if(this -> contenedor -> Len() > 0){
			this -> contenedor -> Traverse(this -> liberaBala);
		}

		delete contenedor;
	} 
}

void Sprite::pintar(Terminal *cursor, bool borrar){

	/*Pone en cursor en el primer pixel del sprite*/
	cursor -> gotoxy(this -> sprite[0].getX() , this -> sprite[0].getY());

	/*Muestra el sprite en pantalla*/
	for(int i = 0;  i< this -> tam; i++){
		cursor -> gotoxy(this -> sprite[i].getX(), this -> sprite[i].getY());

		if(!borrar){
			std::cout << this -> sprite[i].getPixel();
		}else{
			std::cout << this -> fondo;
		}
		
	}	
}


void Sprite::mover(char Tecla,Terminal *tablero){

	/*Variables temporales*/
	int x;
	int y;

	/*Borra al viejo sprite*/
	this -> pintar(tablero,true);

	/*Recorremos a los pixeles*/
	for(int i = 0; i< this -> tam; i++){

		/*Obtenemos las coordenadas actuales*/
		x = this -> sprite[i].getX();
		y = this -> sprite[i].getY();

		/*Las asctualizamos*/
		this -> movimiento(Tecla,&x,&y,this -> flechas);

		sprite[i].setX(x);
		sprite[i].setY(y);
	}

	/*Verificamos que no se salga del tablero*/
	if(this -> combrobadorDeLimites(tablero)){
		for(int i = 0; i< this -> tam; i++){

			/*Obtenemos las coordenadas actuales*/
			x = this -> sprite[i].getX();
			y = this -> sprite[i].getY();

			/*Las regresamos a las viejas coordenadas*/
			this -> inversoDeMovimiento(Tecla,&x,&y,this -> flechas);

			sprite[i].setX(x);
			sprite[i].setY(y);
		}		
	}
}

void Sprite::disparar(Terminal *tablero, char direccion, char pDisparo){
	/*Variables temporales*/
	int x;
	int y;

	/*Localizamos el punto o los puntos que dispararan*/
	for(int i = 0; i< this -> tam; i++){
		if(this -> sprite[i].getPixel() == pDisparo){
			x = this -> sprite[i].getX();
			y = this -> sprite[i].getY();

			/*Obtenemos la posición de la bala*/
			this -> movimientoDeObjetos(&x,&y,direccion);

			/*Creamos a la bala*/
			Sprite *B = new Sprite(1,1,x,y,"Bala");

			/*Le damos una dirección*/
			B -> setDireccion(direccion);

			/*Mostramos la bala*/
			B -> pintar(tablero);

			/*La agregamos al contenedor*/
			this -> contenedor -> InsertBack(B);			
		}
	}
}

void Sprite::moverBala(Terminal *tablero, Sprite *otro){
	/*Variables temporales*/
	Sprite *B;
	int x;
	int y;

	/*Nos colocamos en la primer bala*/
	this -> contenedor -> CursorFirst();

	/*Recorremos todas las balas*/
	for(int i = this -> contenedor -> Len(); i> 0; i--){
		
		/*Obtenemos la bala*/
		this -> contenedor -> Peek(&B);

		/*La borramos */
		B -> pintar(tablero,true);

		/*Guardamos su posición*/
		x = B -> sprite[0].getX();
		y = B -> sprite[0].getY();

		/*Actualizamos su posición dependiendo la dirección*/
		this -> movimientoDeObjetos(&x,&y, B -> getDireccion());

		/*Actualizamos la bala*/
		B -> sprite[0].setX(x);
		B -> sprite[0].setY(y);

		/*Evita que se salga del tablero o si choco con algo*/
		if(B -> combrobadorDeLimites(tablero) || B -> comprobadorDeColision(otro)){

			/*La borramos*/
			this -> contenedor -> Remove(&B);
			delete B;
			break;

		}else{

			/*Si sigue en el tablero la mostramos*/
			B -> pintar(tablero);
		}

		/*Pasamos a la siguiente bala*/
		this -> contenedor -> CursorNext();
	}	
}

bool Sprite::comprobadorDeColision(Sprite *otro){

	/*Recorremos al sprite 1*/
	for(int i = 0; i< this -> tam; i++){
		
		/*Recorremos al sprite 2*/	
		for(int j = 0; j< otro -> tam; j++){

			/*Vemos si estan en las mismas coordenadas*/
			if(this -> sprite[i].getX() == otro -> sprite[j].getX()){
				if(this -> sprite[i].getY() == otro -> sprite[j].getY()){
					return true;
				}
			}
		}
	}

	return false;
}

/***************************************
 *	Setters y getters
 **************************************/

void Sprite::setNombre(std::string nombre){
	this -> nombre = nombre;
}

void Sprite::setDisparo(bool disparo){
	this -> disparo = disparo;
}

void Sprite::setFlechas(bool flechas){
	this -> flechas = flechas;
}

void Sprite::setIgnorar(char ignorar){
	this -> ignorar = ignorar;
}

void Sprite::setFondo(char fondo){
	this -> fondo = fondo;
}

void Sprite::setDireccion(char direccion){
	this -> direc = direccion;
}

char Sprite::getDireccion(){
	return this -> direc;
}

Pixel *Sprite::getSprite(){
	return this -> sprite;
}