#include "Estadistica.h"
#include <iostream>
#include <array>


int Max(const std::array<int, 10>& arreglo) {
	int numMax = arreglo[0];

	for (int i = 0; i < 10; i++) {
		if (arreglo[i] > numMax)
			numMax = arreglo[i];

	}
	std::cout << "El numero mayor es:" << numMax << "\n";
	return 0;
}



int Min(const std::array<int, 10>& arreglo) {
	int numMin = arreglo[0];

	for (int i = 0; i < 10; i++) {
		if (arreglo[i] < numMin) {
			numMin = arreglo[i];
		}
	}
	std::cout << "El numero menor es:" << numMin << "\n";
	return 0;
}



	int Sum(const std::array<int, 10>&arreglo) {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum = sum += arreglo[i];
		}
		std::cout << "La suma de todos los numero es:" << sum << std::endl;
		return 0;
	}



	double Average(const std::array<int, 10>& arreglo) {
		double sum = 0;
		double prom = 0;

		for (int i = 0; i < 10; i++) {
			sum = sum + arreglo[i];
			prom = sum / 10;
		}
		std::cout << "El promedio es:" << prom << "\n";
		return 0;
	}
	
	void arrayInverse(const std::array<int, 20>& array) {
		std::array<int, 20> arrayInverse;
		int contador = 0;
		for (int i = 19; i >= 0; i--) {
			arrayInverse[contador] = array[i];
			contador++;
		}
		for (int x = 0; x < 20; x++) {
			std::cout << "El arreglo al inverso es:" << arrayInverse[x] << std::endl;
		}
		
	}











