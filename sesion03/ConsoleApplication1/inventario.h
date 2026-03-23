#pragma once
#ifndef INVENTARIO.H
#define INVENTARIO.H
#include "productos.h"
#include <string>

namespace EIF201 {

	class inventario
	{
	private:
		productos** producto; //arreglo dinamico
		int cantidad;
		int capacidad;
		void redimencionar();

	public:
		inventario(int capacidadInicial = 3);
		~inventario();

		void agregar(productos* nuevo);
		void mostrarTodos() const;

		productos* buscarporCodigo(std::string codigo) const;
		bool eliminar(std::string codigo);
		double calcularValorTotal() const;

		int getCantidad() const;
		int getCapacidd()const;
	};
#endif
}