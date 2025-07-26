#ifndef LISTA_PRODUCTOS_H
#define LISTA_PRODUCTOS_H

#include "producto.h"

using namespace std;

class listaProductos {
private:
    producto* primero;

public:
    //Constructor
    listaProductos(){
        primero = nullptr;
    }

    // Destructor
    ~listaProductos();

    // Metodos
    producto* getPrimero();
    producto* getUltimo();

    // Métodos de búsqueda
    producto* buscarId(int id);
    producto* buscarNombre(string nombre);
    producto* buscarPrecio(double precio);

    // Metodos de inserción
    void insertarInicio(int id, string nombre, double precio, int cantidad);
    void insertarFinal(int id, string nombre, double precio, int cantidad);

    // Métodos de eliminación
    producto* eliminar(string value, string target);

    // Métodos de impresión
    void imprimirLista();
    int contarProductos();
    bool imprimirVacia();

    bool estaVacia();
};

#endif // LISTA_PRODUCTOS_H