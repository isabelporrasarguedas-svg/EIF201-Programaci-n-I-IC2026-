#include "Plataforma.h"
#include <string>
#include <iostream>
#include <sstream>
namespace EIF201 {
    Plataforma::Plataforma(){
        capacidad = 8;
        cantidad = 0;
       contenidos = new Contenido * [capacidad];
    }
    void Plataforma::redimensionar()
    {
        int nuevaCapacidad = capacidad * 2;
        Contenido** nuevo= new Contenido * [nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = contenidos[i];
        }
        delete[] contenidos;
        contenidos = nuevo;
        capacidad = nuevaCapacidad;
    }

    void Plataforma::agregarContenido(Contenido* contenido)
    {
        if (cantidad == capacidad) {
            redimensionar();
        }

        contenidos[cantidad] = contenido;
        cantidad++;
    }

    void Plataforma::mostrarCatalogo() const
    {
        for (int i = 0; i < cantidad; i++) {
            std::cout << contenidos[i]->toString() << std::endl;
        }
    }

    double Plataforma::regaliasTotales() const
    {
        double total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += contenidos[i]->calcularRegalias();
        }

        return total;
    }

   Contenido* Plataforma::contenidoRentable() const
    {
       if (cantidad == 0) return nullptr;
        Contenido* mejor = contenidos[0];
        for (int i = 1; i < cantidad; i++) {
            if (contenidos[i]->calcularRegalias() > mejor->calcularRegalias()) {
                mejor = contenidos[i];
            }
        }
        return mejor;
    }
    
    Contenido* Plataforma::contenidoPopular() const
    {
        if (cantidad == 0) return nullptr;

        Contenido* mejor = contenidos[0];

        for (int i = 1; i < cantidad; i++) {
            if (contenidos[i]->getNivelPopularidad() > mejor->getNivelPopularidad()) {
                mejor = contenidos[i];
            }
        }
        return mejor;
    }

    int Plataforma::contarPorTipo(const std::string& tipo) const
    {
        int cont = 0;
        for (int i = 0; i < cantidad; i++) {
            if (contenidos[i]->getTipo().find(tipo) != std::string::npos) {
                cont++;
            }
        }
        return cont;
    }

    double Plataforma::promRegaliasPorTipo(const std::string& tipo) const
    {
        double suma = 0;
        int contador = 0;

        for (int i = 0; i < cantidad; i++) {
            if (contenidos[i]->getTipo().find(tipo) != std::string::npos) {
                suma += contenidos[i]->calcularRegalias();
                contador++;
            }
        }

        if (contador == 0) return 0;

        return suma / contador;
    }
    Plataforma::~Plataforma(){
        for (int i = 0; i < cantidad; i++) {
            delete contenidos[i];
        }

        delete[] contenidos;
    }
}