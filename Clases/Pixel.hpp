/**!<Guardas de inclusión*/
#ifndef PIXEL_HPP
#define PIXEL_HPP

/**!<Bibliotecas necesarias*/
#include "Terminal.hpp"
#include <iostream>

class Pixel{
	private:
		char Pixel;
		int x;
		int y;
	public:
		Pixel(char Pixel);
		~Pixel();
		void setPixel(char Pixel);
		char getPixel();
};

#endif