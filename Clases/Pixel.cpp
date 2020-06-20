#include "Pixel.hpp"


Pixel::Pixel(char pixel){
	this -> pixel = pixel;
}

Pixel::~Pixel(){
	/*Nada por el momento*/
}

void setPixel(char pixel){
	this -> pixel = pixel;
}

char getPixel(){
	return this -> pixel();
}

