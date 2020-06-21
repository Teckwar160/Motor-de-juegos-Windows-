/**!<Guardas de inclusión*/
#ifndef SPRITE_HPP
#define SPRITE_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <fstream>
#include "Pixel.hpp"


/**
 *@class Clase que carga a los personajes del juego
 *
 *Nota: Los sprites deben de guardarse en un archivo .txt en la carpeta Sprites
 *      Al momento de crearlos solo introducir el nombre del archivo por ejemplo
 *      prueba.txt al crear el objeto seria Sprite(10,10,"prueba").
 */
class Sprite{
	private:
		/**!<Tamaño del Sprite en y*/
		int y;

		/**!<Tamaño del Sprite en x*/
		int x;

		/*Contenedor del Sprite*/
		char **sprite;

		/**!<Dirección del Sprite*/
		std::string direccion;

		/**!<Nombre del Sprite*/
		std::string nombre; 

		/**!<Pixel madre*/
		Pixel *madre;


	public:
		/**
		 *@brief Constructor de la clase.
		 *
		 *@param x Tamaño del Sprite en x.
		 *@param y Tamaño del Sprite en y.
		 *@param nombre Nombre del archivo que contiene al sprite sin extensión
		 *@param ignorar Este es el caracter de fondo se borrara al momento de
		 *cargar el sprite.
		 */
		Sprite(int x, int y, std::string nombre, char ignorar = '*');

		/**
		 *@brief Destructor de la clase
		 */
		~Sprite();

		/**
		 *@brief Método que muestra el sprite, unicamente se usa para ver si
		 *se cargo bien el sprite, no usar al momento de correr su juego.
		 */
		void mostrar();

};

#endif 