
#include <iostream>
#include "paqueteria.h"

int main()
{
	int cant;
	int limites;

	double* pesos = crearRegistro(cant);
	IngresarPeso(pesos, cant);

	double total = calcularPesoTotal(pesos, cant);
	std::cout << "Peso total del paquete: " << total << std::endl;
	std::cout << "ingrese el limite: ";
	std::cin >> limites;

	int SobreLimite = sobreLimite(pesos, cant, limites);
	std::cout << "El paquete sobre el limite es; " << SobreLimite << std::endl;
	const double* ElmasPesado = buscaElmasPesado(pesos, cant);
	std::cout << "el paquete ingresado con mayor peso es: " << *ElmasPesado << std::endl;

	
	delete[]pesos;
	return 0;
}

