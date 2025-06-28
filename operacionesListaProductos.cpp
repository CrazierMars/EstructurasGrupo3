#include "listaProductos.h"
#include <iostream>
using namespace std;

// getters
producto* listaProductos::getPrimero() {
    return primero;
}

producto* listaProductos::getUltimo(){
    producto* actual = primero; 
    if(actual == nullptr) {
        cout << "La Lista esta vacia" << endl;
    }
    while(actual ->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    return actual;
}

// Buscar productos por id, nombre o precio
producto* listaProductos::buscarProductoId(int pId) {
    producto* actual = primero;
    while (actual != nullptr){
        if (actual->getId() == pId){
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con ID " << pId << " no encontrado." << endl;
}
producto* listaProductos::buscarProductoNombre(const std::string& pNombre) {
    producto* actual = primero;
    while (actual != nullptr){
        if (actual->getNombre() == pNombre){
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con nombre " << pNombre << "no encontrado." << endl;
}
producto* listaProductos::buscarProductoPrecio(double pPrecio){
    producto* actual = primero; 
    while(actual != nullptr){
        if(actual->getPrecio() == pPrecio){
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
    cout << "Producto con precio " << pPrecio << "no encontrado." << endl;
}

// Metodos de insercion
void listaProductos::agregarProductoInicio(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad) {
    producto* nuevoProducto = new producto(pNuevoId, pNuevoNombre, pNuevoPrecio, pNuevaCantidad);
    nuevoProducto->setSiguiente(primero);
    primero = nuevoProducto;
}
void listaProductos::agregarProductoFinal(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad) {
    producto* nuevoProducto = new producto(pNuevoId, pNuevoNombre, pNuevoPrecio, pNuevaCantidad);
    if(primero == nullptr) {
        primero = nuevoProducto;
    } else {
        producto* ultimo = this->getUltimo();
        ultimo->setSiguiente(nuevoProducto);
    }
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
    while (actual != nullptr){
        contador++;
        actual = actual->getSiguiente();
    }
    return contador;
}
