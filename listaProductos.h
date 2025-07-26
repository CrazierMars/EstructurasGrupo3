#ifndef LISTA_PRODUCTOS_H
#define LISTA_PRODUCTOS_H

#include "producto.h"

using namespace std;

class listaProductos {
private:
    producto* primero;

public:
    listaProductos(){
        primero = nullptr;
    }

    ~listaProductos();

    producto* getPrimero();
    producto* getUltimo();

    producto* buscarId(int id);
    producto* buscarNombre(string nombre);
    producto* buscarPrecio(double precio);
    producto* buscarCantidad(int cantidad);

    void insertarInicio(string nombre, double precio, int cantidad);
    void insertarFinal(string nombre, double precio, int cantidad);

    producto* eliminar(string value, string target);

    void imprimirLista();
    int contarProductos();
    bool imprimirVacia();

    bool estaVacia();
    int generarId();

    // Métodos de ordenamiento
    //Ordenamiento por Insercion
    void OrdenamientoInsercionIdAsc(producto arr[], int n);
    void OrdenamientoInsercionIdDesc(producto arr[], int n);
    void OrdenamientoInsercionNombreAsc(producto arr[], int n);
    void OrdenamientoInsercionNombreDesc(producto arr[], int n);
    void OrdenamientoInsercionPrecioAsc(producto arr[], int n);
    void OrdenamientoInsercionPrecioDesc(producto arr[], int n);
    void OrdenamientoInsercionCantidadAsc(producto arr[], int n);
    void OrdenamientoInsercionCantidadDesc(producto arr[], int n);
};

#endif // LISTA_PRODUCTOS_H