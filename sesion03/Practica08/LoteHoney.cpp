#include "LoteHoney.h"
namespace EIF201 {

	LoteHoney::LoteHoney(const string& finca, double pesoKg, int altitudMsnm, int porcentaje): 
		LoteCafe(finca, pesoKg, altitudMsnm), porcentajeMucilago(porcentaje) {

	}



	double LoteHoney::calcularPuntajeCalidad() const  {
		double puntaje = puntajeBaseAltitud();
		puntaje += porcentajeMucilago * 0.08;

		if (altitudMsnm > 1200 && porcentajeMucilago > 60) {
			puntaje += 2.5;
		}
		return puntaje;
	}

	double LoteHoney::calcularPrecioPorKg() const {
		double precioBase = 3200.0;
		double puntaje = calcularPuntajeCalidad();
		double precio = precioBase * (puntaje / 100.0);

		if (porcentajeMucilago >= 75) {
			precio *= 1.15;
		}
		return precio;
	 }



	string LoteHoney::getProceso()const {
		if (porcentajeMucilago < 25)
			return "Honey-White";
		else if (porcentajeMucilago < 50)
			return "Honey-Yellow";
		else if (porcentajeMucilago < 75)
			return"Honey-Red";
		else
		return "Honey-Black";
	}
}
