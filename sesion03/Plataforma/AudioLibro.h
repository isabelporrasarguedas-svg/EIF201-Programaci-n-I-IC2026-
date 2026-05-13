#pragma once
#include <string>
#include <sstream>
#include "Contenido.h"

namespace EIF201 {

	class AudioLibro : public Contenido
	{
	private:
		int numCapitulos;
		double precioVenta;
		int unidadesVendidas;

	public:

		AudioLibro(const std::string& nombre, int tiempoDuracion, int capitulos, double precio, int unidades);
		virtual ~AudioLibro();

		double calcularRegalias() const override;
		std::string getTipo() const override;
		int getNivelPopularidad()const override;

	};
}
