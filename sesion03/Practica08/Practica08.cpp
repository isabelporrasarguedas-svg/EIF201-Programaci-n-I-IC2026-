
#include "Beneficio.h"
#include "LoteLavado.h"
#include "LoteHoney.h"
#include "LoteNatural.h"
#include <iostream>
using namespace std;
using namespace EIF201;



int main()
{
    Beneficio beneficio;

   
    beneficio.agregarLote(new LoteLavado("Finca 34", 100, 1300, 20));
    beneficio.agregarLote(new LoteLavado("Finca 33", 80, 900, 10));   

    beneficio.agregarLote(new LoteHoney("Finca 23", 120, 1400, 80));  
    beneficio.agregarLote(new LoteHoney("Finca 22", 90, 1100, 40));  

    beneficio.agregarLote(new LoteNatural("Finca 44", 150, 1500, 22, 11)); 
    beneficio.agregarLote(new LoteNatural("Finca 43", 110, 800, 30, 9));  
    beneficio.agregarLote(new LoteNatural("Finca 42", 95, 1200, 15, 13)); 

    cout << "===== INVENTARIO =====\n";
    beneficio.mostrarInventario();

    
    cout << "\nValor total inventario: "
        << beneficio.valorTotalInventario() << endl;

    LoteCafe* mejor = beneficio.loteMayorCalidad();
    if (mejor != nullptr) {
        cout << "\nMejor lote:\n" << mejor->toString() << endl;
    }

    
    cout << "\nCantidad Honey: "
        << beneficio.contarPorProceso("Honey") << endl;

    
    cout << "Promedio calidad Honey: "
        << beneficio.promedioCalidadPorProceso("Honey") << endl;

    return 0;
}

