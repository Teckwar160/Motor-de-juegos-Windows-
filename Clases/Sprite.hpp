/**!<Guardas de inclusión*/
#ifndef SPRITE_HPP
#define SPRITE_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <fstream>
#include "Pixel.hpp"

/**!<Definicioens de las flechas del techado*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

/**
 *@class Clase que carga a los personajes del juego
 *
 *Nota: Los sprites deben de guardarse en un archivo .txt en la carpeta Sprites
 *      Al momento de crearlos solo introducir el nombre del archivo por ejemplo
 *      prueba.txt al crear el objeto seria Sprite jugador(10,10,"prueba").
 */
class Sprite{
	private:
		/**!<Tamaño del Sprite en y*/
		int y;

		/**!<Tamaño del Sprite en x*/
		int x;

		/**!<Posición del priemr pixel en y*/
		int pY;

		/**!<Posición del priemr pixel en x*/
		int pX;

		/**!<Activa las flechas del teclado para mover al personaje*/
		bool flechas;

		/**!<Dirección del Sprite*/
		std::string direccion;

		/**!<Nombre del Sprite*/
		std::string nombre; 

		/**!<Contenedor del sprite*/
		Pixel **sprite;

		/**
		 *@brief Métdodo que se encarga de borrar el rastro del Sprite.
		 *@param tablero Tablero del jeugo.
		 */
		void borrar(Terminal *tablero);

		/**
		 *@brief Método que se encarga de ver que el sprite siga en el tablero.
		 *@param tablero Tablero del juego.
		 */
		bool combrobadorDeLimites(Terminal *tablero);


	public:
		/**
		 *@brief Constructor de la clase.
		 *
		 *@param x Tamaño del Sprite en x.
		 *@param y Tamaño del Sprite en y.
		 *@param pX Posición del primer pixel en x.
		 *@param pY Posición del primer pixel en y.
		 *@param nombre Nombre del archivo que contiene al sprite sin extensión
		 *@param flechas Activa el movimento por las flechas del teclado.
		 *@param ignorar Este es el caracter de fondo se borrara al momento de
		 *cargar el sprite.
		 *@param fondo Este es el caracter de fondo que sustituira a ignorar.
		 */
		Sprite(int x, int y, int pX, int pY, std::string nombre,bool flechas = true, char ignorar = '*', char fondo = ' ');

		/**
		 *@brief Destructor de la clase
		 */
		~Sprite();

		/**
		 *@brief Método que muestra el sprite, unicamente se usa para ver si
		 *se cargo bien el sprite, no usar al momento de correr su juego.
		 *@param cursor Apuntador a un objeto terminal, solo para usar gotoxy.
		 */
		void mostrar(Terminal *cursor);

		/**
		*@brief Método que se encarga de mover al Sprite.
		*@param Tecla Tecla que se puslo para mover al sprite.
		*@param tablero Tablero del juego.
		*/
		void mover(char Tecla, Terminal *tablero);

};

#endif 