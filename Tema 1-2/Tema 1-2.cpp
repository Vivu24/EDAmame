// Javier Tirado Ríos
// VJ61

#include <iostream>
#include <fstream>

using namespace std;

// Función que resuelve el problema
void resolver(int* datos, int nums, int& pico, int& valle) {
    pico = 0;
    valle = 0;

    for (int i = 1; i < nums - 1; i++) {
        if (datos[i - 1] < datos[i] && datos[i] > datos[i + 1]) {
            pico++;
        }
        else if (datos[i - 1] > datos[i] && datos[i] < datos[i + 1]) {
            valle++;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int entrada;
    cin >> entrada;

    int* datos = new int[entrada];

    for (int i = 0; i < entrada; i++) {
        cin >> datos[i];
    }

    int picos, valles;
    resolver(datos, entrada, picos, valles);

    cout << picos << " " << valles << endl;

    // Liberar memoria
    delete[] datos;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para aceptar el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para aceptar el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
