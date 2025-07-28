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


<<<<<<< Updated upstream
    return 0;
}
=======
void menuOrdenamientosInsercion() {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "es_ES.UTF-8");
	cout << "\n--- Ordenamiento por Inserción ---" << endl;
	cout << "1. Ordenar por ID Ascendente" << endl;
	cout << "2. Ordenar por ID Descendente" << endl;
	cout << "3. Ordenar por Nombre Ascendente" << endl;
	cout << "4. Ordenar por Nombre Descendente" << endl;
	cout << "5. Ordenar por Precio Ascendente" << endl;
	cout << "6. Ordenar por Precio Descendente" << endl;
	cout << "7. Ordenar por Cantidad Ascendente" << endl;
	cout << "8. Ordenar por Cantidad Descendente" << endl;
	cout << "Seleccione una opción: ";
}

void procesarSeleccionInsercion(listaProductos& catalogo) {
	int opcion;
	cin >> opcion;
	int n = catalogo.contarProductos();

	producto** arrPtr = new producto*[n];
	producto* actual = catalogo.getPrimero();
	for (int i = 0; i < n && actual != nullptr; ++i) {
		arrPtr[i] = actual;
		actual = actual->getSiguiente();
	}

	producto* arr = new producto[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = *arrPtr[i];
	}

	switch (opcion) {
		case 1:
			catalogo.ordenamientoInsercionIdAsc(arr, n);
			cout << "\nCatálogo ordenado por ID Ascendente:\n";
			break;
		case 2:
			catalogo.ordenamientoInsercionIdDesc(arr, n);
			cout << "\nCatálogo ordenado por ID Descendente:\n";
			break;
		case 3:
			catalogo.ordenamientoInsercionNombreAsc(arr, n);
			cout << "\nCatálogo ordenado por Nombre Ascendente:\n";
			break;
		case 4:
			catalogo.ordenamientoInsercionNombreDesc(arr, n);
			cout << "\nCatálogo ordenado por Nombre Descendente:\n";
			break;
		case 5:
			catalogo.ordenamientoInsercionPrecioAsc(arr, n);
			cout << "\nCatálogo ordenado por Precio Ascendente:\n";
			break;
		case 6:
			catalogo.ordenamientoInsercionPrecioDesc(arr, n);
			cout << "\nCatálogo ordenado por Precio Descendente:\n";
			break;
		case 7:
			catalogo.ordenamientoInsercionCantidadAsc(arr, n);
			cout << "\nCatálogo ordenado por Cantidad Ascendente:\n";
			break;
		case 8:
			catalogo.ordenamientoInsercionCantidadDesc(arr, n);
			cout << "\nCatálogo ordenado por Cantidad Descendente:\n";
			break;
		default:
			cout << "Opción no válida." << endl;
			delete[] arrPtr;
			delete[] arr;
			return;
	}

	for (int i = 0; i < n; ++i) {
		cout << "ID: " << arr[i].getId() << ", Nombre: " << arr[i].getNombre()
			<< ", Precio: " << arr[i].getPrecio() << ", Cantidad: " << arr[i].getCantidad() << endl;
	}

	delete[] arrPtr;
	delete[] arr;
}

void menuOrdenamientosMezcla() {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "es_ES.UTF-8");
	cout << "\n--- Ordenamiento por Mezcla ---" << endl;
	cout << "1. Ordenar por ID Ascendente" << endl;
	cout << "2. Ordenar por ID Descendente" << endl;
	cout << "3. Ordenar por Nombre Ascendente" << endl;
	cout << "4. Ordenar por Nombre Descendente" << endl;
	cout << "5. Ordenar por Precio Ascendente" << endl;
	cout << "6. Ordenar por Precio Descendente" << endl;
	cout << "7. Ordenar por Cantidad Ascendente" << endl;
	cout << "8. Ordenar por Cantidad Descendente" << endl;
	cout << "Seleccione una opción: ";
}

