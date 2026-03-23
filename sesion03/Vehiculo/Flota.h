#ifndef FLOTA_H
#define FLOTA_H
#include<iostream>
#include "Vehiculo.h"

namespace UNA {

        class Flota {
        private:
            Vehiculo** vehiculos;
            int cantidad;
            int capacidad;

            void redimensionar();

        public:
            Flota();
            ~Flota();

            void agregar(Vehiculo* v);
            Vehiculo* buscarPorPlaca(std::string placa) const;
            void mostrarTodos() const;
            void mostrarPorMarca(std::string marca) const;
            bool eliminar(std::string placa);
            int contarActivos() const;
        };

    }

#endif


 