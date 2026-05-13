#include "Cancion.h"
#include "Contenido.h"
#include <string>
#include <sstream>
namespace EIF201 {

    Cancion::Cancion(const std::string& nombre, int tiempoDuracion, std::string genero, double reproducciones) 
        :Contenido(nombre, tiempoDuracion), numeroRepro(reproducciones)
    {
    }

    double Cancion::calcularRegalias() const
    {
        double multiplicador= 1.0;
        double regalias = numeroRepro*3.5;

        if (genero == "Jazz" || genero == "Clasica") {
            multiplicador = 1.4;
        }
        else if (genero == "Rock" || genero == "Indie") {
            multiplicador = 1.0;
        }
        else if (genero == "Pop" || genero == "Electronica") {
            multiplicador = 0.9;

        }
        else if (genero == "Reggaeton" || genero == "Urbano") {
            multiplicador = 0.75;
        }
        else {
            multiplicador = 1.0;
        }
        regalias *= multiplicador;

        if (numeroRepro > 1000000) {
            regalias *= 1.25;
        }
        else if (tiempoDuracion > 240) {
            regalias *= 1.10;
        }
        
      return regalias;
    }

    std::string Cancion::getTipo() const
    {

        return "cancion";
    }

    int Cancion::getNivelPopularidad() const
    {
        if (numeroRepro < 1000) return 1;
        else if (numeroRepro >= 1000 && numeroRepro <= 5000)return 2;
        else if (numeroRepro > 5000 && numeroRepro <= 10000)return 3;
        else if (numeroRepro > 10000 && numeroRepro <= 50000)return 4;
        else if (numeroRepro > 50000 && numeroRepro <= 100000)return 5;
        else if (numeroRepro > 100000 && numeroRepro <= 500000)return 6;
        else if (numeroRepro > 500000 && numeroRepro <= 1000000)return 7;
        else if (numeroRepro > 1000000 && numeroRepro <= 5000000)return 8;
        else if (numeroRepro >= 5000000 && numeroRepro <= 10000000)return 9;
        else return 10;
    }

    Cancion::~Cancion()
    {
    }
}