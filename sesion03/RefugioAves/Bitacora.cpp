#include "Bitacora.h"
#include "NodoAve.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace EIF201 {

    Bitacora::Bitacora(const std::string& ruta)
        : ruta_(ruta), validas_(0), descartadas_(0)
    {
    }

   
    bool Bitacora::registrarAve(const std::string& anillo,
        const std::string& especie,
        double peso,
        char sexo,
        const std::string& fecha)
    {
        std::ofstream archivo(ruta_, std::ios::app);

        if (!archivo.is_open()) return false;

        archivo << anillo << ";"
            << especie << ";"
            << peso << ";"
            << sexo << ";"
            << fecha << "\n";

        archivo.close();

        std::ofstream log("anillamientos.txt", std::ios::app);

        if (log.is_open()) {
            log << "\n===== MENU =====\n";
            log << "Opcion: Registrar ave\n";
            log << "Datos: "
                << anillo << " - "
                << especie << " - "
                << peso << " - "
                << sexo << " - "
                << fecha << "\n";
            log.close();
        }
        std::cout << "ENTRE A REGISTRAR\n";
        return true;
    }

   
    int Bitacora::cargarTodas(NodoAve*& cabeza)
    {
        std::ifstream archivo(ruta_);
        cabeza = nullptr;

        if (!archivo.is_open()) return 0;

        std::string linea;
        int cantidad = 0;

        while (std::getline(archivo, linea)) {

            std::stringstream ss(linea);

            std::string anillo, especie, fecha;
            double peso;
            char sexo;

            std::getline(ss, anillo, ';');
            std::getline(ss, especie, ';');

            ss >> peso;
            ss.ignore();

            ss >> sexo;
            ss.ignore();

            std::getline(ss, fecha);

            NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

            
            nuevo->siguiente = cabeza;
            cabeza = nuevo;

            cantidad++;
        }

        archivo.close();
        return cantidad;
    }

    
    int Bitacora::cargarValidas(NodoAve*& cabeza)
    {
        std::ifstream archivo(ruta_);
        cabeza = nullptr;

        validas_ = 0;
        descartadas_ = 0;

        if (!archivo.is_open()) return 0;

        std::string linea;

        while (std::getline(archivo, linea)) {

            if (linea.empty()) {
                descartadas_++;
                continue;
            }

            std::stringstream ss(linea);

            std::string anillo, especie, fecha;
            double peso;
            char sexo;

            if (!std::getline(ss, anillo, ';') ||
                !std::getline(ss, especie, ';') ||
                !(ss >> peso)) {

                descartadas_++;
                continue;
            }

            ss.ignore();

            if (!(ss >> sexo)) {
                descartadas_++;
                continue;
            }

            ss.ignore();

            if (!std::getline(ss, fecha)) {
                descartadas_++;
                continue;
            }

            
            if (peso <= 0 || (sexo != 'M' && sexo != 'H' && sexo != 'X')) {
                descartadas_++;
                continue;
            }

            NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

            
            nuevo->siguiente = cabeza;
            cabeza = nuevo;

            validas_++;
        }

        archivo.close();
        return validas_;
    }

   
    int Bitacora::getValidas() const {
        return validas_;
    }

    int Bitacora::getDescartadas() const {
        return descartadas_;
    }

    
    void Bitacora::liberarLista(NodoAve*& cabeza)
    {
        while (cabeza != nullptr) {
            NodoAve* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

}