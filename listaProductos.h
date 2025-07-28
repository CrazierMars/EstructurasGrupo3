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


<<<<<<< Updated upstream
=======
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

    void OrdenamientoMezclaIdAsc(producto arr[], int n);
    void OrdenamientoMezclaIdDesc(producto arr[], int n);
    void OrdenamientoMezclaNombreAsc(producto arr[], int n);
    void OrdenamientoMezclaNombreDesc(producto arr[], int n);
    void OrdenamientoMezclaPrecioAsc(producto arr[], int n);
    void OrdenamientoMezclaPrecioDesc(producto arr[], int n);
    void OrdenamientoMezclaCantidadAsc(producto arr[], int n);
    void OrdenamientoMezclaCantidadDesc(producto arr[], int n);

    void ordenamientoInsercionIdAsc(producto arr[], int n);
    void ordenamientoInsercionIdDesc(producto arr[], int n);
    void ordenamientoInsercionNombreAsc(producto arr[], int n);
    void ordenamientoInsercionNombreDesc(producto arr[], int n);
    void ordenamientoInsercionPrecioAsc(producto arr[], int n);
    void ordenamientoInsercionPrecioDesc(producto arr[], int n);
    void ordenamientoInsercionCantidadAsc(producto arr[], int n);
    void ordenamientoInsercionCantidadDesc(producto arr[], int n);


    void OrdenamientoBurbujaIdAsc(producto arr[], int n);
    void OrdenamientoBurbujaIdDesc(producto arr[], int n);
    void OrdenamientoBurbujaNombreAsc(producto arr[], int n);
    void OrdenamientoBurbujaNombreDesc(producto arr[], int n);
    void OrdenamientoBurbujaPrecioAsc(producto arr[], int n);
    void OrdenamientoBurbujaPrecioDesc(producto arr[], int n);
    void OrdenamientoBurbujaCantidadAsc(producto arr[], int n);
    void OrdenamientoBurbujaCantidadDesc(producto arr[], int n);

>>>>>>> Stashed changes
};

#endif // !LISTA_PRODUCTOS_H