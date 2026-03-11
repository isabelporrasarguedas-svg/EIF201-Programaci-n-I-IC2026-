#include <iostream>
#include "paqueteria.h"

double* crearRegristro(int& cant)
{
	std::cout << "Ingrese la cantidad de paquetes:" << std::endl;
 	std::cin >> cant;

	while (cant <= 0) {
		std::cout << "cantidad invalida, pruebe otra vez  ";
		std::cin >> cant;
	}
	
}

void IngresarPeso(double* pesos, int cant)
{
	int i = 0;
	for (int i = 0; i < cant; i++) {
		std::cout << "El peso de paquete es " << i + 1;
		std::cin >> pesos[i];

		while (pesos[i] <= 0) {
			std::cout << "peso invalido, intentelo de nuevo: ";
			std::cin >> pesos[i];

		}
	}
}


