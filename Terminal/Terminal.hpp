/**!<Guardas de inclusión*/
#ifndef TERMINAL_HPP
#define TERMINAL_HPP

/**!<Bibliotecas encesarias*/
#include <windows.h>
#include <stdio.h>
#include <conio.h>

class Terminal{
	private:
		/*Nada por el momento*/
	public:
		Terminal();
		~Terminal();
		void gotoxy(int x, int y);
		void ocultarCursor();
		void pintarLimites(int largo, int alto, int dHorizontal = 0, int dVertical = 0,char cHorizontal = 205, char cVertical = 186, char cEsquina1 = 201, char cEsquina2 = 187, char cEsquina3 = 200, char cEsquina4 = 188);
};

#endif