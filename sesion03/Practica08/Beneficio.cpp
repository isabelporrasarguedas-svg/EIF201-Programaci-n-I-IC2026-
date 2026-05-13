#include "LoteCafe.h"
#include <string>
#include <iostream>
#include <sstream>
#include "Beneficio.h"
using namespace std;
namespace EIF201 {

	Beneficio::Beneficio() {
		capacidad = 5;
		cantidad = 0;
		lotes = new LoteCafe * [capacidad];
	}

	

	void Beneficio::redimensionar()
	{
		int nuevaCapacidad = capacidad * 2;
		LoteCafe** nuevo = new LoteCafe * [nuevaCapacidad];

		for (int i = 0; i < cantidad; i++) {
			nuevo[i] = lotes[i];
		}
		delete[] lotes;
		lotes = nuevo;
		capacidad = nuevaCapacidad;
	}

	void Beneficio::agregarLote(LoteCafe* lote) {
		if (cantidad == capacidad) {
			redimensionar();
		}

		lotes[cantidad] = lote;
		cantidad++;
		
	}



	void Beneficio::mostrarInventario() const{
		for (int i = 0; i < cantidad; i++) {
			cout << lotes[i]->toString() << endl;
		}
	}



	double Beneficio::valorTotalInventario()const {
		double total = 0;

		for (int i = 0; i < cantidad; i++) {
			total += lotes[i]->calcularValorTotal();
		}
		return total;
	}



	LoteCafe* Beneficio::loteMayorCalidad() const
	{ if(cantidad==0) return nullptr;

	LoteCafe* mejor = lotes[0];

	for (int i = 0; i < cantidad; i++) {
		if (lotes[i]->calcularPuntajeCalidad() > mejor->calcularPuntajeCalidad())
			mejor = lotes[i];
	}
	return mejor;
	}



	int Beneficio::contarPorProceso(const string& proceso) const
	{
		int cont = 0;
		for (int i = 0; i < cantidad; i++) {
			if (lotes[i]->getProceso().find(proceso) != string::npos) {
				cont++;
			}
		}
		return cont;
	}




	double Beneficio::promedioCalidadPorProceso(const string& proceso) const
	{
		double sum = 0;
		double contador = 0;
		for (int i = 0; i < cantidad; i++) {
			if (lotes[i]->getProceso().find(proceso) != string::npos) {
				sum += lotes[i]->calcularPuntajeCalidad();
				contador++;
			}
		}
			if (contador == 0) return 0;
		return sum/contador;
	}

	

	Beneficio::~Beneficio() {
		for (int i = 0; i < cantidad; i++) {
			delete lotes[i]; 
		}

		delete[] lotes; 
	}
	}

