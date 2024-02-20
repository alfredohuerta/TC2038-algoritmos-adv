/**
 * @authors: Rutilo Alberto De la Pena Rodriguez -----A01384647
 *           Alfredo García Huerta ----- A01708119
 * @date: 15 - febrero - 2024
 * @brief: Este header está encargado de llevar la mayoría de las funciones que
 * se utilizarán en el programa.
 */

#ifndef DNC_H
#define DNC_H

#include <vector>
using namespace std;

class DivideAndConquer {
public:
  /**
   * @brief: Este método es el constructor de la clase DivideAndConquer,
   * sólamente inicializa los atributos de la clase y manda a llamar a la
   * función de ordenamiento.
   * @param: vector<double> arr, int l, int r.
   * @return: No retorna nada.
   */
  void mergeSort(vector<double> &arr, int l, int r) {
    if (l < r) {
      int m = l + (r - l) / 2; // Divide el arreglo inicial a la mitad

      mergeSort(arr, l, m);     // Ordena la primera mitad
      mergeSort(arr, m + 1, r); // Ordena la segunda mitad

      merge(arr, l, m, r); // Une ambas mitades ordenadas
    }
  }

private:
  /**
   * @brief: Este método es el que realiza el ordenamiento de los datos y
   * realiza la comparación en el vector.
   * @param: vector<double> arr, int l, int m, int r.
   */
  void merge(vector<double> &arr, int l, int m, int r) {
    int i, j, k;        // Iteradores
    int n1 = m - l + 1; // Tamaño de la primera mitad
    int n2 = r - m;     // Tamaño de la segunda

    vector<double> L(n1),
        R(n2); // genera arreglos vacios para realizar comparaciones

    for (i = 0; i < n1; i++) // Llena los subarreglos
      L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    // Realiza las comparaciones y ordena los elementos
    while (i < n1 && j < n2) {
      if (L[i] >= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
    }
  }
};

#endif // DNC_H
