#include "Estadistica.h"
#include <iostream>
#include <array>
#include <iomanip>

//int Max(const std::array<int, 10>& arreglo) {
//	int numMax = arreglo[0];
//
//	for (int i = 0; i < 10; i++) {
//		if (arreglo[i] > numMax)
//			numMax = arreglo[i];
//
//	}
//	std::cout << "El numero mayor es:" << numMax << "\n";
//	return 0;
//}
//
//
//
//int Min(const std::array<int, 10>& arreglo) {
//	int numMin = arreglo[0];
//
//	for (int i = 0; i < 10; i++) {
//		if (arreglo[i] < numMin) {
//			numMin = arreglo[i];
//		}
//	}
//	std::cout << "El numero menor es:" << numMin << "\n";
//	return 0;
//}
//
//
//
//	int Sum(const std::array<int, 10>&arreglo) {
//		int sum = 0;
//		for (int i = 0; i < 10; i++) {
//			sum = sum += arreglo[i];
//		}
//		std::cout << "La suma de todos los numero es:" << sum << std::endl;
//		return 0;
//	}
//
//
//
//	double Average(const std::array<int, 10>& arreglo) {
//		double sum = 0;
//		double prom = 0;
//
//		for (int i = 0; i < 10; i++) {
//			sum = sum + arreglo[i];
//			prom = sum / 10;
//		}
//		std::cout << "El promedio es:" << prom << "\n";
//		return 0;
//	}
//	
//	void arrayInverse(const std::array<int, 20>& array) {
//		std::array<int, 20> arrayInverse;
//		int contador = 0;
//		for (int i = 19; i >= 0; i--) {
//			arrayInverse[contador] = array[i];
//			contador++;
//		}
//		for (int x = 0; x < 20; x++) {
//			std::cout << "El arreglo al inverso es:" << arrayInverse[x] << std::endl;
//		}
//		
//	}

std::array<std::array<int, ROWS>, COLS> Matrix() {
	int contador = 0;

	std::array<std::array<int, ROWS>, COLS>Mat;
	for (int rows = 0; rows < 3; rows++) {
		for (int cols = 0; cols < 3; cols++) {
			std::cout << "ingrese un numero:" <<contador++<< std::endl;
			std::cin >> Mat[rows][cols];
		}

	}
	return Mat;
}

void sumRows(const std::array<std::array<int, ROWS>, COLS> Matrix)
{
	std::array<int, 3>sumRowsMat;

	for (int x = 0; x < 3; x++) {
		int sumRows = 0;
		for (int y = 0; y < 3; y++) {
			sumRows = sumRows + Matrix[x][y];
			sumRowsMat[x] = sumRows;
			std::cout << std::setw(6) << Matrix[x][y] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "La suma de las filas es" << "\n Primera fila " << sumRowsMat[0] << "\n Segunda fila " << sumRowsMat[1] << "\n Tercera fila " << sumRowsMat[2] << "\n";


}

void sumCols(const std::array<std::array<int, ROWS>, COLS> Matrix)
{
	std::array<int, 3>sumColsMat;
	for (int x = 0; x < 3; x++) {
		int sumCols = 0;
		for (int y = 0; y < 3; y++) {
			sumCols = sumCols + Matrix[y][x];
			sumColsMat[x] = sumCols;
		}
	}
	std::cout << "\nLuma de las columnas es" << "\n Primer columna " << sumColsMat[0] << "\n Segunda Columna " << sumColsMat[1] << "\n Tercer columna " << sumColsMat[2] << "\n";
}

void sumDiag(const std::array<std::array<int, ROWS>, COLS> Matrix) {
	
	int sumDiag = 0;
	for (int x = 0; x < 3; x++) {
		sumDiag = sumDiag + Matrix[x][x];
	}
	std::cout << "\nLa suma de la Diagonal principal es "<< sumDiag;
}








