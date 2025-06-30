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
    if(actual == nullptr) {
        cout << "La Lista esta vacia" << endl;
    }
    while(actual ->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    return actual;
}

// Metodos de búsqueda
producto* listaProductos::buscarId(int pId) {
    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getId() == pId) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con ID " << pId << " no encontrado." << endl;
}
producto* listaProductos::buscarNombre(const string& pNombre) {
    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getNombre() == pNombre) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con nombre " << pNombre << "no encontrado." << endl;
}
producto* listaProductos::buscarPrecio(double pPrecio) {
    producto* actual = primero; 
    while(actual != nullptr) {
        if(actual->getPrecio() == pPrecio) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
    cout << "Producto con precio " << pPrecio << "no encontrado." << endl;
}

// Metodos de inserción
void listaProductos::insertarInicio(int pNuevoId, const string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad) {
    if (buscarId(pNuevoId) != nullptr) {
        cout << "Ya existe un producto con el mismo ID." << endl;
        return;
    }
    producto* nuevoProducto = new producto(pNuevoId, pNuevoNombre, pNuevoPrecio, pNuevaCantidad);
    nuevoProducto->setSiguiente(primero);
    primero = nuevoProducto;
}
void listaProductos::insertarFinal(int pNuevoId, const string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad) {
    if (buscarId(pNuevoId) != nullptr) {
        cout << "Ya existe un producto con el mismo ID." << endl;
        return;
    }
    producto* nuevoProducto = new producto(pNuevoId, pNuevoNombre, pNuevoPrecio, pNuevaCantidad);
    if(primero == nullptr) {
        primero = nuevoProducto;
    } else {
        producto* ultimo = this->getUltimo();
        ultimo->setSiguiente(nuevoProducto);
    }
}

// Métodos de eliminación
producto *listaProductos::eliminarPorNombre(string &pNombreEliminar) {
    if(primero == nullptr) {
        cout << "La lista esta vacia." << endl;
        return nullptr;
    }
    producto* anterior = nullptr;
    producto* actual = primero;
    while(actual != nullptr && actual->getNombre() != pNombreEliminar) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if(actual == nullptr) {
        cout << "El producto no existe." << endl;
        return nullptr;
    }
    if(actual == primero) {
        primero = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }
    delete actual;
    return actual;
}

//
void listaProductos::imprimirLista() {
    producto* actual = primero; 
    if (primero == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }while(actual != nullptr) {
        cout << "ID: " << actual->getId() << ", Nombre: " << actual->getNombre()
             << ", Precio: " << actual->getPrecio() << ", Cantidad: " << actual->getCantidad() << endl;
        actual = actual->getSiguiente();
    }
}
//cantidad de productos en la lista
int listaProductos::contarProductos() {
    int contador = 0;
    producto* actual = primero; 
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }
    return contador;
}