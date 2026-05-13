#pragma once
#include "Estudiante.h"

namespace EIF201 {
	struct Nodo {
		Estudiante* dato;
		Nodo* siguiente;
		Nodo* anterior;

		Nodo(Estudiante* e);
		~Nodo();
	};


		class ListaEstudiantes
		{
		private:
			Nodo* cabeza;
			int cantidad;

		public:
			ListaEstudiantes();
			~ListaEstudiantes();

			void insertarAlInicio(Estudiante* nuevo);
			void insertarAlFinal(Estudiante* nuevo);

			Estudiante* buscarPorCarnet(const std::string& carnet) const;

			bool eliminarPorCarnet(const std::string& carnet);
			void recorrer();
			double calcularPromedio()const;
			int contarAprobados(double notaMinima)  const;
			int contarRepro(double notaMinima)const;

			int getCantidad()const;
			bool estaVacia()const;

		};


	}
