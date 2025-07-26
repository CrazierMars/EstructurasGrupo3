#include "listaProductos.h"
#include <iostream>

using namespace std;

listaProductos::~listaProductos() {
    producto* actual = primero;
    while (actual != nullptr) {
        producto* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr; // Opcional, pero asegura que la lista quede vacía
}

// Getters
producto* listaProductos::getPrimero() {
    return primero;
}
producto* listaProductos::getUltimo() {
    producto* actual = primero; 
    if (imprimirVacia()) {
        return nullptr;
    }
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    return actual;
}

// Metodos de búsqueda
producto* listaProductos::buscarId(int id) {
    if (imprimirVacia()) {
        return nullptr;
    }

    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getId() == id) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con ID " << id << " no encontrado." << endl;
}
producto* listaProductos::buscarNombre(string nombre) {
    if (imprimirVacia()) {
        return nullptr;
    }

    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getNombre() == nombre) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con nombre " << nombre << "no encontrado." << endl;
}
producto* listaProductos::buscarPrecio(double precio) {
    if (imprimirVacia()) {
        return nullptr;
    }

    producto* actual = primero; 
    while (actual != nullptr) {
        if (actual->getPrecio() == precio) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
    cout << "Producto con precio " << precio << "no encontrado." << endl;
}

// Metodos de inserción
void listaProductos::insertarInicio(int id, string nombre, double precio, int cantidad) {
    if (buscarId(id) != nullptr) {
        cout << "Ya existe un producto con el mismo ID." << endl;
        return;
    }
    producto* nuevoProducto = new producto(id, nombre, precio, cantidad);
    nuevoProducto->setSiguiente(primero);
    primero = nuevoProducto;
}
void listaProductos::insertarFinal(int id, string nombre, double precio, int cantidad) {
    if (buscarId(id) != nullptr) {
        cout << "Ya existe un producto con el mismo ID." << endl;
        return;
    }
    producto* nuevoProducto = new producto(id, nombre, precio, cantidad);
    if (primero == nullptr) {
        primero = nuevoProducto;
    } else {
        producto* ultimo = this->getUltimo();
        ultimo->setSiguiente(nuevoProducto);
    }
}

// Métodos de eliminación
producto *listaProductos::eliminar(string value, string target) {
    if (imprimirVacia()) {
        return nullptr;
    }

    producto* anterior = nullptr;
    producto* actual = primero;
    
    if (target == "nombre") {
        while (actual != nullptr && actual->getNombre() != value) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    if (target == "id") {
        int idEliminar = stoi(value);
        while (actual != nullptr && actual->getId() != idEliminar) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }
    
    if (actual == nullptr) {
        cout << "El producto no existe." << endl;
        return nullptr;
    }

    if (actual == primero) {
        primero = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual;
    return actual;
}

void listaProductos::imprimirLista() {
    if (!imprimirVacia()) {
        producto* actual = primero; 
        
        while(actual != nullptr) {
            cout << "ID: " << actual->getId() << ", Nombre: " << actual->getNombre()
                 << ", Precio: " << actual->getPrecio() << ", Cantidad: " << actual->getCantidad() << endl;
            actual = actual->getSiguiente();
        }
    }
}

int listaProductos::contarProductos() {
    if (imprimirVacia()) {
        return 0;
    }

    int contador = 0;
    producto* actual = primero; 
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }
    return contador;
}

bool listaProductos::estaVacia() {
    return primero == nullptr;
}

bool listaProductos::imprimirVacia() {
    if (estaVacia()) {
        cout << "La lista esta vacia." << endl;
        return true;
    }

    return false;
}