/**
 * @author: Erick Alfredo García Huerta - A01708119 - @alfredohuerta
 *
 * @details: Archivo .h que alberga la función principal del problema.
 *
 * @date: 12 - febrero - 2024
 */

#ifndef RES_H
#define RES_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Activity {
public:
  vector<int> ej1_quitarep(vector<int>);
};

/**
 * @brief función que recibe un arreglo de números y elimina los dígitos
 * duplicados
 *
 * @param vector<int> arr
 * @return arreglo con números no repetidos ans
 */
vector<int> Activity::ej1_quitarep(vector<int> arr) {
  vector<int> ans;    // vector con la respuesta final
  vector<int> banned; // vector que almacena el índice de los números repetidos
  for (int i = 0; i < arr.size();
       i++) { // Ciclo que compara los elementos del arreglo con los otros
              // elementos del arreglo
    if (i ==
        arr.size() - 1) { // Identifica si se ha llegado al final del arreglo
      break;              // romple el ciclo
    }
    int j = i + 1;
    for (; j < arr.size();
         j++) { // compara un elemento i con los otros elemnto del arreglo
      if (arr[i] == arr[j]) { // identifica que encuentra un elemento repetido
        banned.push_back(
            j); // si encuentra un elemento repetido, se registra su índice
      }
    }
  }

  for (int i = 0; i < arr.size();
       i++) { // construye el arreglo final con la respuesta
    if (find(banned.begin(), banned.end(), i) !=
        banned.end()) { // busca el índice en la lista de repetidos
      continue; // salta al siguiente step del ciclo si hay una coincidencia
    }
    ans.push_back(arr[i]); // ingresa elementos en el arreglo de respuesta
  }

  return ans;
};

#endif // RES_H