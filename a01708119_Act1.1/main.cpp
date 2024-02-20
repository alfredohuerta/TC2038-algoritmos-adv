/**
 * @authors: Rutilo Alberto De la Pena Rodriguez A01384647
 *           Alfredo García Huerta - A01708119
 *
 * @name:Actividad 1.1 Implementación de la técnica de programación "divide y
 * vencerás"
 *
 * @details: Utilizando la técnica de programación de "divide y vencerás",
 * escribe en equipos de máximo dos personas, en C++ un programa que implemente
 * el algoritmo de MergeSort El programa recibe un numero entero N, seguido de N
 * valores reales (double, uno en cada línea) por la entrada estándar. La salida
 * del programa es una lista de los N valores ordenados de Mayor a menor
 *
 * @date: 15 - febrero - 2024
 */
#include "dnc.h"
#include <iostream>

int main() {
  int N;
  cout << "Inserte longitud del arreglo: ";
  cin >> N;
  vector<double> arr(N);
  cout << endl << "Inserte los valores del arreglo: " << endl; // valores del arreglo
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  DivideAndConquer dnc;
  dnc.mergeSort(arr, 0, N - 1);// Llama al método mergeSort de la instancia dnc para ordenar el arreglo arr

  cout << "Arreglo ordenado: ";
  for (int i = 0; i < N; i++)
    cout << " " << arr[i] << " ";

  return 0;
}
