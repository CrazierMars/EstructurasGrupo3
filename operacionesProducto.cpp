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
producto* producto::getSiguiente() {
    return siguiente;
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
void producto::setSiguiente(producto* siguiente) {
    this->siguiente = siguiente;
}

void producto::imprimir() {
    std::cout << "ID: " << id << " | Nombre: " << nombre << " | Precio: " << precio << " | Cantidad: " << cantidad << std::endl;
}