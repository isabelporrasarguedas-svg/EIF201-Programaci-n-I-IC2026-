#include "inventario.h"
#include <iomanip>
namespace EIF201 {

	//constructor

	inventario::inventario(int cantidadInicial) : cantidad(0), capacidad(cantidadInicial) {
		producto = new productos * [cantidadInicial];
		for (int i = 0; i < capacidad; i++) {
			producto[i] = nullptr;

		}
	}

	inventario::~inventario() {
		for (int i = 0; i < cantidad; i++) {
			delete producto[i];
			producto[i] = nullptr;
		}

		delete[] producto;
		producto = nullptr;
		std::cout << "inventario destruido";
	}

	void inventario::redimencionar() {
		int nuevaCapacidad = capacidad * 2;

		productos** nuevoArreglo = new productos * [nuevaCapacidad];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = producto[i];
		}

		//inicializar las posiciones nuevas
		for (int i = cantidad; i < nuevaCapacidad; i++) {
			nuevoArreglo[i] = nullptr;
		}

		delete[] producto;

		producto = nuevoArreglo;
		capacidad = nuevaCapacidad;

	}

	void inventario::agregar(productos* nuevo) {
		if (nuevo == nullptr) {
			std::cout << "error";
			//return;
		}

		if (cantidad == capacidad) {
			redimencionar();
		}

		producto[cantidad] = nuevo;
		cantidad++;
	}

	void inventario::mostrarTodos() const {

		if (cantidad == 0) {

			std::cout << "erorr, no data" << std::endl;
			return;

		}
		std::cout << "===========INVENTARIO===========" << std::endl;
		for (int i = 0; i < cantidad; i++) {
			producto[i]->mostrar();                              //flecha:acceso directo
		}
		std::cout << "--------------------------------" << std::endl;
	
	
	}

	//buscarPorCodigo

	productos* inventario::buscarporCodigo(std::string codigo)const {
		for (int i = 0; i < cantidad; i++) {
			if (producto[i]->getCodigo() == codigo) {
				return producto[i];
			}
		}

		return nullptr;

	}

	bool inventario::eliminar(std::string codigo) {

		int posicion = -1;
		for (int i = 0; i < cantidad; i++) {
			if (producto[i]->getCodigo() == codigo) {
				posicion = i;
				break;
			}
		}    

		if (posicion == -1) {
			std::cout << "Producto no encontrado" << std::endl;
			return false;
		}
		
		std::string nombreproductos = producto[posicion]->getNombre();


		delete[]producto[posicion];

		for (int i = posicion; i < cantidad; i++) {
			producto[i] = producto[i + 1];
		 }


		producto[cantidad - 1] = nullptr;
			cantidad--;

			std::cout << "Producto" << nombreproductos << " elimidao del inventario";
			return true;


	}
	 //total


	//
	int inventario::getCantidad() const {
		return cantidad;
	}


	int inventario::getCapacidd() const {
		return capacidad;

	}




}