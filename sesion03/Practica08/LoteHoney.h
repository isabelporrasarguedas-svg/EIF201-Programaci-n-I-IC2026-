#pragma once
#include <string>
#include <sstream>
#include "LoteCafe.h"
using namespace std;
namespace EIF201 {


	class LoteHoney: public LoteCafe {
	private:
		int porcentajeMucilago;

	public:
		LoteHoney(const string& finca, double pesoKg, int altitudMsnm, int porcentaje);
	
		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		string getProceso() const override;
	};
}

