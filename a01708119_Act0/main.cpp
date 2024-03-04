/**
 * @author: Alfredo García Huerta - A01708119 - @alfredohuerta
 * 
 * @name:Actividad en clase 1 - TC2038
 * 
 * @details: Programa donde se le pida al usuario ingresar un arreglo de enteros, se impriman y 
 * se eliminen los elementos repetidos, así como se imprima el nuevo arreglo
 * 
 * @date: 12 - febrero - 2024
*/

#include <iostream>
#include <vector>

#include "res.h"

using namespace std;

int main() {
  int len;
  int temp;
  vector<int> list;
  vector<int> ans;

  cout << "Ingrese longitud del arreglo: ";
  cin >> len;

  cout << endl << "Ingrese los dígitos del arreglo: " << endl;

  for (int i = 0; i < len; i++) {
    cin >> temp;
    list.push_back(temp);
    temp = 0;
  }

  Activity act;
  ans = act.ej1_quitarep(list);

  cout << "Arreglo original: { ";

  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
  }

  cout << "}"
       << "\n"
       << "Arreglo sin duplicados: { ";

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  cout << "}";

  return 0;
}