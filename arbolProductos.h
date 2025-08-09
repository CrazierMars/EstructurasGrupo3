#ifndef ARBOL_PRODUCTOS_H
#define ARBOL_PRODUCTOS_H

#include <string>
#include "producto.h"

class arbolProductos {
private:
    producto* raiz;

public:
    arbolProductos() : raiz(nullptr) {}
    ~arbolProductos(); // libera todo el árbol

    // Acceso a la raíz
    producto* getRaiz() const { return raiz; }
    void setRaiz(producto* nuevaRaiz) { raiz = nuevaRaiz; }

    // Operaciones básicas
    void insertarNodo(int id,std::string nombre, double precio, int cantidad);
    producto* buscarNodo (int llaveBuscar) const;
    producto* buscarPadre(int llaveBuscar) const;

    // Recorridos
    void enOrden (producto* r) const;
    void preOrden(producto* r) const;
    void postOrden(producto* r) const;

    // Utilidades de eliminación
    producto* getSucesor(producto* nodo) const; // sucesor in-order (mínimo del subárbol derecho)
    void eliminar(int llaveEliminar);
};

#endif // ARBOL_PRODUCTOS_H
