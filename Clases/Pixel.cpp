#include "Pixel.hpp"


Pixel::Pixel(char Pixel){
	this -> Pixel = Pixel;
}

Pixel::~Pixel(){
	/*Nada por el momento*/
}

void setPixel(char Pixel){
	this -> Pixel = Pixel;
}

char getPixel(){
	return this -> Pixel();
}

