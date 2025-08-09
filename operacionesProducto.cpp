#include "producto.h"
#include <iostream>

int producto::getId() {
    return id;
}
std::string producto::getNombre() {
    return nombre;
}
double producto::getPrecio() {
    return precio;
}
int producto::getCantidad() {
    return cantidad;
}
producto* producto::getHijoIzquierdo() { 
    return hijoIzquierdo;
}
producto* producto::getHijoDerecho() { 
    return hijoDerecho; 
}

void producto::setId(int id) {
    this->id = id;
}
void producto::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}
void producto::setPrecio(double precio) {
    this->precio = precio;
}
void producto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void producto::setHijoIzquierdo(producto* hijoIzquierdo) { 
    this->hijoIzquierdo = hijoIzquierdo; 
}
void producto::setHijoDerecho (producto* hijoDerecho){ 
    this->hijoDerecho  = hijoDerecho;  
}


void producto::imprimir() {
    std::cout << "\nID: " << id << " | Nombre: " << nombre << " | Precio: " << precio << " | Cantidad: " << cantidad << std::endl;
}