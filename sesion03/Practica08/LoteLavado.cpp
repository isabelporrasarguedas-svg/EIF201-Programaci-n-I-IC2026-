#include "LoteLavado.h"
namespace EIF201 {

	LoteLavado::LoteLavado(const string& finca, double pesoKg, int altitudMsnm, int horas)
		: LoteCafe(finca, pesoKg, altitudMsnm), horasFermentacion(horas) {

	}

	double LoteLavado::calcularPuntajeCalidad() const {
		double puntaje = puntajeBaseAltitud();

		if (horasFermentacion >= 18 && horasFermentacion <= 36)
		{
			puntaje += 3;
		}

		else if (horasFermentacion < 18) { puntaje -= 4; }
	
		else {
			int exceso = horasFermentacion - 36;
			int bloques = exceso / 12;
			puntaje -= (bloques * 2);
		}
		return puntaje;
	}

	double LoteLavado::calcularPrecioPorKg() const {
		double puntaje = calcularPuntajeCalidad();
		double precioBase = 2900.0;
		return precioBase * (puntaje / 100.0);
	}

	string LoteLavado::getProceso() const {
		return "Lavado";
	}

}