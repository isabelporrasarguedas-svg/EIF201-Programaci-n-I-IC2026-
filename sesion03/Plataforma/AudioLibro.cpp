#include "AudioLibro.h"
#include <string>
#include <sstream>
#include "Contenido.h"

namespace EIF201 {

	AudioLibro::AudioLibro(const std::string& nombre, int tiempoDuracion, int capitulos, double precio, int unidades) 
		:Contenido(nombre, tiempoDuracion), numCapitulos(capitulos), precioVenta(precio), unidadesVendidas(unidades) {

	}
	double AudioLibro::calcularRegalias() const
	{
		double regalias = 0;

		if (tiempoDuracion > 36000) {
			regalias = precioVenta * 0.30 * unidadesVendidas;
		}
		else {
			regalias= precioVenta * 0.25 * unidadesVendidas;
		}

		if (unidadesVendidas > 1000) {
			regalias *= 1.12;
		 }
		if (numCapitulos > 20) {
			regalias *= 1.08;
		}
		return regalias;
	}
	std::string AudioLibro::getTipo() const
	{
		if(numCapitulos<20)return  "AudioLibro - Normal";
		else {
			return "AudioLibro - Denso";
		}
	}
	int AudioLibro::getNivelPopularidad() const
	{
		if (unidadesVendidas < 100) return 1;
		else if (unidadesVendidas < 500) return 2;
		else if (unidadesVendidas < 1000) return 3;
		else if (unidadesVendidas < 3000) return 4;
		else if (unidadesVendidas < 5500) return 5;
		else if (unidadesVendidas < 10000) return 6;
		else if (unidadesVendidas < 30000) return 7;
		else if (unidadesVendidas < 55000) return 8;
		else if (unidadesVendidas < 100000) return 9;
		else return 10;
	}
	AudioLibro::~AudioLibro(){}
}