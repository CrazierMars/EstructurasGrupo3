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
	cout << "7. Ordenar catálogo" << endl;
	cout << "8. Buscar en catálogo" << endl;
	cout << "9. Salir" << endl;
	cout << "Seleccione una opción: ";
}

void menuOrdenamientos() {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "es_ES.UTF-8");
	cout << "\n--- Menú de Ordenamientos ---" << endl;
	cout << "1. Ordenamiento por Inserción" << endl;
	cout << "2. Ordenamiento por Selección" << endl;
	cout << "3. Ordenamiento por Burbuja" << endl;
	cout << "4. Ordenamiento por Mezcla" << endl;
	cout << "5. Volver." << endl;
	cout << "Seleccione una opción: ";
}

void menuOrdenamientoSeleccionado(string tipoOrdenamiento) {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "es_ES.UTF-8");
	cout << "\n--- Ordenamiento por " << tipoOrdenamiento << " ---" << endl;
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

void menuBusqueda() {
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "es_ES.UTF-8");
	cout << "\n--- Menú de Búsqueda ---" << endl;
	cout << "1. Buscar por ID (lineal)" << endl;
	cout << "2. Buscar por Nombre (lineal)" << endl;
	cout << "3. Buscar por Precio (lineal)" << endl;
	cout << "4. Buscar por Cantidad (lineal)" << endl;
	cout << "5. Buscar por ID (binaria)" << endl;
	cout << "6. Buscar por Nombre (binaria)" << endl;
	cout << "7. Buscar por Precio (binaria)" << endl;
	cout << "8. Buscar por Cantidad (binaria)" << endl;
	cout << "9. Volver" << endl;
	cout << "Seleccione una opción: ";
}

