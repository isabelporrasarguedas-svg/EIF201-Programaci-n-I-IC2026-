#pragma once
#include "NodoLocutor.h"
namespace EIF201 {
	class RotacionCircular
	{ private:
		NodoLocutor* cola;
		int cantidad;
		NodoLocutor* getCabeza()const;

	public: RotacionCircular();
		  ~RotacionCircular();

          void insertarAlFinal(const std::string& nombre);

          void insertarAlInicio(const std::string& nombre);

          bool insertarDespuesDe(const std::string& referencia, const std::string& nuevo_nombre);

          bool existeLocutor(const std::string& nombre) const;

          int obtenerPosicion(const std::string& nombre) const;

          std::string turnoActual() const;

          bool eliminarLocutor(const std::string& nombre);

          bool eliminarTurnoActual();

          std::string siguiente();

          void simularTurnos(int n);

          void imprimirRotacion() const;

          int getCantidad() const;
          bool estaVacia() const;
    };

}

