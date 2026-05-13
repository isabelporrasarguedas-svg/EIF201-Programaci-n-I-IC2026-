#pragma once
#include <string>
#include <sstream>
#include "Contenido.h"
namespace EIF201 {
	class Cancion : public Contenido
	{
	private:
		std::string genero;
		double numeroRepro;

	public:
		Cancion(const std::string& nombre, int tiempoDuracion, std::string genero, double numeroRepro);
		virtual ~Cancion();
		double calcularRegalias()const override; 
		 std::string getTipo()const override;
		 int getNivelPopularidad() const override;
	};
}
