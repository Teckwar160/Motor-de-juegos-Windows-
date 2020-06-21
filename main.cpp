#include <iostream>
#include <stdlib.h>
//#include "Terminal\Terminal.hpp"
#include "Clases\Sprite.hpp"
int main(){

	/*Main de pruebas*/

#if 0
	Terminal prueba;

	prueba.pintarLimites(30,10,9,9,'-','|');

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
#endif

	Sprite prueba(10,5,"prueba");
	prueba.mostrar();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;	
	system("Pause");
	return 0;
}