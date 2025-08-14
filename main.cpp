#include <windows.h>
#include <iostream>
#include "arbolProductos.h"
#include "producto.h"
#include "colaClientes.h"
#include "cliente.h"

using namespace std;

void mostrarMenu() {
	SetConsoleOutputCP(CP_UTF8);
	
	std::cout << "\n--- Menú Principal ---" << endl;
	std::cout << "1. Agregar producto al catálogo" << endl;
	std::cout << "2. Eliminar producto del catálogo" << endl;
	std::cout << "3. Mostrar catálogo" << endl;
	std::cout << "4. Agregar cliente a la cola" << endl;
	std::cout << "5. Atender cliente (quitar de la cola)" << endl;
	std::cout << "6. Mostrar clientes en cola" << endl;
	std::cout << "7. Salir" << endl;
	std::cout << "Seleccione una opción: ";
}

void imprimirFactura(cliente* cliente) {
	SetConsoleOutputCP(CP_UTF8);

	std::cout << "\n--- Factura del cliente ---" << endl;
	cliente->imprimir();
	double total = 0;

	arbolProductos* productos = cliente->getProductos();
	productos->enOrden(productos->getRaiz(), [&total](producto* p) {
		total += p->getPrecio() * p->getCantidad();
	});

	std::cout << "\nTotal a cancelar: " << total << endl;
	std::cout << "--------------------------\n";
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	colaClientes cola;
	arbolProductos catalogo;
	char opcion;

	string nombre, apellidos, cedula, prodNombre;
	double precio;
	int id, cantidad, edad, nprod, cant, prioridad;

	catalogo.insertarNodo("Arroz", 2000, 5);
	catalogo.insertarNodo("Frijoles", 1000, 7);
	catalogo.insertarNodo("Leche", 4000, 3);

	do {
		mostrarMenu();
		cin >> opcion;
		cin.ignore();
		std::cout << endl;

		switch (opcion) {
			case '1': {
				std::cout << "Nombre del producto: "; getline(cin, nombre);
				std::cout << "Precio: "; cin >> precio;
				std::cout << "Cantidad: "; cin >> cantidad;
				catalogo.insertarNodo(nombre, precio, cantidad);
				std::cout << "\nProducto agregado al catálogo.\n";
				break;
			}
			case '2': {
				if (!catalogo.getRaiz()) {
					std::cout << "El catálogo está vacío\n";
					break;
				}

				std::cout << "Id del producto a eliminar: "; cin >> id;

				if (catalogo.eliminar(id)) {
					std::cout << "\nProducto eliminado.\n";
				} else {
					std::cout << "\nProducto no encontrado.\n";
				}
				break;
			}
			case '3': {
				if (!catalogo.getRaiz()) {
					std::cout << "El catálogo está vacío\n";
					break;
				}

				std::cout << "--- Catálogo de productos ---\n";
				catalogo.imprimir();
				break;
			}
			case '4': {
				if (!catalogo.getRaiz()) {
					std::cout << "No se puede agregar clientes, el catálogo está vacío.\n";
					break;
				}

				std::cout << "Nombre: "; cin >> nombre;
				std::cout << "Apellidos: "; cin >> apellidos;
				std::cout << "Cédula: "; cin >> cedula;
				std::cout << "Edad: "; cin >> edad; cin.ignore();
				std::cout << "Prioridad: \n1-Ordinario\n2-Regular\n3-Preferencial" << endl; 
				cin >> prioridad;

				cliente* nuevoCliente = new cliente(nombre, apellidos, cedula, edad, prioridad);
				std::cout << "¿Cuántos productos va a comprar?: ";
				cin >> nprod; cin.ignore();

				for (int i = 0; i < nprod; ++i) {
					producto* prod = nullptr;
					do {
						std::cout << "\nId del producto a comprar: "; 
						cin >> id;
						prod = catalogo.buscarNodo(id);
						if (!prod) {
							std::cout << "\nProducto no encontrado en catálogo. Intente nuevamente.\n\n";
						}
					} while (!prod);

					if (prod->getCantidad() < 1) {
						std::cout << "No hay stock disponible de ese producto.\n";
						continue;
					}

					bool cantidadValida = false;
					while (!cantidadValida) {
						std::cout << "Cantidad: "; cin >> cant;

						if (cant <= prod->getCantidad() && cant > 0) {
							nuevoCliente->agregarProducto(prod->getNombre(), prod->getPrecio(), cant, prod->getId());
							cantidadValida = true;
						} else {
							std::cout << "\nSolo hay " << prod->getCantidad() << " unidades disponibles. Ingrese una cantidad válida.\n";
						}
					}
				}

				cola.insertar(nuevoCliente);

				std::cout << "\nCliente agregado a la cola.\n";
				break;
			}
			case '5': {
				if (cola.estaVacia()) {
					std::cout << "No hay clientes en la cola.\n";
					break;
				}

				cliente* atendido = cola.quitarPorPrioridad();

				if (atendido) {
					arbolProductos* productosCliente = atendido->getProductos();
					producto* prodActual = productosCliente->getRaiz();

					productosCliente->enOrden(prodActual, [&catalogo](producto* p) {
						producto* prodCatalogo = catalogo.buscarNodo(p->getPadreId());

						if (prodCatalogo) {
							int nuevaCantidad = prodCatalogo->getCantidad() - p->getCantidad();
							if (nuevaCantidad < 0) nuevaCantidad = 0;
							prodCatalogo->setCantidad(nuevaCantidad);
						}
					});

					imprimirFactura(atendido);
					delete atendido;
				}

				break;
			}
			case '6': {
				if (cola.estaVacia()) {
					std::cout << "No hay clientes en la cola.\n";
					break;
				}

				std::cout << "--- Clientes en cola ---\n";
				cola.imprimirCola();
				break;
			}
		}
	} while (opcion != '7');

	std::cout << "Programa finalizado.\n";
	return 0;
}
