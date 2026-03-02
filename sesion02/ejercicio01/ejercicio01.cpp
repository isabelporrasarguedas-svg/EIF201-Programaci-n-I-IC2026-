#include "Estadistica.h" 
#include <iostream>
#include <string>
#include <array>
#include <cctype>

int main()
{
	std::string name;
	std::string firstname = "";

	std::cout << "ingrese su nombre" << "\n";
	std::getline(std::cin, name);

	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			break;	
		}
		firstname = firstname + name[i];
	}



	std::cout << "Primer nombre:" << firstname << std::endl;
	std::cout << "Su nombre tiene" << name.length() << "letras de longitud" << std:: endl;


	for (int i = 0; i < name.length(); i++) {
		name[i] = toupper(name[i]);
	}
	std::cout << "Su nombre en mayusculas:" << name << std::endl;

	std::cin.get();
	return 0;





	/*sumRows(mat);
	sumCols(mat);
	sumDiag(mat);*/
	/*std::string nombreCompleto;
	std::array<std::array<int, ROWS>, COLS> mat = Matrix();

	std::cout << "ingrese su nombre" << "\n";
	std::getline(std::cin, nombreCompleto);

	std::*/




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

