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
        ~listaProductos(){
            producto* actual = primero; 
            while (actual != nullptr) {
                producto* siguiente = actual->getSiguiente();
                delete actual; 
                actual = siguiente;
            }
        }

        // Metodos de la lista 

        producto* getPrimero();
        producto* getUltimo(); 
        // *****
        //****Revisar metodos buscar, si es optimo separar por parametro o buscar solo por id
        //***** */
        // Se implementa buscar por posible implementacion a futuro. 
        producto* buscarProductoId(int pId); 
        producto* buscarProductoNombre(const std::string& pNombre);
        producto* buscarProductoPrecio(double pPrecio);
        // Metodos de insercion 
        void agregarProductoInicio(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad);
        void agregarProductoFinal(int pNuevoId, const std::string& pNuevoNombre, double pNuevoPrecio, int pNuevaCantidad);
        void imprimirLista();
        int contarProductos();
        // ****
        // Revisar si es optimo borrar por id o modularlo como los metodos buscar de aca arriba
        void eliminarProducto(int pIdEliminar);


};

#endif // !LISTA_PRODUCTOS_H