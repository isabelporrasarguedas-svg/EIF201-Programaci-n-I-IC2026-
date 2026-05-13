#ifndef SONARCR_H
#define SONARCR_H
#include <string>
#include <sstream>
namespace EIF201 {
	class Contenido
	{
	protected:
		std::string nombre;
		int tiempoDuracion;

	public:
		Contenido(const std::string& nombre,int tiempoDuracion):nombre(nombre), tiempoDuracion(tiempoDuracion){}
	    virtual ~Contenido(){}
		virtual double calcularRegalias()const = 0;
		virtual std::string getTipo()const= 0 ;
		virtual int getNivelPopularidad() const= 0;

		virtual std::string toString()const {
			std::ostringstream oss;
			oss << getTipo() << " | Nombre: " << nombre
				<< " | Tiempo de Duracion: " << tiempoDuracion << std::endl;
			return oss.str();
		}

		std::string getNombre() const { return nombre; }
		int getTiempoDuracion()const { return tiempoDuracion; }
			
	};
}
#endif
