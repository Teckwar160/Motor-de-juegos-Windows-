/**!<Bibliotecas necesarias*/
#include "Sprite.hpp"

Sprite::Sprite(int x, int y, std::string nombre, char ignorar){

	/*Guardamos datos basicos*/
	this -> x = x;
	this -> y = y;
	this -> nombre = nombre;
	this -> direccion = "Sprites\\"+ nombre + ".txt";

	/*Variable que leé el Sprite*/
	std::ifstream sprite;

	sprite.open(direccion,std::ios::in);

	if(!sprite.fail()){
		/*Creamos al contenedor del Sprite*/
		this -> sprite = new char*[this -> y];

		for(int i = 0; i<y; i++){
			this -> sprite[i] = new char[x];
		}

		for(int i = 0; i<y; i++){
			for(int j = 0; j<x; j++){
				sprite >> this ->sprite[i][j];  
			}
		}		
	}else{
		std::cout << "Fallo #0" << std::endl;
	}

	sprite.close();

	/*Ahora quitamos el fondo del sprite*/
	for(int i = 0; i< this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			if(this -> sprite[i][j] == ignorar){
				this -> sprite[i][j] = ' ';
			}
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

void Sprite::mostrar(){

	/*Muestar el sprite en pantalla*/
	for(int i = 0; i<this -> y; i++){
		for(int j = 0; j< this -> x; j++){
			std::cout << this -> sprite[i][j];
		}
		std::cout << std::endl;
	}
}