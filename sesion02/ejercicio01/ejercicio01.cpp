#include "Estadistica.h" 
#include <iostream>
#include <array>

int main()
{
	int contador = 0;
	std::array <int, 10> arreglo;

	for (int i = 0; i < 10; i++) {
		contador++;
			std::cout << "Ingrese un numero"<<contador<< std:: endl;
			std::cin >> arreglo[i];
	}
	Max(arreglo);
	Min(arreglo);
	Sum(arreglo);
	Average(arreglo);

}

