/**
 * @authors: Rutilo Alberto De la Pena Rodriguez A01384647
 *           Erick Alfredo García Huerta - A01708119
 *
@name:Actividad 1.2 Implementación de la técnica de programación "Programación
dinámica" y "algoritmos avaros"

 * @details: El programa recibe un número entero N, seguido de N valores enteros
   (uno en cada línea) que representan las diferentes denominaciones disponibles de
   las monedas. Seguido de esto, el programa recibe dos números enteros: P y Q,
   (uno en cada línea) por la entrada estándar, que representan P: el precio de un
   producto dado y Q: el billete o moneda con el que se paga dicho producto.
   La salida del programa es una lista de N valores correspondientes al número
   de monedas de cada denominación, de mayor a menor, una en cada línea, que se
   tienen que dar para dar el cambio por el producto pagado.
 *
 * @date: 19 - febrero - 2024
 */

#include <iostream>
#include <vector>

#include "dynamicCoin.h"
#include "greedyCoin.h" // Incluye el archivo de encabezado greedyCoin.h

using namespace std;

int main() {
  int N, temp, P, Q;
  vector<int> denominaciones;

  cout << "Ingrese la cantidad de denominaciones disponibles: ";

  cin >> N;

  cout << endl << "Ingrese las denominaciones: ";

  for (int i = 0; i < N; i++) {
    cin >> temp;
    denominaciones.push_back(temp);
  }

  sort(denominaciones.begin(), denominaciones.end(),
       greater<int>()); // Por comodidad, ordenamos de mayor a menor los elementos de las denominaciones

  cout << "Ingrese el precio del producto: ";
  cin >> P;

  cout << endl << "Ingrese el billete con el que se paga: ";
  cin >> Q;

    cout << "Función algoritmo avaro: " << endl;
    GreedyCoin codicioso; // Crea una instancia de GreedyCoin
    codicioso.cambio(N, denominaciones, P, Q); // Llama a la función cambio de GreedyCoin

    cout << "Función de programación dinámica: " << endl;
    DynamicCoin dinamico;
    dinamico.cambio(N, denominaciones, P, Q);
    return 0;
}