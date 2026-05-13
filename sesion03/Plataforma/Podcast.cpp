#include "Podcast.h"
#include "Contenido.h"
#include <string>
#include <sstream>
namespace EIF201 {

	Podcast::Podcast(const std::string& nombre,int tiempoDuracion, int ep, bool patro, double oyentes)
		:Contenido(nombre, tiempoDuracion), episodios(ep), patrocinio(patro), promOyentes(oyentes)
	{

	}
	
	double Podcast::calcularRegalias() const
	{
		double regaliasBase = episodios * 1500*(promOyentes/1000);

		if (patrocinio) {
			regaliasBase *= 1.45;
		}
		 if (episodios > 50) {
			regaliasBase *= 1.18;
		}
		if (tiempoDuracion < 900) {
			regaliasBase *= 0.80;
		}
		return regaliasBase;
	}
	std::string Podcast::getTipo() const
	{
		return "Podcast";
	}
	int Podcast::getNivelPopularidad() const
	{
		if (promOyentes < 1000) return 1;
		else if (promOyentes < 5000)return 2;
		else if (promOyentes < 10000)return 3;
		else if (promOyentes < 25000)return 4;
		else if (promOyentes < 50000)return 5;
		else if (promOyentes < 100000)return 6;
		else if (promOyentes < 500000)return 7;
		else if (promOyentes < 1000000)return 8;
		else if (promOyentes < 3000000)return 9;

		else return 10;

	}
	Podcast::~Podcast()
	{
	}
}