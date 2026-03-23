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
	}

	Vehiculo* UNA::Flota::buscarPorPlaca(std::string placa) const
	{
		return nullptr;
	}

	void UNA::Flota::mostrarTodos() const
	{
	}

	void UNA::Flota::mostrarPorMarca(std::string marca) const
	{
	}

	bool UNA::Flota::eliminar(std::string placa)
	{
		return false;
	}

	int UNA::Flota::contarActivos() const
	{
		return 0;
	}

}