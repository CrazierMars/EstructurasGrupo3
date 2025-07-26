#include <string>
#include "listaProductos.h"

#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

class cliente {
private:
    string nombre;
    string apellidos;
    string cedula;
    int edad;
    int prioridad;
    listaProductos* productos;
    cliente* siguiente;

public:
    cliente(string nombre, string apellidos, string cedula, int edad, int prioridad);
    ~cliente();

    string getNombre();
    string getApellidos();
    string getCedula();
    int getEdad();
    int getPrioridad();
    listaProductos* getProductos();
    cliente* getSiguiente();

    void setNombre(string nombre);
    void setApellidos(string apellidos);
    void setCedula(string cedula);
    void setEdad(int edad);
    void setPrioridad(int prioridad);
    void setProductos(listaProductos* productos);
    void setSiguiente(cliente* siguiente);

    void agregarProducto(int id, string nombre, double precio, int cantidad);
    void imprimir();
};

#endif
