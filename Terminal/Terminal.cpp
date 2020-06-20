/**!<Bibliotecas necesarias*/
#include "Terminal.hpp"

Terminal::Terminal(){
	/*Nada por el momento*/
}

Terminal::~Terminal(){
	/*Nada por el momento*/
}

void Terminal::gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hcon,dwPos);
}

void Terminal::ocultarCursor(){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;

	cursor.dwSize = 2;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(hcon,&cursor);		
}

void Terminal::pintarLimites(int largo, int alto, int dHorizontal, int dVertical, char cHorizontal, char cVertical, char cEsquina1, char cEsquina2, char cEsquina3, char cEsquina4){

	/*Puede el usuario determinar el caracter de borde*/

	/*Pinta las lineas horizontales*/
	for(int i = 0; i<largo; i++){
		this -> gotoxy(i + dHorizontal,0 + dVertical); printf("%c",cHorizontal);
		this -> gotoxy(i + dHorizontal,alto + dVertical); printf("%c",cHorizontal);
	}

	/*Pinta las lineas verticales*/
	for(int i = 0; i<alto; i++){
		this -> gotoxy(0 + dHorizontal,i + dVertical); printf("%c",cVertical);
		this -> gotoxy(largo + dHorizontal,i + dVertical); printf("%c",cVertical);
	}

	/*Pinta las esquinas*/
	this -> gotoxy(0 + dHorizontal,0 + dVertical); printf("%c",cEsquina1);
	this -> gotoxy(largo + dHorizontal,0 + dVertical); printf("%c",cEsquina2);
	this -> gotoxy(0 + dHorizontal,alto + dVertical); printf("%c",cEsquina3);
	this -> gotoxy(largo + dHorizontal,alto + dVertical); printf("%c",cEsquina4);	
}


