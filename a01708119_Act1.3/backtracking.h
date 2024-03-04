#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <map>
#include <vector>

using namespace std;

class Backtracking {
public:
  /**
   * @brief Algoritmo principal para la solución por backtracking.
   * @param maze {laberinto que se debe recorrer}
   * @param N {longitud del laberinto}
   * @param M {ancho del laberinto}
   */
  vector<vector<int>> track(const int N, const int M,
                            vector<vector<int>> maze) {
    vector<vector<int>> path(
        N,
        vector<int>(
            M, 0)); // Caminos válidos por los que tiene que pasar el algoritmo
    path[0][0] = 1;
    pair<int, int> prev{0, 0}; // ubicación previa en el mapa para regresar

    traverse(0, 0, path, maze, N, M, prev);

    return path;
  }

private:
  /**
   * @brief Algoritmo encargado de caminar el laberinto
   * @param x {localización en el eje horizontal}
   * @param y {localización en el eje vertical}
   * @param path {mapa con la lista del camino en el laberinto}
   * @param maze {laberinto a cruzar}
   * @param N {longitud del laberinto}
   * @param M {ancho del laberinto}
   * @param prev {posición previa en el laberinto a la que se puede regresar}
   *
   * @complexity O(N*M) {Esto debido a que se revisa una posición a la vez en el
   * mapa}
   *
   * @return path {mapa con la lista de valores x,y del camino hasta el momento}
   */
  vector<vector<int>> traverse(int x, int y, vector<vector<int>> &path,
                               vector<vector<int>> &maze, const int N,
                               const int M, pair<int, int> prev) {
    int xUp = x - 1;
    int xDown = x + 1;
    int yRight = y + 1;
    int yLeft = y - 1;

    if (x == N - 1 &&
        y == M - 1) // Caso base en la que se regesa el camino completado
    {
      return path;
    } else if (maze[x][yRight] == 1 &&
               (x != prev.first ||
                yRight != prev.second)) // Revisa el vecino de la derecha
    {
      path[x][yRight] = 1; // Registramos el camino
      prev = {x, y};
      return traverse(x, yRight, path, maze, N, M,
                      prev); // Nos movemos al nodo de la derecha
    } else if (maze[xDown][y] == 1 &&
               (xDown != prev.first ||
                y != prev.second)) // Revisa el vecino de abajo
    {
      path[xDown][y] = 1; // Registramos el camino
      prev = {x, y};
      return traverse(xDown, y, path, maze, N, M,
                      prev); // Nos movemos al nodo de abajo
    } else if (maze[x][yLeft] == 1 &&
               (x != prev.first ||
                yLeft != prev.second)) // Revisa el vecino de la izquierda
    {
      path[x][yLeft] = 1; // Registramos el camino
      prev = {x, y};
      return traverse(x, yLeft, path, maze, N, M,
                      prev); // Nos movemos al nodo de la izquierda
    } else if (maze[xUp][y] == 1 &&
               (xUp != prev.first ||
                y != prev.second)) // Revisa el vecino de arriba
    {
      path[xUp][y] = 1; // Registramos el camino
      prev = {x, y};
      return traverse(xUp, y, path, maze, N, M,
                      prev); // Nos movemos al nodo de arriba
    } else {                 // En caso de un callejón sin salida
      maze[x][y] = 0; // anulamos la posición actual para no volver a ella
      path[x][y] = 0; // anulamos la posición actual del camino
      return traverse(prev.first, prev.second, path, maze, N, M,
                      prev); // Regresamos a la ubicación previa en el laberinto
    }
    return path;
  }
};

#endif // BACKTRACKING_H
