#include "Vehiculo.h"
#include <iostream>

namespace UNA {

    Vehiculo::Vehiculo(std::string placa, std::string marca, int anio, double km)
        : placa(placa), marca(marca), anio(anio), kilometraje(km), activo(true) {
    }

    std::string Vehiculo::getPlaca() const { return placa; }
    std::string Vehiculo::getMarca() const { return marca; }
    int Vehiculo::getAnio() const { return anio; }
    double Vehiculo::getKilometraje() const { return kilometraje; }
    bool Vehiculo::isActivo() const { return activo; }


    void Vehiculo::registrarKilometros(double km)
    {

    }
    void Vehiculo::desactivar()
    {
    }
    void Vehiculo::reactivar()
    {
    }
    void Vehiculo::mostrar() const
    {
    }
}
