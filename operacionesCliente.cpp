#include "cliente.h"
#include <iostream>

using namespace std;

cliente::cliente(string nombre, string apellidos, string cedula, int edad, int prioridad) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->cedula = cedula;
    this->edad = edad;
    this->prioridad = prioridad;
    this->productos = new listaProductos();
    this->siguiente = nullptr;
}

cliente::~cliente() {
    delete productos;
}

string cliente::getNombre() { 
    return nombre; 
}

string cliente::getApellidos() { 
    return apellidos; 
}

string cliente::getCedula() { 
    return cedula; 
}

int cliente::getEdad() { 
    return edad; 
}

int cliente::getPrioridad() { 
    return prioridad;
}

listaProductos* cliente::getProductos() { 
    return productos; 
}

cliente* cliente::getSiguiente() { 
    return siguiente; 
}

void cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void cliente::setApellidos(string apellidos) {
    this->apellidos = apellidos;
}

void cliente::setCedula(string cedula) {
    this->cedula = cedula;
}

void cliente::setEdad(int edad) {
    this->edad = edad;
}

void cliente::setPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

void cliente::setProductos(listaProductos* productos) {
    this->productos = productos;
}

void cliente::setSiguiente(cliente* siguiente) { 
    this->siguiente = siguiente; 
}

void cliente::agregarProducto(int id, string nombre, double precio, int cantidad) {
    productos->insertarFinal(id, nombre, precio, cantidad);
}

void cliente::imprimir() {
    cout << "Nombre: " << nombre << " " << apellidos << " | Cédula: " << cedula << " | Edad: " << edad << " | Prioridad: " << prioridad << endl;
    cout << "Productos comprados:" << endl;
    productos->imprimirLista();
}
