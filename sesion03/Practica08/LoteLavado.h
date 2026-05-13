#pragma once
#include "LoteCafe.h"
#include <string>
#include <sstream>
using namespace std;

namespace EIF201 {


	class LoteLavado: public LoteCafe {
	private:
		int horasFermentacion;

	public:
		LoteLavado(const string& finca, double pesoKg, int altitudMsnm, int horas);
	
		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		string getProceso() const override;

	};
}
