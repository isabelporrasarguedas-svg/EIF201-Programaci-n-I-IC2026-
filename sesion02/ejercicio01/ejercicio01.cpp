#include "Estadistica.h" 
#include <iostream>
#include <array>

int main()
{
	std::array<std::array<int, 3>, 3> mat = Matrix();
	sumRows(mat);
	sumCols(mat);
	sumDiag(mat);








	/*int contador = 0;
	std::array <int, 10> arreglo;

	for (int i = 0; i < 10; i++) {
		contador++;
			std::cout << "Ingrese un numero"<<contador<< std:: endl;
			std::cin >> arreglo[i];
	}

	std::array<int, 20> array;
	for (int i = 0; i < 20; i++) {
		std::cout << "ingrese un numero" << std::endl;
		std::cin >> array[i];

	}*/



	/*Max(arreglo);
	Min(arreglo);
	Sum(arreglo);
	Average(arreglo);
	arrayInverse(array);*/

}

