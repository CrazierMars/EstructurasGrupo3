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
<<<<<<< Updated upstream
=======
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

    //Ordenamiento por mezcla
    void OrdenamientoMezclaIdAsc(producto arr[], int n);
    void OrdenamientoMezclaIdDesc(producto arr[], int n);
    void OrdenamientoMezclaNombreAsc(producto arr[], int n);
    void OrdenamientoMezclaNombreDesc(producto arr[], int n);
    void OrdenamientoMezclaPrecioAsc(producto arr[], int n);
    void OrdenamientoMezclaPrecioDesc(producto arr[], int n);
    void OrdenamientoMezclaCantidadAsc(producto arr[], int n);
    void OrdenamientoMezclaCantidadDesc(producto arr[], int n);
>>>>>>> Stashed changes
};

#endif // LISTA_PRODUCTOS_H