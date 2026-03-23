#include "Flota.h"
#include <iostream>

namespace UNA {
	
	Flota::Flota(int capacidadInicial) : cantidad(0), capacidad(capacidadInicial) {
		vehiculos = new Vehiculo * [capacidadInicial];

		for (int i = 0; i < capacidad; i++) {
			vehiculos[i] = nullptr;
		}
	}

	Flota::~Flota() {
		for (int i = 0; i < cantidad; i++) {
			delete vehiculos[i];
			vehiculos[i] = nullptr;
		}
		delete[] vehiculos;
		vehiculos = nullptr;
		std::cout << "Flota destruido";
	}

	void Flota::redimensionar()
	{
		int nuevaCapacidad = capacidad * 2;

		Vehiculo** nuevoArreglo = new Vehiculo * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = vehiculos[i];
		}

		
		for (int i = cantidad; i < nuevaCapacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}

		delete[] vehiculos;

		vehiculos = nuevoArreglo;
		capacidad = nuevaCapacidad;

	}
	
	void UNA::Flota::agregar(Vehiculo* v)
	{
		if (v == nullptr) {
			std::cout << "Error el vehiculo es invalido\n";
			return;
		}

		if (cantidad == capacidad) {
			redimensionar();
		}

		vehiculos[cantidad] = v;
		cantidad++;
	}
	

	Vehiculo* UNA::Flota::buscarPorPlaca(std::string placa) const
	{
		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				return vehiculos[i];
			}
		}
	}

	void UNA::Flota::mostrarTodos() const
	{
		if (cantidad == 0) {
			std::cout << "Error no hay vehiculos\n";
			return;
		}

		std::cout << "=========== FLOTA ===========" << std::endl;

		for (int i = 0; i < cantidad; i++) {
			vehiculos[i]->mostrar(); 
		}

		std::cout << "--------------------------------" << std::endl;
	
	}

	void UNA::Flota::mostrarPorMarca(std::string marca) const
	{
		int contador = 0;

		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getMarca() == marca) {
				vehiculos[i]->mostrar();
				contador++;
			}
		}

		if (contador == 0) {
			std::cout << "No hay vehiculos de la marca ingresada: " << marca << std::endl;
		}
		else {
			std::cout << "Total de vehiculos de la marca ingresada " << marca
				<< ": " << contador << std::endl;
		}
	}

	bool UNA::Flota::eliminar(std::string placa)
	{
		int posicion = -1;

		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				posicion = i;
				break;
			}
			if (posicion == -1) {
				std::cout << "Vehiculo no encontrado\n";
				return false;
			}
		}
		if (vehiculos[posicion]->isActivo()) {
			std::cout << "Debe desactivar el vehiculo primero\n";
			return false;
		}
		std::string placaVehiculo = vehiculos[posicion]->getPlaca();

		delete vehiculos[posicion];

		for (int i = posicion; i < cantidad - 1; i++) {
			vehiculos[i] = vehiculos[i + 1];
		}

		vehiculos[cantidad - 1] = nullptr;
		cantidad--;

		std::cout << "Vehiculo " << placaVehiculo << " eliminado\n";
		return true;

	}

	int UNA::Flota::contarActivos() const
	{
		int cont = 0;

		for (int i = 0; i < cantidad; i++) {
			if (vehiculos[i]->isActivo()) {
				cont++;
			}
		}

		return cont;
	}

}