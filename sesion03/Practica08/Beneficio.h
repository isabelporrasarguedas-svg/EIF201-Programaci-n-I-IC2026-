
#pragma once
#include<string>
#include <sstream>
#include "LoteCafe.h"
using namespace std;
namespace EIF201 {

	class Beneficio {

		LoteCafe** lotes;
		int capacidad;
		int cantidad;
		void redimensionar();

	public:
		Beneficio();
		~Beneficio();
		void agregarLote(LoteCafe* lote);
		void mostrarInventario() const;
		double valorTotalInventario() const;
		LoteCafe* loteMayorCalidad() const;
		double promedioCalidadPorProceso(const string& proceso) const;
		int contarPorProceso(const string& proceso) const;
	};
}
