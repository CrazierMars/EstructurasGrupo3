#include <string>
#include "arbolProductos.h"

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
    arbolProductos* productos;
    cliente* siguiente;

public:
    cliente(string nombre, string apellidos, string cedula, int edad, int prioridad);
    ~cliente();

    string getNombre();
    string getApellidos();
    string getCedula();
    int getEdad();
    int getPrioridad();
    arbolProductos* getProductos();
    cliente* getSiguiente();

    void setNombre(string nombre);
    void setApellidos(string apellidos);
    void setCedula(string cedula);
    void setEdad(int edad);
    void setPrioridad(int prioridad);
    void setProductos(arbolProductos* productos);
    void setSiguiente(cliente* siguiente);

    void agregarProducto(string nombre, double precio, int cantidad, int padreId);
    void imprimir();
};

#endif
