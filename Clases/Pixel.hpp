/**!<Guardas de inclusión*/
#ifndef PIXEL_HPP
#define PIXEL_HPP

/**!<Bibliotecas necesarias*/
#include "..\Terminal\Terminal.hpp"
#include <iostream>

class Pixel{
	private:
		char pixel;
		int x;
		int y;
	public:
		Pixel(char pixel);
		~Pixel();
		void setPixel(char pixel);
		char getPixel();
};

#endif