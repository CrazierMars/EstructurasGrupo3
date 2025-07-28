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
    void ordenamientoInsercionIdAsc(producto arr[], int n);
    void ordenamientoInsercionIdDesc(producto arr[], int n);
    void ordenamientoInsercionNombreAsc(producto arr[], int n);
    void ordenamientoInsercionNombreDesc(producto arr[], int n);
    void ordenamientoInsercionPrecioAsc(producto arr[], int n);
    void ordenamientoInsercionPrecioDesc(producto arr[], int n);
    void ordenamientoInsercionCantidadAsc(producto arr[], int n);
    void ordenamientoInsercionCantidadDesc(producto arr[], int n);
};

#endif // LISTA_PRODUCTOS_H