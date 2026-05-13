#pragma once
#include <string>
#include <sstream>
#include "Contenido.h"
namespace EIF201 {
	class Podcast : public Contenido
	{
	private:
		int episodios;
		bool patrocinio;
		double promOyentes;

	public:
		Podcast(const std::string& nombre, int tiempoDuracion, int ep, bool patro, double oyentes);
		virtual ~Podcast();
		
		double calcularRegalias() const override;
		std::string getTipo() const override;
		int getNivelPopularidad()const override;

	};

}