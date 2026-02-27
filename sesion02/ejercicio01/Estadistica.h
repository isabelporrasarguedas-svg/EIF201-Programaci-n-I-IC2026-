#ifndef ESTADISTICA_H
#define ESTADISTICA_H
#include <array>
#include <string>
constexpr int ROWS = 3;
constexpr int COLS = 3;

std::array<std::array<int, 3>, 3> Matrix();
void sumRows(const std::array<std::array<int, ROWS>, COLS>Matrix);
void sumCols(const std::array<std::array<int, ROWS>, COLS>Matrix);
void sumDiag(const std::array<std::array<int, ROWS>, COLS> Matrix);
//int Max(const std::array<int, 10>& arreglo);
//int Min(const std::array<int, 10>& arreglo);
//int Sum(const std::array<int, 10>& arreglo);
//double Average(const std::array<int, 10>& arreglo);
//void arrayInverse(const std::array<int, 20>& array);

#endif