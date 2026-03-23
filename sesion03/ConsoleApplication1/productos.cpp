#include "productos.h"
#include <iomanip>

namespace EIF201 {
	productos::productos(std::string nombre, double precio, int stock, std::string codigo) : nombre(nombre), precio(precio), stock(stock), codigo(codigo) {}

	//getes
	std::string productos::getNombre() const {
		return nombre;
	}

	double productos::getPrecio() const {
		return precio;
	}

	int productos::getStock() const {
		return stock;
	}

	std::string productos::getCodigo() const{
		return codigo;
	}

	//setters

	void productos::setPrecio(double nuevoPrecio) {
		if (nuevoPrecio >= 0) {
			std::cout << "error, precio no puede ser negativo";
		}
		precio = nuevoPrecio;
	}

	void productos::setStock(int nuevaCantidad) {
		if (nuevaCantidad < 0) {
			std::cout << "eror, no puede ser negativo" << std::endl;
		}
		stock = nuevaCantidad;
	}

	void productos::mostrar() const {
		std::cout << "[" << codigo << "]" << nombre
			<< "|Precio:    " << std::fixed << std::setprecision(2) << precio
			<< "|Stock:     " << stock <<"unidades" << std::endl; 
	}

	//vender ~~
}