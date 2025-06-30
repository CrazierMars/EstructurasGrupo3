#include "listaProductos.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void mostrarMenu() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n==============================\n";
    cout << "---- MENU PRINCIPAL ----\n";
    cout << "1. Agregar producto al inicio\n";
    cout << "2. Agregar producto al final\n";
    cout << "3. Eliminar producto por nombre\n";
    cout << "4. Mostrar lista de productos\n";
    cout << "0. Salir\n";
    cout << "==============================\n";
    cout << "\nSeleccione una opcion: ";
}

int main (){
    listaProductos lista;
    int opcion, id, cantidad;
    string nombre;
    double precio;

    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: // Insertar al inicio
                cout << "Ingrese el id: ";
                cin >> id;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                lista.insertarInicio(id, nombre, precio, cantidad);
                break;

            case 2: // Insertar al final
                cout << "Ingrese el id: ";
                cin >> id;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                lista.insertarFinal(id, nombre, precio, cantidad);
                break;

            case 3: // Eliminar por nombre
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin >> nombre;
                lista.eliminarPorNombre(nombre);
                break;

            case 4: // Mostrar lista
                lista.imprimirLista();
                break;

            case 0: // Salir
                cout << "Saliendo del programa..." << endl;
                lista.~listaProductos();
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);

    return 0;
}