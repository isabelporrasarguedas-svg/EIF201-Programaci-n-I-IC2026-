#include <iostream>
#include "Flota.h"

using namespace UNA;

    int main()
    {
        Flota flota(3);
        int opcion;

        do {
            std::cout << "\n====== MENU FLOTA DE VEHICULOS ======\n";
            std::cout << "1. Registrar vehiculo\n";
            std::cout << "2. Buscar vehiculo por placa\n";
            std::cout << "3. Mostrar vehiculos por marca\n";
            std::cout << "4. Registrar kilometros\n";
            std::cout << "5. Desactivar vehiculo (fuera de servicio)\n";
            std::cout << "6. Reactivar vehiculo\n";
            std::cout << "7. Eliminar vehiculo (dar de baja definitiva)\n";
            std::cout << "8. Mostrar todos\n";
            std::cout << "9. Contar activos\n";
            std::cout << "10. Salir\n";
            std::cout << "Seleccione opcion: ";
            std::cin >> opcion;

            std::string placa, marca;
            int anio;
            double km;

            switch (opcion) {

            case 1: {
                std::cout << "Placa: ";
                std::cin >> placa;

                std::cout << "Marca: ";
                std::cin >> marca;

                std::cout << "Anio: ";
                std::cin >> anio;

                std::cout << "Kilometraje: ";
                std::cin >> km;

                Vehiculo* v = new Vehiculo(placa, marca, anio, km);
                flota.agregar(v);

                std::cout << "Vehiculo registrado\n";
                break;
            }

            case 2: {
                std::cout << "Ingrese placa: ";
                std::cin >> placa;

                Vehiculo* v = flota.buscarPorPlaca(placa);

                if (v != nullptr) {
                    v->mostrar();
                }
                else {
                    std::cout << "Vehiculo no encontrado\n";
                }
                break;
            }

            case 3: {
                std::cout << "Ingrese marca: ";
                std::cin >> marca;

                flota.mostrarPorMarca(marca);
                break;
            }

            case 4: {
                std::cout << "Ingrese placa: ";
                std::cin >> placa;

                Vehiculo* v = flota.buscarPorPlaca(placa);

                if (v != nullptr) {
                    std::cout << "Ingrese km a agregar: ";
                    std::cin >> km;

                    v->registrarKilometros(km);
                }
                else {
                    std::cout << "Vehiculo no encontrado\n";
                }
                break;
            }

            case 5: {
                std::cout << "Ingrese placa: ";
                std::cin >> placa;

                Vehiculo* v = flota.buscarPorPlaca(placa);

                if (v != nullptr) {
                    v->desactivar();
                }
                else {
                    std::cout << "Vehiculo no encontrado\n";
                }
                break;
            }

            case 6: {
                std::cout << "Ingrese placa: ";
                std::cin >> placa;

                Vehiculo* v = flota.buscarPorPlaca(placa);

                if (v != nullptr) {
                    v->reactivar();
                }
                else {
                    std::cout << "Vehiculo no encontrado\n";
                }
                break;
            }

            case 7: {
                std::cout << "Ingrese placa: ";
                std::cin >> placa;

                flota.eliminar(placa);
                break;
            }

            case 8:
                flota.mostrarTodos();
                break;

            case 9:
                std::cout << "Vehiculos activos: " << flota.contarActivos() << std::endl;
                break;

            case 10:
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opcion invalida\n";
            }

        } while (opcion != 10);

        return 0;
    }

