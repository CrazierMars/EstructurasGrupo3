#include "producto.h"

// Getters
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

// Setters 
void producto::setId(int pId) {
    id = pId;
}
void producto::setNombre(const std::string& pNombre) {
    nombre = pNombre;
}
void producto::setPrecio(double pPrecio) {
    precio = pPrecio;
}
void producto::setCantidad(int pCantidad) {
    cantidad = pCantidad;
}
void producto::setSiguiente(producto* nuevoSiguiente) {
    siguiente = nuevoSiguiente;
}