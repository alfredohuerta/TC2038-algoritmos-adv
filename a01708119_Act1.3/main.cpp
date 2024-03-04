/**
* @authors: Rutilo Alberto De la Pena Rodriguez A01384647
 *           Erick Alfredo García Huerta - A01708119
 *
@name:Actividad 1.3 Implementación de la técnica de programación "backtracking"
y "ramificación y poda"

 * @details: Utilizando la técnica de programación de "backtracking" y la de
"ramificación y poda", escribe en equipos de máximo dos peronas, en C++ un
programa que resuelva un laberinto. El programa recibe dos numeros enteros M y
N, seguido de M líneas de N valores booleanos(0|1) separados por un espacio, por
la entrada estándar que representan el laberinto.  Un 1 representa una casilla
en la que es posible moverse, un 0 es una casilla por la que NO se puede pasar.
El origen o casilla de inicio es siempre la casilla (0,0) y la salida o meta es
siempre la casilla (M-1, N-1) La salida del programa es una matriz de valores
booleanos (0|1) que representan el camino para salir del laberinto. Primero debe
mostrarse la solución utilizando la técnica de backtracking, y luego utilizando
la técnica de ramificación y poda.
 *
 * @date: 26 - febrero - 2024
 */

#include <iostream>
#include <vector>

#include "backtracking.h"
#include "branch&Bound.h"

int main() {
  int M, N;
  cout << "Ingrese el número de filas (M) y columnas (N) del laberinto: ";
  cin >> M >> N;

  vector<vector<int>> maze(M, vector<int>(N));

  cout << "Ingrese los valores del laberinto:" << endl;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> maze[i][j];
    }
  }

  // Encontrar el camino utilizando la técnica de ramificación y poda
  cout << "\nSolución utilizando la técnica de ramificación y poda:" << endl;
  cout << "Laberinto original:" << endl;
  printMatrix(maze);
  vector<vector<int>> solution = findPath(maze, M, N);

  // Imprimir la solución
  cout << "La solución al laberinto es:" << endl;
  printMatrix(solution);

  cout << "-------" << endl;

  cout << "\nSolución utilizando la técnica de backtraking:" << endl;
  cout << "Laberinto original: " << endl;
  printMatrix(maze);

  cout << "La solución al laberinto es:" << endl;
  Backtracking backSolution;
  vector<vector<int>> ans = backSolution.track(N, M, maze);
  printMatrix(ans);

  return 0;
}