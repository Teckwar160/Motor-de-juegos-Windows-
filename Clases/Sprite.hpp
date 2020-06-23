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

		/**!<Caracter a ignorar del Sprite*/
		char ignorar;

		/**!<Caracter de fondo del sprite*/
		char fondo;

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
		 *@param nombre Nombre del archivo que contiene al sprite sin extensión.
		 *@param disparo Si es que el sprite puede disparar.
		 *@param flechas Activa el movimento por las flechas del teclado.
		 *@param ignorar Este es el caracter de fondo se borrara al momento de
		 *cargar el sprite.
		 *@param fondo Este es el caracter de fondo que sustituira a ignorar.
		 */
		Sprite(int x, int y, int pX, int pY, std::string nombre,bool disparo = false,bool flechas = true, char ignorar = '*', char fondo = ' ');

		/**
		 *@brief Contructor vacío para arreglos.
		 *@param disparo Si es que el sprite puede disparar.
		 *@param flechas Activa el movimento por las flechas del teclado.
		 *@param ignorar Este es el caracter de fondo se borrara al momento de
		 *cargar el sprite.
		 *@param fondo Este es el caracter de fondo que sustituira a ignorar.
		 */
		Sprite(bool disparo = false,bool flechas = true, char ignorar = '*', char fondo = ' ');
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
		 *@param otro Sprite que esta en el tablero.
		 */
		void moverBala(Terminal *tablero, Sprite *otro);

		/**
		 *@brief Método que verifica si un sprite choco con otro.
		 *@param otro Es el otro sprite que se estara analizando.
		 */
		bool comprobadorDeColision(Sprite *otro);

		/**
		 *@brief Métdo que define el tamaño en x del sprite.
		 *@param x Tamaño en x del sprite.
		 */
		void setX(int x);

		/**
		 *@brief Método que define el tamaño en y del sprite.
		 *@param y Tamaño en y del sprite.
		 */
		void setY(int y);

		/**
		 *@brief Método que define la posición del sprite en x.
		 *@param pX Posición en x del sprite.
		 */
		void setpX(int pX);

		/**
		 *@brief Método que define la posición del sprite en y.
		 *@param pY Posición en y del sprite.
		 */
		void setpY(int pY);

		/**
		 *@brief Método que define el nombre del sprite.
		 *@param nombre Nombre del sprite.
		 */
		void setNombre(std::string nombre);

		/**
		 *@brief Método que define si el sprite puede disparar.
		 *@param disparo Si puede disparar o no.
		 */
		void setDisparo(bool disparo);

		/**
		 *@brief Método que define si se usan las flachas o w,a,s,d para mover.
		 *@param flechas Si se puede usar flachas o no.
		 */
		void setFlechas(bool flechas);

		/**
		 *@brief Método que define el caracter a ignorar en el sprite.
		 *@param ignorar Caracter a ignorar del sprite.
		 */
		void setIgnorar(char ignorar);

		/**
		 *@brief Método que define el fondo del sprite.
		 *@param fondo Caracter de fondo del sprite.
		 */
		void setFondo(char fondo);

		/**
		 *@brief Método que se encarga de dar una dirección a los objetos que se muevan solos.
		 *@param Dirección en la que se moveran lso objetos.
		 */
		void setDireccion(char direccion);

		/**
		 *@brief Método que regresara el sentido en el cual se mueven los objetos.
		 */
		char getDireccion();

		/**
		 *@brief Método que retorna el tamño en x del sprite.
		 */
		int getX();

		/**
		 *@brief Método que retorna en tamño en y del sprite.
		 */
		int getY();

		/**
		 *@brief Método que retorna el sprite del jugador(OJO solo usar dentro de Sprite nunca fuera de el)
		 */
		Pixel **getSprite();
};

#endif 