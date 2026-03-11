#include <iostream>
#include "paqueteria.h"

double* crearRegistro(int& cant)
{
	std::cout << "Ingrese la cantidad de paquetes:" << std::endl;
 	std::cin >> cant;

	while (cant <= 0) {
		std::cout << "cantidad invalida, pruebe otra vez  ";
		std::cin >> cant;
	}
	double* pesos = new double[cant];
	return pesos;

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

double calcularPesoTotal(const double* pesos, int cant)
{
	double total = 0;
	int i = 0;
	while (i < cant) {
		total = total = pesos[i];
		i++;
	}
	return total;
}

int sobreLimite(const double* pesos, int cant, double limites)
{
	int cant = 0;
	for (int i = 0; i < cant; i++) {
		if (pesos[i] > limites) {
			cant = cant + 1;
		}
	}
	return cant;
}

const double* buscaElmasPesado(const double* pesos, int cantidad)
{
	double max = pesos[0];
	int posi = 0;
	for (int i = 0; i < cantidad; i++) {
		if (pesos[i] > max) {
			max = pesos[i];
			posi = i;
		}
	}

	return &pesos[posi];
}


