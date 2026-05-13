#pragma once
#include "LoteCafe.h"
#include <string>
#include <sstream>
using namespace std;
namespace EIF201 {


	class LoteNatural: public LoteCafe
	{
	private:
		int diasSecado;
		double humedad;

	public:
		LoteNatural(const string& finca, double pesoKg, int altitudMsnm, int diasSecado, double humedad);

		double calcularPuntajeCalidad() const override;
		double calcularPrecioPorKg() const override;
		string getProceso() const override;
	};
}
