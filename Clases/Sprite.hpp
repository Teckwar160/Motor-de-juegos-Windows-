/**!<Guardas de inclusión*/
#ifndef SPRITE_HPP
#define SPRITE_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <fstream>
#include "Pixel.hpp"
#include "Controles.hpp"
#include "..\Terminal\Terminal.hpp"
#include "DLL.hpp"


/**
 *@class Clase que carga a los personajes del juego
 *
 *Nota: Los sprites deben de guardarse en un archivo .txt en la carpeta Sprites
 *      Al momento de crearlos solo introducir el nombre del archivo por ejemplo
 *      prueba.txt al crear el objeto seria Sprite jugador(10,10,"prueba").
 */
class Sprite : public Controles{
	private:
		/**!<Tamaño del Sprite en y*/
		int y;

		/**!<Tamaño del Sprite en x*/
		int x;

		/**!<Posición del priemr pixel en y*/
		int pY;

		/**!<Posición del priemr pixel en x*/
		int pX;

		/**!<Activa la opcón de disparar*/
		bool disparo;

		/**!<Activa las flechas del teclado para mover al personaje*/
		bool flechas;

		/**!<Dirección del Sprite*/
		std::string direccion;

		/**!<Nombre del Sprite*/
		std::string nombre; 

		/**!<Contenedor del sprite*/
		Pixel **sprite;

		/**!<Contenedor de las balas (Si es que quiere usar esta opción)*/
		DLL<Sprite*> *contenedor;

		/**!<Dirección de un objeto en movimiento(Si es que se quiere usar esta opción)*/
		char direc;

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

		/**
		 * @brief Método que libera la memoria de las balas.
		 * @param B Bala que se liberara la memoria.
		 */
		static void liberaBala(Sprite *B);

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
		Sprite(int x, int y, int pX, int pY, std::string nombre,bool disparo = false,bool flechas = true, char ignorar = '*', char fondo = ' ');

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

		/**
		 *@brief Método que se encarga de hacer existir a la bala.
		 *@param tablero Tablero del juego.
		 *@param direccion Dirección en la cual se movera la bala.
		 *@param pDisparo Caracter por el cual saldrán las balas.
		 */
		void disparar(Terminal*tablero, char direccion, char pDisparo);

		/**
		 *@brief Método que mueve a las balas.
		 *@param tablero Tablero del juego.
		 */
		void moverBala(Terminal *tablero);

		/**
		 *@brief Método que se encarga de dar una dirección a los objetos que se muevan solos.
		 *@param Dirección en la que se moveran lso objetos.
		 */
		void setDireccion(char direccion);

		/**
		 *@brief Método que regresara el sentido en el cual se mueven los objetos.
		 */
		char getDireccion();

};

#endif 