void mostrarCatalogoOrdenado(listaProductos& catalogo, string metodo) {
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

    if (metodo == "insercion") {
        switch (opcion) {
            case 1: catalogo.ordenamientoInsercionIdAsc(arr, n); break;
            case 2: catalogo.ordenamientoInsercionIdDesc(arr, n); break;
            case 3: catalogo.ordenamientoInsercionNombreAsc(arr, n); break;
            case 4: catalogo.ordenamientoInsercionNombreDesc(arr, n); break;
            case 5: catalogo.ordenamientoInsercionPrecioAsc(arr, n); break;
            case 6: catalogo.ordenamientoInsercionPrecioDesc(arr, n); break;
            case 7: catalogo.ordenamientoInsercionCantidadAsc(arr, n); break;
            case 8: catalogo.ordenamientoInsercionCantidadDesc(arr, n); break;
            default: cout << "Opción no válida." << endl; delete[] arrPtr; delete[] arr; return;
        }
    }
    if (metodo == "burbuja") {
        switch (opcion) {
            case 1: catalogo.ordenamientoBurbujaIdAsc(arr, n); break;
            case 2: catalogo.ordenamientoBurbujaIdDesc(arr, n); break;
            case 3: catalogo.ordenamientoBurbujaNombreAsc(arr, n); break;
            case 4: catalogo.ordenamientoBurbujaNombreDesc(arr, n); break;
            case 5: catalogo.ordenamientoBurbujaPrecioAsc(arr, n); break;
            case 6: catalogo.ordenamientoBurbujaPrecioDesc(arr, n); break;
            case 7: catalogo.ordenamientoBurbujaCantidadAsc(arr, n); break;
            case 8: catalogo.ordenamientoBurbujaCantidadDesc(arr, n); break;
            default: cout << "Opción no válida." << endl; delete[] arrPtr; delete[] arr; return;
        }
    }
    if (metodo == "mezcla") {
        switch (opcion) {
            case 1: catalogo.ordenamientoMezclaIdAsc(arr, n); break;
            case 2: catalogo.ordenamientoMezclaIdDesc(arr, n); break;
            case 3: catalogo.ordenamientoMezclaNombreAsc(arr, n); break;
            case 4: catalogo.ordenamientoMezclaNombreDesc(arr, n); break;
            case 5: catalogo.ordenamientoMezclaPrecioAsc(arr, n); break;
            case 6: catalogo.ordenamientoMezclaPrecioDesc(arr, n); break;
            case 7: catalogo.ordenamientoMezclaCantidadAsc(arr, n); break;
            case 8: catalogo.ordenamientoMezclaCantidadDesc(arr, n); break;
            default: cout << "Opción no válida." << endl; delete[] arrPtr; delete[] arr; return;
        }
    }
    if (metodo == "seleccion") {
        switch (opcion) {
            case 1: catalogo.ordenamientoSeleccionIdAsc(arr, n); break;
            case 2: catalogo.ordenamientoSeleccionIdDesc(arr, n); break;
            case 3: catalogo.ordenamientoSeleccionNombreAsc(arr, n); break;
            case 4: catalogo.ordenamientoSeleccionNombreDesc(arr, n); break;
            case 5: catalogo.ordenamientoSeleccionPrecioAsc(arr, n); break;
            case 6: catalogo.ordenamientoSeleccionPrecioDesc(arr, n); break;
            case 7: catalogo.ordenamientoSeleccionCantidadAsc(arr, n); break;
            case 8: catalogo.ordenamientoSeleccionCantidadDesc(arr, n); break;
            default: cout << "Opción no válida." << endl; delete[] arrPtr; delete[] arr; return;
        }
    }

    string message = "\nCatálogo ordenado por ";

    switch (opcion) {
        case 1: message += "ID Ascendente:\n"; break;
        case 2: message += "ID Descendente:\n"; break;
        case 3: message += "Nombre Ascendente:\n"; break;
        case 4: message += "Nombre Descendente:\n"; break;
        case 5: message += "Precio Ascendente:\n"; break;
        case 6: message += "Precio Descendente:\n"; break;
        case 7: message += "Cantidad Ascendente:\n"; break;
        case 8: message += "Cantidad Descendente:\n"; break;
    }

	cout << message;

	for (int i = 0; i < n; ++i) {
		cout << "ID: " << arr[i].getId() << ", Nombre: " << arr[i].getNombre() << ", Precio: " << arr[i].getPrecio() << ", Cantidad: " << arr[i].getCantidad() << endl;
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

	catalogo.insertarFinal("Arroz", 2000, 5);
	catalogo.insertarFinal("Frijoles", 1000, 7);
	catalogo.insertarFinal("Leche", 4000, 3);

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
							menuOrdenamientoSeleccionado("Inserción");
							mostrarCatalogoOrdenado(catalogo, "insercion");
							break;
						case 2:
							menuOrdenamientoSeleccionado("Selección");
							mostrarCatalogoOrdenado(catalogo, "seleccion");
							break;
						case 3:
							menuOrdenamientoSeleccionado("Burbuja");
							mostrarCatalogoOrdenado(catalogo, "burbuja");
							break;
						case 4:
							menuOrdenamientoSeleccionado("Mezcla");
							mostrarCatalogoOrdenado(catalogo, "mezcla");
							break;
						case 5:
							cout << "\nVolviendo al menu principal..." << endl;
							break;
						default:
							cout << "Opción no válida.\n";
							break;
					}
				} while (tipoOrdenamiento != 5);
				break;
			}
			case '8': {
				if (catalogo.estaVacia()) {
					cout << "El catálogo está vacío. No se puede ordenar.\n";
					break;
				}

				int tipoBusqueda;
				int id = 0, cantidad = 0;
				double precio = 0.0;
				string nombre = "";
				producto* productoEncontrado = nullptr;

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

				do {
					menuBusqueda();
					cin >> tipoBusqueda;
					switch (tipoBusqueda) {
						case 1:
							cout << "Ingrese el ID del producto a buscar: ";
							cin >> id;
							productoEncontrado = catalogo.buscarId(id);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 2:
							cout << "Ingrese el nombre del producto a buscar: ";
							cin >> nombre;
							productoEncontrado = catalogo.buscarNombre(nombre);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 3:
							cout << "Ingrese el precio del producto a buscar: ";
							cin >> precio;
							productoEncontrado = catalogo.buscarPrecio(precio);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 4:
							cout << "Ingrese el cantidad del producto a buscar: ";
							cin >> cantidad;
							productoEncontrado = catalogo.buscarCantidad(cantidad);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						// Búsqueda binaria
						case 5:
							cout << "Ingrese el ID del producto a buscar: ";
							cin >> id;
							catalogo.ordenamientoInsercionIdAsc(arr, n);
							productoEncontrado = catalogo.busquedaBinariaPorId(arr, n, id);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 6:
							cout << "Ingrese el nombre del producto a buscar: ";
							cin >> nombre;
							catalogo.ordenamientoInsercionNombreAsc(arr, n);
							productoEncontrado = catalogo.busquedaBinariaPorNombre(arr, n, nombre);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 7:
							cout << "Ingrese el precio del producto a buscar: ";
							cin >> precio;
							catalogo.ordenamientoInsercionPrecioAsc(arr, n);
							productoEncontrado = catalogo.busquedaBinariaPorPrecio(arr, n, precio);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 8:
							cout << "Ingrese el cantidad del producto a buscar: ";
							cin >> cantidad;
							catalogo.ordenamientoInsercionCantidadAsc(arr, n);
							productoEncontrado = catalogo.busquedaBinariaPorCantidad(arr, n, cantidad);
							if (productoEncontrado) {
								productoEncontrado->imprimir();
							} else {
								cout << "\nProducto no encontrado.\n";
							}
							break;
						case 9:
							cout << "\nVolviendo al menu principal..." << endl;
							break;
						default:
							cout << "Opción no válida.\n";
							break;
					}
				} while (tipoBusqueda != 9);
					break;
			}
		}
	} while (opcion != '9');

	cout << "Programa finalizado.\n";
	return 0;
}
