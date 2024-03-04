/**
* @brief: Este archivo .h está encargado deresolver el problemade las monedas
 * utilizando un enfoque de algoritmo avaro.
 * @authors: Rutilo Alberto De la Pena Rodriguez A01384647
 *           Alfredo García Huerta - A01708119
 * @date: 19 - febrero - 2024
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreedyCoin {
public:
    void cambio(int N, vector<int> &denominaciones, int P, int Q) {
        int T = Q - P;
        vector<int> result(N, 0);
        for (int i = 0; i < N; i++) {
            result[i] = T / denominaciones[i];
            T -= result[i] * denominaciones[i];
        }

        cout << "Cambio: " << endl;
        for (int i = 0; i < N; i++) {
            cout << "Denominacion: " << denominaciones[i] << " Cantidad: " << result[i] << endl;
        }
    }
};

