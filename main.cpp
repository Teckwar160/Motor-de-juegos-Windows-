#include <iostream>
#include <stdlib.h>
#include "Terminal\Terminal.hpp"
int main(){

	/*Main de pruebas*/
	Terminal prueba;

	prueba.pintarLimites(30,10,9,9,'-','|');

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	system("Pause");
	return 0;
}