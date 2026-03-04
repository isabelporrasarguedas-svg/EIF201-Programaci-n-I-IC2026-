
#include <iostream>
using namespace std;
// Datos de prueba
// int datos[6] = {10, 30, 50, 20, 40, 60};
// Tarea A: imprima todos los elementos usando *(arr + i)
void imprimirTodo(int* arr, int n) {
    for (int row = 0; row < n; row++) {
        cout << "los elementos son: " << *(arr + n);
    }
}
// Tarea B: retorne el valor máximo usando aritmética de punteros
int encontrarMaximo(int* arr, int n) {
    int max = *arr

        for (int i = 0; i < n; i++) {

            if (*arr + n) > max)
            max = *(arr + n)
        }

}
// Tarea C: invierta el arreglo in-place usando dos punteros, uno al inicio, otro al final
void invertir(int* arr, int n) {

    int* izq = arr;
    int* der = arr;
    while (izq < der) {
        int temp = *izq;
        *izq = *der;
        *der = temp;
        izq++;
        der--;
    }
}
   




int main() {
    int datos[6] = { 10, 30, 50, 20, 40, 60 };
    imprimirTodo(datos, 6);
    // esperado: 10 30 50 20 40 60
        cout<< encontrarMaximo(datos, 6) << endl;
    // esperado: 60
    invertir(datos, 6);
    imprimirTodo(datos, 6); // esperado: 60 40 20 50 30 10
    return 0;
}



























   /* int temp = 35;
    int* ptemp = &temp;
    *ptemp = 36;
    temp = 40;

    std::cout << temp << std::endl;
    std::cout << *ptemp << std::endl;

}*/
