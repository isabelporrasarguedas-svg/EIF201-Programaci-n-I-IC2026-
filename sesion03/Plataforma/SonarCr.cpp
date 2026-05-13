#include <iostream>
#include "Plataforma.h"
#include "Cancion.h"
#include "Podcast.h"
#include "AudioLibro.h"

using namespace std;
using namespace EIF201;


int main() {

    Plataforma plataforma;

    // 🔹 Canciones
    plataforma.agregarContenido(new Cancion("Track 1", 300, "Rock", 150000));
    plataforma.agregarContenido(new Cancion("Track 2", 250, "Jazz", 1200000)); // viral

    // 🔹 Podcasts
    plataforma.agregarContenido(new Podcast("Podcast 1", 1000, 60, true, 20000));
    plataforma.agregarContenido(new Podcast("Podcast 2", 800, 30, false, 5000));

    // 🔹 Audiolibros
    plataforma.agregarContenido(new AudioLibro("Libro 1", 40000, 25, 5000, 1500)); // premium + bonus
    plataforma.agregarContenido(new AudioLibro("Libro 2", 20000, 10, 3000, 800));

    // 🔹 Mostrar catálogo
    cout << "===== CATALOGO =====\n";
    plataforma.mostrarCatalogo();

    // 🔹 Regalías totales
    cout << "\nRegalias totales: "
        << plataforma.regaliasTotales() << endl;

    // 🔹 Más rentable
    Contenido* rentable = plataforma.contenidoRentable();
    if (rentable != nullptr) {
        cout << "\nContenido mas rentable:\n";
        cout << rentable->toString() << endl;
    }

    // 🔹 Más popular
    Contenido* popular = plataforma.contenidoPopular();
    if (popular != nullptr) {
        cout << "\nContenido mas popular:\n";
        cout << popular->toString() << endl;
    }

    // 🔹 Contar por tipo
    cout << "\nCantidad Cancion: "
        << plataforma.contarPorTipo("Cancion") << endl;

    cout << "Cantidad Podcast: "
        << plataforma.contarPorTipo("Podcast") << endl;

    cout << "Cantidad AudioLibro: "
        << plataforma.contarPorTipo("AudioLibro") << endl;

    // 🔹 Promedios
    cout << "\nPromedio regalías Cancion: "
        << plataforma.promRegaliasPorTipo("Cancion") << endl;

    cout << "Promedio regalías Podcast: "
        << plataforma.promRegaliasPorTipo("Podcast") << endl;

    cout << "Promedio regalías AudioLibro: "
        << plataforma.promRegaliasPorTipo("AudioLibro") << endl;

    return 0;
}