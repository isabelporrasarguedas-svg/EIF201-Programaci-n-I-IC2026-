#pragma once
#include <string>
#include <sstream>
#include "Contenido.h"
namespace EIF201 {
	class Plataforma 
	{ private:
		Contenido** contenidos;
		int cantidad;
		int capacidad;
		void redimensionar();

	public:
		Plataforma();
		virtual ~Plataforma();
		void agregarContenido(Contenido* contenido);

		void mostrarCatalogo()const;
		double regaliasTotales()const;
		Contenido* contenidoRentable()const; 
		Contenido* contenidoPopular()const;
		int contarPorTipo(const std::string& tipo) const;
		double promRegaliasPorTipo(const std::string& tipo) const;
			
		
	};
}
