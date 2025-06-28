#include <iostream>
#include "listaProductos.h"
#include <thread>
#include <chrono>
using namespace std;

void mostrarMenu() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n==============================\n";
    cout << "\n--- MENU PRINCIPAL ---\n";
    cout << "1. Agregar punto al inicio\n";
    cout << "2. Agregar punto al final\n";
    cout << "3. Eliminar punto\n";
    cout << "4. Imprimir lista de puntos\n";
    cout << "5. Buscar punto\n";
    cout << "6. Invertir lista\n";
    cout << "7. Mostrar longitud de la lista\n";
    cout << "8. Punto más cercano al origen\n";
    cout << "9. Punto más lejano al origen\n";
    cout << "10. Salir\n";
    cout << "\n==============================\n";
    // cout << "Seleccione una opción: ";
}
int main (){


    return 0;
}