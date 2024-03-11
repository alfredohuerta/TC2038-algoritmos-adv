/**
 * @name {Actividad 2.1 Implementación de "Hash String"}
 *
 * @authors {Rutilo Alberto De la Pena Rodriguez A01384647}
 * @authors {Erick Alfredo García Huerta - A01708119}
 *
 * @details {Escribe un programa en C++ que reciba el nombre de un archivo de
 * texto, seguido de un entero n, donde n es un entero múltiplo de 4 y (16 <= n
 * <=64) La salida es una cadena de longitud n/4 que es una representación
 * hexadecimal que corresponde al hasheo del archivo de texto de entrada de
 * acuerdo con las siguientes reglas: El entero n determina el número de
 * columnas que contendrá una tabla donde se irán acomodando los caracteres del
 * archivo de texto(incluyendo saltos de líneas) en los renglones que sean
 * necesarios. Si el numero de caracteres en el archivo de entrada no es
 * múltiplo de n, el último renglón se "rellena" con el valor de n En un arreglo
 * a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la
 * columna) % 256 la salida se genera concatenando la representación hexadecimal
 * (mayúsculas) a dos dígitos de cada posición en el arreglo. La longitud de la
 * cadena de salida será de n/4.}
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Analisis de Complejidad: O(n^2) esto debido a que se tienen ciclos for
 * anidados de longitud n cuando se está haciendo la suma de los valores ASCII
 * de cada caracter en la columna.
 */
string hashFile(const string &fileName, int n) {
  ifstream file(fileName);
  if (!file.is_open()) {
    cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
    return "";
  }

  vector<char> chars;
  char c;
  while (file.get(c)) { // Lee cada carácter del archivo y lo agrega al vector
    chars.push_back(c);
  }

  int numRows =
      (chars.size() + n - 1) / n; // Calcula el número de filas necesario
  vector<int> a(n);               // Declara un vector de enteros de tamaño n

  for (int i = 0; i < numRows; ++i) {
    int start =
        i * n; // Posición de inicio de la fila en el vector de caracteres
    int end = min(start + n,
                  static_cast<int>(chars.size())); // Posición de fin de la fila
    int sum = 0; // Inicializa la suma de caracteres
    for (int j = start; j < end;
         ++j) { // Suma los valores ASCII de los caracteres en la fila
      sum += static_cast<int>(chars[j]);
    }
    a[i] =
        sum % 256; // Calcula el hash para la fila y lo guarda en el vector 'a'
  }

  string hash;
  char buffer[3]; // Declara un buffer para convertir los valores a hexadecimal
  for (int i = 0; i < n;
       ++i) { // Convierte los valores del vector 'a' a formato hexadecimal
    snprintf(buffer, sizeof(buffer), "%02X", a[i]);
    hash += buffer; // Concatena los valores al hash final
  }

  return hash;
}

int main() {
  string fileName; // Variable para almacenar el nombre del archivo
  int n;           // Variable para almacenar el valor de n

  cout << "AVISO!!!, el archivo que va a utilizar en el programa debe estar en "
          "la carpeta de ejecucion"
       << endl;
  cout << "Ingrese el nombre del archivo de texto con extensión: ";
  cin >> fileName;
  cout << "Ingrese el valor de n: ";
  cin >> n;

  if (n % 4 != 0 || n < 16 ||
      n > 64) { // Verifica si n cumple con las condiciones
    cerr << "Error: n debe ser un entero múltiplo de 4 y estar entre 16 y 64"
         << endl;
    return 1;
  }
  // Calcula el hash del archivo y lo muestra
  string hash = hashFile(fileName, n);
  cout << "Hash: " << hash << endl;

  return 0;
}
