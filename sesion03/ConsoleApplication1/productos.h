#pragma once
#ifndef PRODUCTOS.H
#include <string>
#include <iostream>


namespace EIF201 {
	class productos
	{
	private:
		std::string nombre;
		double precio;
		int stock;
		std::string codigo;

	public:
		productos(std::string nombre, double precio, int stock, std::string codigo);

		//getes
		std::string getNombre() const;
		double getPrecio() const;
		int getStock() const;
		std::string getCodigo() const;

		//settes
		void setPrecio(double nuevoPrecio);
		void setStock(int nuevaCantidad);

		//mostrar
		void mostrar() const;

		bool vender(int cantidad);

	};
}
#endif
