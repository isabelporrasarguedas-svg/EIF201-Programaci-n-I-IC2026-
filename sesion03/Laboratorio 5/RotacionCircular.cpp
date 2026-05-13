#include "RotacionCircular.h"
namespace EIF201 {
	
	RotacionCircular::RotacionCircular()
		:cola(nullptr), cantidad(0){}

	NodoLocutor* RotacionCircular::getCabeza() const
	{
		return (cola != nullptr) ? cola->siguiente : nullptr;;

	}
    RotacionCircular::~RotacionCircular() {
        if (cola == nullptr) {
            return;
        }

        NodoLocutor* cabeza = cola->siguiente;
        cola->siguiente = nullptr;
        NodoLocutor* actual = cabeza;
        while (actual != nullptr) {
            NodoLocutor* temp = actual->siguiente;
            delete actual;
            actual = temp;
        }

        cola = nullptr;
        std::cout << "[RotacionCircular destruida]" << std::endl;
    }

    void RotacionCircular::insertarAlFinal(const std::string& nombre) {
        NodoLocutor* nuevo = new NodoLocutor(nombre);
        if (cola == nullptr) {
            nuevo->siguiente = nuevo;
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        cantidad++;
    }

    void RotacionCircular::insertarAlInicio(const std::string& nombre) {
        NodoLocutor* nuevo = new NodoLocutor(nombre);
        if (cola == nullptr) {
            nuevo->siguiente = nuevo;
            cola = nuevo;
        }
        else {
            nuevo->siguiente = cola->siguiente;
            cola->siguiente = nuevo;
        }
        cantidad++;
    }

    bool RotacionCircular::insertarDespuesDe(const std::string& referencia,
        const std::string& nuevo_nombre) {
        if (cola == nullptr) { return false; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        do {
            if (actual->nombre == referencia) {
                NodoLocutor* nuevo = new NodoLocutor(nuevo_nombre);
                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
                if (actual == cola) cola = nuevo;
                cantidad++;
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    int RotacionCircular::obtenerPosicion(const std::string& nombre) const {
        if (cola == nullptr) { return -1; }
        NodoLocutor* cabeza = getCabeza();
        NodoLocutor* actual = cabeza;
        int pos = 0;
        do {
            if (actual->nombre == nombre) { return pos; }
            actual = actual->siguiente;
            pos++;
        } while (actual != cabeza);
        return -1;
    }

   std::string RotacionCircular::turnoActual() const {
        if (cola == nullptr) { return ""; }
        return getCabeza()->nombre;
    }
   bool RotacionCircular::eliminarLocutor(const std::string& nombre) {
       if (cola == nullptr) { return false; }
       NodoLocutor* cabeza = getCabeza();
       NodoLocutor* actual = cabeza;
       NodoLocutor* previo = cola;  // el recorrido circular comienza con previo = cola
       do {
           if (actual->nombre == nombre) {
               if (actual == cola && actual == cabeza) {
                   // único nodo en la lista
                   cola = nullptr;
               }
               else {
                   previo->siguiente = actual->siguiente;        // saltar al actual
                   if (actual == cola) cola = previo;            // si era la cola, actualizar
               }
               delete actual;
               actual = nullptr;
               cantidad--;
               return true;
           }
           previo = actual;
           actual = actual->siguiente;
       } while (actual != cabeza);
       return false;
   }
   bool RotacionCircular::eliminarTurnoActual() {
       if (cola == nullptr) { return false; }
       return eliminarLocutor(getCabeza()->nombre);
   }

   std::string RotacionCircular::siguiente() {
       if (cola == nullptr) { return ""; }
       cola = cola->siguiente;
       return getCabeza()->nombre;
   }

   void RotacionCircular::simularTurnos(int n) {
       if (cola == nullptr) { std::cout << "Sin locutores en rotacion." << std::endl; return; }
       for (int i = 1; i <= n; i++) {
           std::cout << "Turno " << i << ": " << siguiente() << std::endl;
       }
   }

   void RotacionCircular::imprimirRotacion() const {
       if (cola == nullptr) { std::cout << "Rotacion vacia." << std::endl; return; }
       NodoLocutor* cabeza = getCabeza();
       NodoLocutor* actual = cabeza;
       std::cout << "Rotacion: ";
       do {
           std::cout << actual->nombre;
           actual = actual->siguiente;
           if (actual != cabeza) { std::cout << " -> "; }
       } while (actual != cabeza);
       std::cout << " -> (inicio)" << std::endl;
   }

   int RotacionCircular::getCantidad() const { return cantidad; }
   bool RotacionCircular::estaVacia() const { return cola == nullptr; }

   bool RotacionCircular::existeLocutor(const std::string& nombre) const {
       return obtenerPosicion(nombre) != -1;
   }
}

	

