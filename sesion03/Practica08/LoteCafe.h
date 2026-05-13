#pragma once
#include<string>
#include <sstream>
using namespace std;
namespace EIF201 {


	class LoteCafe{

	protected:
		string finca;
		double pesoKg;
		int altitudMsnm;

		double puntajeBaseAltitud() const {
			if (altitudMsnm > 1400) {
				return 88.0;
			}

			else if (altitudMsnm> 1200) {
				return 84.0;
			}

			else if (altitudMsnm > 800) {
				return 80.0;
			}
			else {
				return 75.0;
			}
		}

	public:
		LoteCafe(const string& finca, double pesoKg, int altitudMsnm) :
			finca(finca), pesoKg(pesoKg), altitudMsnm(altitudMsnm) {}

		virtual ~LoteCafe(){}

		virtual double calcularPuntajeCalidad()const = 0;
		virtual double calcularPrecioPorKg() const = 0;
		virtual string getProceso()const = 0;

		double calcularValorTotal()const {
			return pesoKg * calcularPrecioPorKg();

		}

		virtual string toString()const {
			ostringstream oss;
			oss << getProceso() << " | Finca: " << finca
				<< " | " << pesoKg << "kg | " << altitudMsnm << " Msnm"
				<< " | Calidad: " << calcularPuntajeCalidad()
				<< " | Precio/kg: " << calcularPrecioPorKg()
				<< " | Total: " << calcularValorTotal() << " colones.";
				return oss.str();
		}

		string getFinca() const { return finca; }
		double getPesoKg() const {	return pesoKg;}
		int getAltitudMsnm() const { return altitudMsnm; }



	};

}