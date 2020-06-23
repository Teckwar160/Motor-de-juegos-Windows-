/**!<Guardas de inclusión*/
#ifndef CONTROLES_HPP
#define CONTROLES_HPP

/**!<Definicioens de las flechas del techado*/
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


class Controles{
	public:
		void movimiento(char Tecla, int *x, int *y, bool flechas = true);
};

#endif