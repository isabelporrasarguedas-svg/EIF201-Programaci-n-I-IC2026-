#include <iostream>
#include <fstream>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace std;
using namespace EIF201;

int main() {

    Bitacora bitacora("aves.txt");
    AnalisisAves analisis;
    NodoAve* lista = nullptr;

    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar ave\n";
        cout << "2. Cargar aves\n";
        cout << "3. Mostrar cronologico\n";
        cout << "4. Mostrar inverso\n";
        cout << "5. Resumen\n";
        cout << "6. Exportar a archivo\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1: {
            string anillo, especie, fecha;
            double peso;
            char sexo;

            cout << "Anillo: "; getline(cin, anillo);
            cout << "Especie: "; getline(cin, especie);
            cout << "Peso: "; cin >> peso;
            cout << "Sexo (H/M): "; cin >> sexo;
            cin.ignore();
            cout << "Fecha: "; getline(cin, fecha);

            bitacora.registrarAve(anillo, especie, peso, sexo, fecha);
            cout << "Registrado\n";
            break;
        }

        case 2:
            bitacora.cargarTodas(lista);
            cout << "Datos cargados\n";
            break;

        case 3:
            analisis.imprimirCronologico(lista);
            break;

        case 4:
            analisis.imprimirInverso(lista);
            break;

        case 5:
            cout << "Total: " << analisis.contar(lista) << endl;
            cout << "Garza Tigre: "
                << analisis.contarEspecie(lista, "Garza Tigre") << endl;
            cout << "Peso total: "
                << analisis.sumaPesos(lista) << endl;
            cout << "Existe Garza Tigre: "
                << (analisis.existeEspecie(lista, "Garza Tigre") ? "SI" : "NO") << endl;
            break;

        case 6: {
            ofstream archivo("anillamientos.txt");

            NodoAve* temp = lista;

            while (temp != nullptr) {
                archivo << temp->anillo << " - "
                    << temp->especie << " - "
                    << temp->peso << " - "
                    << temp->sexo << " - "
                    << temp->fecha << endl;

                temp = temp->siguiente;
            }

            archivo.close();
            cout << "Exportado a anillamientos.txt\n";
            break;
        }

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    bitacora.liberarLista(lista);

    return 0;
}