void procesarSeleccionMezcla(listaProductos& catalogo) {
	int opcion;
	cin >> opcion;
	int n = catalogo.contarProductos();
	if (n == 0) {
		cout << "No hay productos para ordenar." << endl;
		return;
	}

	producto** arrPtr = new producto*[n];
	producto* actual = catalogo.getPrimero();
	for (int i = 0; i < n && actual != nullptr; ++i) {
		arrPtr[i] = actual;
		actual = actual->getSiguiente();
	}

	producto* arr = new producto[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = *arrPtr[i];
	}

	switch (opcion) {
		case 1:
			catalogo.OrdenamientoMezclaIdAsc(arr, n);
			cout << "\nCatálogo ordenado por ID Ascendente:\n";
			break;
		case 2:
			catalogo.OrdenamientoMezclaIdDesc(arr, n);
			cout << "\nCatálogo ordenado por ID Descendente:\n";
			break;
		case 3:
			catalogo.OrdenamientoMezclaNombreAsc(arr, n);
			cout << "\nCatálogo ordenado por Nombre Ascendente:\n";
			break;
		case 4:
			catalogo.OrdenamientoMezclaNombreDesc(arr, n);
			cout << "\nCatálogo ordenado por Nombre Descendente:\n";
			break;
		case 5:
			catalogo.OrdenamientoMezclaPrecioAsc(arr, n);
			cout << "\nCatálogo ordenado por Precio Ascendente:\n";
			break;
		case 6:
			catalogo.OrdenamientoMezclaPrecioDesc(arr, n);
			cout << "\nCatálogo ordenado por Precio Descendente:\n";
			break;
		case 7:
			catalogo.OrdenamientoMezclaCantidadAsc(arr, n);
			cout << "\nCatálogo ordenado por Cantidad Ascendente:\n";
			break;
		case 8:
			catalogo.OrdenamientoMezclaCantidadDesc(arr, n);
			cout << "\nCatálogo ordenado por Cantidad Descendente:\n";
			break;
		default:
			cout << "Opción no válida." << endl;
			delete[] arrPtr;
			delete[] arr;
			return;
	}

	for (int i = 0; i < n; ++i) {
		cout << "ID: " << arr[i].getId() << ", Nombre: " << arr[i].getNombre()
			<< ", Precio: " << arr[i].getPrecio() << ", Cantidad: " << arr[i].getCantidad() << endl;
	}

	delete[] arrPtr;
	delete[] arr;
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
			case '1': {
				cout << "Nombre del producto: "; getline(cin, nombre);
				cout << "Precio: "; cin >> precio;
				cout << "Cantidad: "; cin >> cantidad;
				catalogo.insertarFinal(nombre, precio, cantidad);
				cout << "\nProducto agregado al catálogo.\n";
				break;
			}
			case '2': {
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
			}
			case '3': {
				if (catalogo.estaVacia()) {
					cout << "El catálogo está vacío\n";
					break;
				}

				cout << "--- Catálogo de productos ---\n";
				catalogo.imprimirLista();
				break;
			}
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
			case '6': {
				if (cola.estaVacia()) {
					cout << "No hay clientes en la cola.\n";
					break;
				}

				cout << "--- Clientes en cola ---\n";
				cola.imprimirCola();
				break;
			}
			case '7': {
				if (catalogo.estaVacia()) {
					cout << "El catálogo está vacío. No se puede ordenar.\n";
					break;
				}

                int tipoOrdenamiento;
                do {
                    menuOrdenamientos();
                    cin >> tipoOrdenamiento;
                    switch (tipoOrdenamiento) {
                        case 1:
                            menuOrdenamientosInsercion();
                            procesarSeleccionInsercion(catalogo);
                            break;
                        case 2:
                            cout << "Aqui deberia ir ordenamiento por seleccion" << endl;
                            break;
                        case 3:
                            cout << "Aqui deberia ir ordenamiento por burbuja" << endl;
                            break;
                        case 4:
                            menuOrdenamientosMezcla();
                            procesarSeleccionMezcla(catalogo);
                            break;
                        default:
                            cout << "Opción no válida.\n";
                            break;
                    }
                } while (tipoOrdenamiento != 5);
            }

			case '7':
    			if (catalogo.estaVacia()) {
        			cout << "El catálogo está vacío. No se puede ordenar.\n";
        			break;
    		}

    MenuOrdenamientos();
    int metodo;
    cin >> metodo;

    switch (metodo) {
        case 1: MenuOrdenamientosInsercion(); ProcesarSeleccionInsercion(catalogo); break;
        case 3: MenuOrdenamientosBurbuja(); ProcesarSeleccionBurbuja(catalogo); break;
        default: cout << "Método aún no implementado.\n"; break;
    }
    break;

        }
	} while (opcion != '8');


	void MenuOrdenamientosBurbuja() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "es_ES.UTF-8");
    cout << "\n--- Ordenamiento por Burbuja ---" << endl;
    cout << "1. Ordenar por ID Ascendente" << endl;
    cout << "2. Ordenar por ID Descendente" << endl;
    cout << "3. Ordenar por Nombre Ascendente" << endl;
    cout << "4. Ordenar por Nombre Descendente" << endl;
    cout << "5. Ordenar por Precio Ascendente" << endl;
    cout << "6. Ordenar por Precio Descendente" << endl;
    cout << "7. Ordenar por Cantidad Ascendente" << endl;
    cout << "8. Ordenar por Cantidad Descendente" << endl;
    cout << "Seleccione una opción: ";
}


void ProcesarSeleccionBurbuja(listaProductos& catalogo) {
    int opcion;
    cin >> opcion;
    int n = catalogo.contarProductos();

    if (n == 0) {
        cout << "No hay productos para ordenar." << endl;
        return;
    }

    producto** arrPtr = new producto*[n];
    producto* actual = catalogo.getPrimero();
    for (int i = 0; i < n && actual != nullptr; ++i) {
        arrPtr[i] = actual;
        actual = actual->getSiguiente();
    }

    producto* arr = new producto[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = *arrPtr[i];
    }

    switch (opcion) {
        case 1: catalogo.OrdenamientoBurbujaIdAsc(arr, n); break;
        case 2: catalogo.OrdenamientoBurbujaIdDesc(arr, n); break;
        case 3: catalogo.OrdenamientoBurbujaNombreAsc(arr, n); break;
        case 4: catalogo.OrdenamientoBurbujaNombreDesc(arr, n); break;
        case 5: catalogo.OrdenamientoBurbujaPrecioAsc(arr, n); break;
        case 6: catalogo.OrdenamientoBurbujaPrecioDesc(arr, n); break;
        case 7: catalogo.OrdenamientoBurbujaCantidadAsc(arr, n); break;
        case 8: catalogo.OrdenamientoBurbujaCantidadDesc(arr, n); break;
        default: cout << "Opción no válida." << endl;
            delete[] arrPtr;
            delete[] arr;
            return;
    }

    for (int i = 0; i < n; ++i) {
        cout << "ID: " << arr[i].getId() << ", Nombre: " << arr[i].getNombre()
             << ", Precio: " << arr[i].getPrecio() << ", Cantidad: " << arr[i].getCantidad() << endl;
    }

    delete[] arrPtr;
    delete[] arr;
}


	cout << "Programa finalizado.\n";
	return 0;
}
>>>>>>> Stashed changes
