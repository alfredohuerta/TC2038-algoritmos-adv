/**
* @brief: Este archivo .h está encargado deresolver el problemade las monedas
 * utilizando un enfoque de programación dinámica.
 * @authors: Rutilo Alberto De la Pena Rodriguez A01384647
 *           Alfredo García Huerta - A01708119
 * @date: 19 - febrero - 2024
 */
#ifndef DYNAMICCOIN_H
#define DYNAMICCOIN_H

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class DynamicCoin {
public:
    void cambio(int N, vector<int> &denominaciones, int P, int Q) {

        int T = Q - P;    // Calculamos el cambio que debemos dar
        map<int, int> dp; // Creamos un mapa vacío para almacenar las soluciones
        map<int, int>::iterator
            itr; // Creamos un iterador para movernos en la función

        dynamic(0, denominaciones, T, dp);

        cout << "Cambio: " << endl;
        for (itr = dp.end(); itr != dp.begin();) {
            --itr;
            cout << '\t' << "Denominacion: " << itr->first << '\t'
                 << " Cantidad: " << itr->second << '\n';
        }
    };

private:
    map<int, int> dynamic(int N, vector<int> &denominaciones, int T,
                          map<int, int> &dp) {
        // cout << "Entramos" << endl << "Target: " << T << " N: " << N << endl;
        // cout << "S: " << dp.size() << endl;
        if (T == 0) {
            dp.insert(make_pair(0, 0));
            return dp;
        } else {
            int coins =
                T / denominaciones[N]; // Calculamos la mayor cantidad de monedas
            // necesarias para acercarse al cambio
            dp.insert(make_pair(denominaciones[N],
                                coins)); // Registramos la cantidad en el map

            return dynamic(N + 1, denominaciones, T - (denominaciones[N] * coins),
                           dp); // Volvemos a llamar la función, pero reducimos el
            // target de cambio a dar con el resultado del
            // cociente de las monedas disponibles por el número
            // de monedas que se acercan a esa cantidad y
            // avanzamos en el arreglo de monedas disponibles
        }
    }
};

#endif // DYNAMICCOIN_H
