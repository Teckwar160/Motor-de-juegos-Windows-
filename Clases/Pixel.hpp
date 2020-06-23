/**!<Guardas de inclusión*/
#ifndef PIXEL_HPP
#define PIXEL_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>

/**
 *@class Clase que define cada pixel del juego.
 */
class Pixel{
	private:
		/**<Caracter inidivdual del pixel*/
		char pixel;

		/**!<Coordenada en x del pixel*/
		int x;

		/**!<coordenada en y del pixel*/
		int y;

	public:
		/**
		 *@brief Método cosntructor de Pixel.
		 */
		Pixel();

		/**
		 *@brief Método destructor del pixel.
		 */
		~Pixel();

		/**
		 *@brief Método que redefine el caracter del pixel.
		 */
		void setPixel(char pixel);

		/**
		 *@brief Método que redefine la coordena en x del pixel.
		 *@param x Nueva coordena en x.
		 */
		void setX(int x);

		/**
		 *@brief Método que redefine la coordena en y del pixel.
		 *@param y Nueva coordena en y.
		 */
		void setY(int y);

		/**
		 *@brief Método que retorna el caracter del pixel.
		 */
		char getPixel();

		/**
		 *@brief Método que retorna la coordena en x del pixel.
		 */
		int getX();

		/**
		 *@brief Método que retorna la coordena en y del pixel.
		 */
		int getY();
};

#endif