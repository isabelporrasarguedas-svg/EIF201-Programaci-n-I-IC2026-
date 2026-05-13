#include "Estudiante.h"
#include <iostream>
#include <iomanip>

namespace EIF201 {
	Estudiante::Estudiante(const std::string& nombre, const std::string& carnet, double nota)
	:carnet(carnet), nombre(nombre), nota(nota)
	{

	}


	Estudiante::~Estudiante()
	{
	}

	std::string Estudiante::getCarnet() const
	{
		return carnet;
	}
	


	std::string Estudiante::getNombre() const
	{

		return nombre;
	}

	double Estudiante::getNota() const
	{
		return nota;
	}


	void Estudiante::setNota(double nota)
	{
		this->nota = nota;

	
	}

	void Estudiante::mostrar()
	{
		std::cout << "Carnet: " << carnet
			<< "Nombre: " << nombre
			<< "Nota: " << std::fixed << std::setprecision
			(1) << nota << std::endl;
	}
}
