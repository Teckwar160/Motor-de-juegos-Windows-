#include "Pixel.hpp"


Pixel::Pixel(char pixel){
	this -> pixel = pixel;
}

Pixel::~Pixel(){
	/*Nada por el momento*/
}

void Pixel::setPixel(char pixel){
	this -> pixel = pixel;
}

void Pixel::setX(int x){
	this -> x = x;
}

void Pixel::setY(int y){
	this -> y = y;
}

char Pixel::getPixel(){
	return this -> pixel;
}

int Pixel::getX(){
	return this -> x;
}

int Pixel::getY(){
	return this -> y;

}

