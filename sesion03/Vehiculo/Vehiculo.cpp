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
        if (!activo) {
            std::cout << "Este vehiculo se encuentra fuera de servicio\n";
            return;
        }

        if (km < 0) {
            std::cout << "El kilometraje no puede ser menor a 0\n";
        }
        else {
            kilometraje += km;
        }
       }
    void Vehiculo::desactivar()
    {
        if (!activo) {
            std::cout << "El vehiculo ya se encuentra desactivado\n";
            return;
        }

        activo = false;
        std::cout << "El vehiculo ha sido desactivado\n";
    
    }
    void Vehiculo::reactivar()
    {
        if (activo)
        {
            std::cout << "El vehiculo se encuntra activado\n";
            return;
            
        }
        activo = true;
    }
    void Vehiculo::mostrar() const
    {
        std::cout << "====== DATOS DEL VEHICULO ======\n"
            << "Placa:        " << placa << "\n"
            << "Marca:        " << marca << "\n"
            << "Anio:         " << anio << "\n"
            << "Kilometraje:  " << kilometraje << "\n"
            << "Estado:       " << (activo ? "ACTIVO" : "FUERA DE SERVICIO") << "\n"
            << "================================" << std::endl;
}
