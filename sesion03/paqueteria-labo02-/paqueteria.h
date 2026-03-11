#ifndef PAQUETERIA_H
#define PAQUETERIA_H


double* crearRegristro(int& cant);

void IngresarPeso(double* pesos, int cant);

double calcularPesoTotal(const double* pesos, int cant);


int sobreLimite(const double* pesos, int cant, double limites);

const double*
buscaElmasPesado(const double* pesos, int cantidad);


#endif
