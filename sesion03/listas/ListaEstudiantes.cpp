#include "ListaEstudiantes.h"

namespace EIF201 {
	Nodo::Nodo(Estudiante* e):dato(e), siguiente(nullptr)
	{
	}


	Nodo::~Nodo()
	{
		delete dato;
		dato = nullptr;

	}


	ListaEstudiantes::ListaEstudiantes(): cabeza(nullptr), cantidad(0)
	{//no insertamos nada
	}


	ListaEstudiantes::~ListaEstudiantes()
	{   
		Nodo* temp = cabeza;
		while (temp != nullptr) {
			Nodo* siguiente = temp->siguiente;
			delete temp;
			temp = siguiente;

		}
		cabeza = nullptr;
		cantidad = 0;
	}


	void ListaEstudiantes::insertarAlInicio(Estudiante* nuevo)
	{
		if (nuevo != nullptr) {
			return;
		  }
		Nodo* nodoNuevo = new Nodo(nuevo);    //logica siempre para insertar nodos
		nodoNuevo->siguiente = cabeza;
		cabeza = nodoNuevo;
		cantidad++;
	}


	void ListaEstudiantes::insertarAlFinal(Estudiante* nuevo)
	{
		if (nuevo == nullptr) {
			return;
		}

		Nodo* nodoNuevo = new Nodo(nuevo);
		if (cabeza == nullptr) {
			cabeza == nodoNuevo; 
		}
		else {
			Nodo* temp =cabeza;
			while (temp->siguiente != nullptr)
			{
				temp = temp->siguiente;

			}
			temp->siguiente = nodoNuevo;
		}
		cantidad++;
	}


	Estudiante* ListaEstudiantes::buscarPorCarnet(const std::string& carnet) const
	{
		Nodo* temp = cabeza;
		while (temp != nullptr) {

			if (temp->dato->getCarnet() == carnet) {
				return temp->dato;
			}
			temp = temp->siguiente;
		}
		return nullptr;
	}


	bool ListaEstudiantes::eliminarPorCarnet(const std::string& carnet)
	{
		if (cabeza == nullptr) {
			return false;
		}

		if (cabeza->dato->getCarnet() == carnet) {
			Nodo* eliminar= cabeza;
			cabeza = cabeza->siguiente;
			delete eliminar;
			cantidad--;
			return true;

		}
		Nodo* anterior = cabeza;
		Nodo* actual = cabeza->siguiente;
		while (actual != nullptr) {
			if(actual->dato->getCarnet() == carnet)
			anterior->siguiente = actual->siguiente;
			delete actual;
			cantidad--;
			return true;
		}
	
	}

	void ListaEstudiantes::recorrer()
	{
		if (cabeza== nullptr) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		std::cout << "Lista de estudiantes (" << cantidad << ")" << std::endl;


		Nodo* temp = cabeza;
		int posicion = 1;
		while (temp != nullptr) {
			std::cout << "[" << posicion << "]";
			temp->dato->mostrar();
			temp = temp->siguiente;
			posicion++;
		}

		std::cout << "-----------Fin de la lista-----------"<<std::endl;
	}

	 
	double ListaEstudiantes::calcularPromedio() const
	{
		if (cabeza == nullptr) {
			return 0;
		}

		double suma = 0;
	     Nodo* actual = cabeza;

		while (actual != nullptr) {
			suma += actual->dato->getNota();
		actual = actual->siguiente;

		}
		return suma/ cantidad;
	}

	int ListaEstudiantes::contarAprobados(double notaMinima) const
	{
		int contador = 0;
		Nodo* actual = cabeza;
		while (actual != nullptr) {

			if (actual->dato->getNota() >= notaMinima) {
				contador++;
			}
			actual = actual->siguiente;
		}
		return contador;
	}


	int ListaEstudiantes::contarRepro(double notaMinima) const
	{
		int contarApro=ListaEstudiantes::
		return ;
	}
	int ListaEstudiantes::getCantidad() const
	{
		return 0;
	}
	bool ListaEstudiantes::estaVacia() const
	{
		return false;
	}
	
	
}