#ifndef ARBOL_PRODUCTOS_H
#define ARBOL_PRODUCTOS_H

#include <string>
#include <functional>
#include "producto.h"

class arbolProductos {
private:
    producto* raiz;

public:
    arbolProductos() : raiz(nullptr) {}
    ~arbolProductos();

    producto* getRaiz();
    void setRaiz(producto* nuevaRaiz);

    void insertarNodo(std::string nombre, double precio, int cantidad, int padreId = 0);
    producto* buscarNodo(int id);
    producto* buscarPadre(int id);

    void enOrden(producto* r, std::function<void(producto*)> visitar);
    void preOrden(producto* r);
    void postOrden(producto* r);

    producto* getSucesor(producto* nodo);
    bool eliminar(int id);

    void imprimir();
};

#endif // ARBOL_PRODUCTOS_H
