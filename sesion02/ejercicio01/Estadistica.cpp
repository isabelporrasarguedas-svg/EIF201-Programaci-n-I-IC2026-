#include "Estadistica.h"
#include <iostream>
#include <array>

int Numbers()
{
	int contador = 0;

	std::array <int, 10> arreglo;

	for (int i = 0; i < 10; i++) {
		contador++;
		std::cout << "ingrese el numero "<<contador<<std::endl;
		std::cin >> arreglo[i];
	}
	int numMax = arreglo[0];
	int numMin = arreglo[0];

	for (int i = 0; i < 10; i++) {
		if (arreglo[i] > numMax) {
			numMax = arreglo[i];
		}
		if (arreglo[i] < numMin) {
			numMin = arreglo[i];
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = sum += arreglo[i];
	}
	double average = 0;
	average = sum / 10;

	std::cout << "La suma de todos los numero es" << sum << std::endl;
	std::cout << "El numero mayor es:" << numMax << "\n";
	std::cout << "El numero menor es:" << numMin << "\n";
	std::cout << "El promedio es:" << average << "\n";

	return 0;
}