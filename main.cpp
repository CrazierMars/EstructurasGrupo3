#include <windows.h>
#include <iostream>
#include "listaProductos.h"
#include "producto.h"
#include "colaClientes.h"
#include "cliente.h"

using namespace std;

void mostrarMenu() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES.UTF-8");

    cout << "\n--- Menú Principal ---" << endl;
    cout << "1. Agregar producto al catálogo" << endl;
    cout << "2. Eliminar producto del catálogo" << endl;
    cout << "3. Mostrar catálogo" << endl;
    cout << "4. Agregar cliente a la cola" << endl;
    cout << "5. Atender cliente (quitar de la cola)" << endl;
    cout << "6. Mostrar clientes en cola" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void imprimirFactura(cliente* cliente) {
    cout << "\n--- Factura del cliente ---" << endl;
    cliente->imprimir();
    double total = 0;

    producto* prod = cliente->getProductos()->getPrimero();

    while (prod != nullptr) {
        total += prod->getPrecio() * prod->getCantidad();
        prod = prod->getSiguiente();
    }

    cout << "Total a cancelar: " << total << endl;
    cout << "--------------------------\n";
}

int main() {
    colaClientes cola;
    listaProductos catalogo;
    char opcion;

    string nombre, apellidos, cedula, prodNombre;
    double precio;
    int cantidad, edad, nprod, cant, prioridad;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        cout << endl;

        switch (opcion) {
            case '1': 
                cout << "Nombre del producto: "; getline(cin, nombre);
                cout << "Precio: "; cin >> precio;
                cout << "Cantidad: "; cin >> cantidad;
                catalogo.insertarFinal(nombre, precio, cantidad);
                cout << "\nProducto agregado al catálogo.\n";
                break;
            
            case '2':
                if (catalogo.estaVacia()) {
                    cout << "El catálogo está vacío\n";
                    break;
                }

                cout << "Nombre del producto a eliminar: "; getline(cin, nombre);

                if (catalogo.eliminar(nombre, "nombre")) {
                    cout << "Producto eliminado.\n";
                } else {
                    cout << "Producto no encontrado.\n";
                }

                break;
            
            case '3': 
                if (catalogo.estaVacia()) {
                    cout << "El catálogo está vacío\n";
                    break;
                }

                cout << "--- Catálogo de productos ---\n";
                catalogo.imprimirLista();
                break;
            
            case '4': {
                if (catalogo.estaVacia()) {
                    cout << "No se puede agregar clientes, el catálogo está vacío.\n";
                    break;
                }

                cout << "Nombre: "; cin >> nombre;
                cout << "Apellidos: "; cin >> apellidos;
                cout << "Cédula: "; cin >> cedula;
                cout << "Edad: "; cin >> edad; cin.ignore();
                cout << "Prioridad: \n1-Ordinario\n2-Regular\n3-Preferencial "; cin >> prioridad;

                cliente* nuevoCliente = new cliente(nombre, apellidos, cedula, edad, prioridad);
                cout << "¿Cuántos productos va a comprar?: ";
                cin >> nprod; cin.ignore();
                
                for (int i = 0; i < nprod; ++i) {
                    producto* prod = nullptr;
                    do {
                        cout << "Nombre del producto a comprar: "; getline(cin, prodNombre);
                        prod = catalogo.buscarNombre(prodNombre);
                        if (!prod) {
                            cout << "\nProducto no encontrado en catálogo. Intente nuevamente.\n\n";
                        }
                    } while (!prod);

                    if (prod->getCantidad() < 1) {
                        cout << "No hay stock disponible de ese producto.\n";
                        continue;
                    }

                    bool cantidadValida = false;
                    while (!cantidadValida) {
                        cout << "Cantidad: "; cin >> cant;

                        if (cant <= prod->getCantidad() && cant > 0) {
                            nuevoCliente->agregarProducto(prod->getNombre(), prod->getPrecio(), cant);
                            cantidadValida = true;
                        } else {
                            cout << "\nSolo hay " << prod->getCantidad() << " unidades disponibles. Ingrese una cantidad válida.\n";
                        }
                    }
                }

                cola.insertar(nuevoCliente);

                cout << "\nCliente agregado a la cola.\n";
                break;
            }
            
            case '5': {
                if (cola.estaVacia()) {
                    cout << "No hay clientes en la cola.\n";
                    break;
                }

                cliente* atendido = cola.quitarPorPrioridad();

                if (atendido) {
                    producto* prodCliente = atendido->getProductos()->getPrimero();

                    while (prodCliente != nullptr) {
                        producto* prodCatalogo = catalogo.buscarNombre(prodCliente->getNombre());
                        if (prodCatalogo) {
                            int nuevaCantidad = prodCatalogo->getCantidad() - prodCliente->getCantidad();
                            if (nuevaCantidad < 0) nuevaCantidad = 0;
                            prodCatalogo->setCantidad(nuevaCantidad);
                        }
                        prodCliente = prodCliente->getSiguiente();
                    }

                    imprimirFactura(atendido);
                    delete atendido;
                }

                break;
            }
            case '6': 
                if (cola.estaVacia()) {
                    cout << "No hay clientes en la cola.\n";
                    break;
                }

                cout << "--- Clientes en cola ---\n";
                cola.imprimirCola();
                break;
            
        }
    } while (opcion != '7');

    cout << "Programa finalizado.\n";
    return 0;
}
