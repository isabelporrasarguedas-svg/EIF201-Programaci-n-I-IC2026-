#include "LoteNatural.h"
namespace EIF201 {

    LoteNatural::LoteNatural(const string& finca, double pesoKg, int altitudMsnm, int diasSecado, double humedad) :
        LoteCafe(finca, pesoKg, altitudMsnm), diasSecado(diasSecado), humedad(humedad) {

    }


    double LoteNatural::calcularPuntajeCalidad() const
    {
        double puntaje = puntajeBaseAltitud();
       
       if (diasSecado >= 18 && diasSecado <= 25) {
            puntaje += 5;
        }

      else if (diasSecado > 25) {
           int exceso = diasSecado - 25;
           puntaje -= exceso * 0.8;
       }
        
      else {
           puntaje -= 6;
       }

       if (humedad >= 10 && humedad <= 12) {
           puntaje += 3;
       }
       else if (humedad < 10) {
           puntaje -= (10 - humedad);
       }
       else {
           puntaje -= (humedad - 12);
       }


        return puntaje;
    }

    double LoteNatural::calcularPrecioPorKg() const
    {
        double precioBase = 3600.0;
        double puntaje = calcularPuntajeCalidad();
        double precio = precioBase *(puntaje/100.0);

        if (puntaje > 90) {
            precio *= 1.20;
        }

        return precio;
    }

    string LoteNatural::getProceso() const
    {
        if (diasSecado >= 18 && diasSecado <= 25)
            return "SecadoObtimo";
        else if (diasSecado < 18)
            return "SubSecado";
        else 
            return"SobreSecado";
        
    }
}