#ifndef BRANCH_BOUND_H
#define BRANCH_BOUND_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// definición de constantes para las direcciones
const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, -1, 1, 0};

// estructura para representar una posición en el laberinto
struct Position {
    int row, col;
};

// funcion para verificar si una posición está dentro del laberinto
bool isValid(int row, int col, int M, int N) {
    return row >= 0 && row < M && col >= 0 && col < N;
}

// funcion para encontrar un camino utilizando la técnica de ramificación y poda
// Complejidad es de O(N*M), esto debido a que a pesar de que hay ciclos
// anidados, este es uno lineal O(1), ya que sólo se revisa una posición a la
// vez en un set definido y O(N*M) * 0(1) = O(N*M)
vector<vector<int>> findPath(const vector<vector<int>> &maze, int M, int N) {
    vector<vector<int>> solution(M, vector<int>(N, 0));
    queue<Position> q;
    q.push({0, 0}); // agregar la posición de inicio a la cola

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        // marcar la posición actual como parte del camino
        solution[curr.row][curr.col] = 1;

        // si alcanzamos la salida, detener la búsqueda
        if (curr.row == M - 1 && curr.col == N - 1)
            break;

        // explorar las 4 direcciones posibles
        for (int i = 0; i < 4; ++i) {
            int newRow = curr.row + dr[i];
            int newCol = curr.col + dc[i];

            // verificar si la nueva posición es válida y no ha sido visitada
            if (isValid(newRow, newCol, M, N) && maze[newRow][newCol] == 1 &&
                solution[newRow][newCol] == 0) {
                q.push({newRow, newCol});
                }
        }
    }

    return solution;
}

// función para imprimir una matriz
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif
