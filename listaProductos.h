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

    void ordenamientoInsercionIdAsc(producto arr[], int n);
    void ordenamientoInsercionIdDesc(producto arr[], int n);
    void ordenamientoInsercionNombreAsc(producto arr[], int n);
    void ordenamientoInsercionNombreDesc(producto arr[], int n);
    void ordenamientoInsercionPrecioAsc(producto arr[], int n);
    void ordenamientoInsercionPrecioDesc(producto arr[], int n);
    void ordenamientoInsercionCantidadAsc(producto arr[], int n);
    void ordenamientoInsercionCantidadDesc(producto arr[], int n);

    void selectionSortIdAsc(producto arr[], int n);
    void selectionSortIdDesc(producto arr[], int n);
    void selectionSortNombreAsc(producto arr[], int n);
    void selectionSortNombreDesc(producto arr[], int n);
    void selectionSortPrecioAsc(producto arr[], int n);
    void selectionSortPrecioDesc(producto arr[], int n);
    void selectionSortCantidadAsc(producto arr[], int n);
    void selectionSortCantidadDesc(producto arr[], int n);

    void ordenamientoMezclaIdAsc(producto arr[], int n);
    void ordenamientoMezclaIdDesc(producto arr[], int n);
    void ordenamientoMezclaNombreAsc(producto arr[], int n);
    void ordenamientoMezclaNombreDesc(producto arr[], int n);
    void ordenamientoMezclaPrecioAsc(producto arr[], int n);
    void ordenamientoMezclaPrecioDesc(producto arr[], int n);
    void ordenamientoMezclaCantidadAsc(producto arr[], int n);
    void ordenamientoMezclaCantidadDesc(producto arr[], int n);
    
    void ordenamientoBurbujaIdAsc(producto arr[], int n);
    void ordenamientoBurbujaIdDesc(producto arr[], int n);
    void ordenamientoBurbujaNombreAsc(producto arr[], int n);
    void ordenamientoBurbujaNombreDesc(producto arr[], int n);
    void ordenamientoBurbujaPrecioAsc(producto arr[], int n);
    void ordenamientoBurbujaPrecioDesc(producto arr[], int n);
    void ordenamientoBurbujaCantidadAsc(producto arr[], int n);
    void ordenamientoBurbujaCantidadDesc(producto arr[], int n);

    int binarySearchId(producto arr[], int n, int target);
    int binarySearchNombre(producto arr[], int n, const std::string& target);
    int binarySearchPrecio(producto arr[], int n, double target);
    int binarySearchCantidad(producto arr[], int n, int target);
};

#endif // LISTA_PRODUCTOS_H