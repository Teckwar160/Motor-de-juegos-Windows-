/**!<Guardas de inclusión*/
#ifndef TERMINAL_HPP
#define TERMINAL_HPP

/**!<Bibliotecas encesarias*/
#include <windows.h>
#include <stdio.h>
#include <conio.h>

/**
 *
 *@class Terminal
 *@brief Se encarga de todas las funciones que tengan que ver con la terminal.
 */
class Terminal{
	private:
		/*Nada por el momento*/
	public:

		/**
		 *@brief Método constructor de la clase.
		 */
		Terminal();

		/**
		 *@brief Método destructor de la clase.
		 */
		~Terminal();

		/**
		 *@brief Método que mueve el cursor en la temrinal.
		 *@param x Coordenada en x en la temrinal.
		 *@param y Coordenada en y en la temrinal.
		 */
		void gotoxy(int x, int y);

		/**
		 *@brief Método que oculta el cursor de la terminal.
		 */
		void ocultarCursor();

		/**
		 *@brief Método que pinta los limites del tablero de juego,
		 *si se desea se pueden colocar unicamente los parametros de largo y alto y
		 *se creara un tablero por default, si se desea personalizar usar los demas paramatros.
		 *
		 *@param largo Tamaño en x del tablero.
		 *@param alto Tamaño en y del tablero.
		 *@param dHorizontal Distancia que separa el tablero del lado izquierdo de la temrinal.
		 *@param dVertical Distancia que separa el tablero del lado superior de la terminal.
		 *@param cHorizontal Caracter de las lineas horizontales del tablero.
		 *@param cVertical Caracter de las lineas verticales del tablero.
		 *@param cEsquina1 Caracter de la esquina superior izquierda del tablero.
		 *@param cEsquina2 Caracter de la esquina superior derecha del tablero.
		 *@param cEsquina3 Caracter de la esquina inferiro izquierda del tablero.
		 *@param cEsquina4 Carcter de la esquina inferiro derecha del tablero.
		 */
		void pintarLimites(int largo, int alto, int dHorizontal = 0, int dVertical = 0,char cHorizontal = 205, char cVertical = 186, char cEsquina1 = 201, char cEsquina2 = 187, char cEsquina3 = 200, char cEsquina4 = 188);
};

#endif