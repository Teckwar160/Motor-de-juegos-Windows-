/**!<Guardas de inclusión*/
#ifndef CONTROLES_HPP
#define CONTROLES_HPP

/**!<Bibliotecas necesarias*/
#include "Pixel.hpp"


/**!<Definiciones de las flechas del teclado*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

class Controles{
	public:
		/**
		 *@brief Método que se encarga de seleccionar lso controles del jugador.
		 *@param Tecla Tecla que preciono el jugador.
		 *@param *x Apuntador a la coordenada x.
		 *@param *y Apuntador a la coordenada y.
		 *@param flechas Indica si se usan o no las flechas del teclado.
		 */
		void movimiento(char Tecla, int *x, int *y, bool flechas = true);
		void movimientoDeObjetos(int *x, int *y, char direccion);
};

#endif