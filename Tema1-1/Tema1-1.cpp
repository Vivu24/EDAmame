// Javier Tirado Ríos
// VJ61


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
bool resolver(int* datos, int n) {

    bool esDalton = true;
    bool ascendente = true;

    if (datos[0] < datos[1]) 
    {
        ascendente = true;
    }
    else if (datos[0] > datos[1]) 
    {
        ascendente = false;
    }
    else
    {
        esDalton = false;
    }


    int i = 0;

    while (ascendente && esDalton && i < n - 1)
    {
        if (!(datos[i] < datos[i + 1])) 
        {
            esDalton = false;
        }
        i++;
    }
    int j = 0;
    while (!ascendente && esDalton && j < n - 1)
    {
        if (!(datos[j] > datos[j + 1]))
        {
            esDalton = false;
        }
        j++;
    }

    /*for (int i = 0; i < n - 1; i++) {
        if (!(datos[i] < datos[i + 1])) {
            esDalton = false;
            break; // Puedes salir del bucle tan pronto como detectes que no son Dalton.
        }
    }*/

    return esDalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int entrada;
    cin >> entrada;

    if (entrada == 0)
        return false;

    int* datos = new int[entrada];

    for (int i = 0; i < entrada; i++) 
    {
        cin >> datos[i];
    }
    bool sol = resolver(datos, entrada);

    // escribir sol
    if (sol)
    {
        cout << "DALTON" << endl;
    }
    else
    {
        cout << "DESCONOCIDOS" << endl;
    }
    delete[] datos;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
