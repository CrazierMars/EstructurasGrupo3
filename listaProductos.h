#ifndef LISTA_PRODUCTOS_H
#define LISTA_PRODUCTOS_H

#include "producto.h"

class listaProductos {
    //atributos
private:
    producto* primero;
    // metodos
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
    //****Revisar metodos buscar, si es optimo separar por parametro o buscar solo por id

    // Métodos de búsqueda
    producto* buscarId(int pId);
    producto* buscarNombre(const std::string& pNombre);
    producto* buscarPrecio(double pPrecio);

    // Metodos de inserción
    void insertarInicio(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad);
    void insertarFinal(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad);
    void imprimirLista();
    int contarProductos();

    // Métodos de eliminación
    // producto* eliminarPorId(int pIdEliminar);
    producto* eliminarPorNombre(std::string& pNombreEliminar);
};

#endif // LISTA_PRODUCTOS_H