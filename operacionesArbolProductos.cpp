#include <iostream>
#include <windows.h>
#include <functional>
#include "arbolProductos.h"

int generarId() {
    return rand() % 90000 + 10000;
}

// ---------- Destructor: libera todos los nodos en postorden ----------
static void liberarPostorden(producto* n) {
    if (!n) return;
    liberarPostorden(n->getHijoIzquierdo());
    liberarPostorden(n->getHijoDerecho());
    delete n;
}

arbolProductos::~arbolProductos() {
    liberarPostorden(raiz);
    raiz = nullptr;
}

producto* arbolProductos::getRaiz() {
    return raiz;
}

void arbolProductos::setRaiz(producto* raiz) {
    this->raiz = raiz;
}

// ---------- Insertar en BST ----------
void arbolProductos::insertarNodo(std::string nombre, double precio, int cantidad, int padreId) {
    int id = 0;

    do {
        id = generarId();
        if (buscarNodo(id) != nullptr) {
            id = 0;
        }
    } while (id == 0);

    producto* nuevo = new producto(id, nombre, precio, cantidad, padreId);

    if (!raiz) { raiz = nuevo; return; }

    producto* actual = raiz;
    producto* padre  = nullptr;

    while (actual) {
        padre = actual;

        if (id == actual->getId()) {
            delete nuevo;
            return;
        } else if (id < actual->getId()) {
            actual = actual->getHijoIzquierdo();
        } else {
            actual = actual->getHijoDerecho();
        }
    }

    if (id < padre->getId()) {
        padre->setHijoIzquierdo(nuevo);
    } else {
        padre->setHijoDerecho(nuevo);
    }
}

// ---------- Búsqueda segura ----------
producto* arbolProductos::buscarNodo(int id) {
    producto* nodoTemp = raiz;
    
    while (nodoTemp && nodoTemp->getId() != id) {
        if (id < nodoTemp->getId()) {
            nodoTemp = nodoTemp->getHijoIzquierdo();
        } else {
            nodoTemp = nodoTemp->getHijoDerecho();
        }
    }

    return nodoTemp;
}

producto* arbolProductos::buscarPadre(int id) {
    producto* nodoActual = raiz;
    producto* nodoPadre  = nullptr;

    while (nodoActual && nodoActual->getId() != id) {
        nodoPadre = nodoActual;
        if (id < nodoActual->getId())
            nodoActual = nodoActual->getHijoIzquierdo();
        else
            nodoActual = nodoActual->getHijoDerecho();
    }

    return (nodoActual == nullptr) ? nullptr : nodoPadre;
}

// ---------- Recorridos ----------
void arbolProductos::enOrden(producto* r, std::function<void(producto*)> visitar) {
    if (!r) return;
    enOrden(r->getHijoIzquierdo(), visitar);
    visitar(r);
    enOrden(r->getHijoDerecho(), visitar);
}

void arbolProductos::preOrden(producto* r) {
    if (!r) return;
    r->imprimir();
    preOrden(r->getHijoIzquierdo());
    preOrden(r->getHijoDerecho());
}

void arbolProductos::postOrden(producto* r) {
    if (!r) return;
    postOrden(r->getHijoIzquierdo());
    postOrden(r->getHijoDerecho());
    r->imprimir();
}

// ---------- Sucesor in-order (mínimo del subárbol derecho) ----------
producto* arbolProductos::getSucesor(producto* nodo) {
    producto* padreSucesor = nodo;
    producto* sucesor = nodo->getHijoDerecho();

    while (sucesor && sucesor->getHijoIzquierdo()) {
        padreSucesor = sucesor;
        sucesor = sucesor->getHijoIzquierdo();
    }

    if (sucesor && sucesor != nodo->getHijoDerecho()) {
        padreSucesor->setHijoIzquierdo(sucesor->getHijoDerecho());
        sucesor->setHijoDerecho(nodo->getHijoDerecho());
    }

    return sucesor;
}

// ---------- Eliminar por llave ----------
bool arbolProductos::eliminar(int id) {
    if (!raiz) return false;

    producto* actual = raiz;
    producto* padre  = nullptr;

    while (actual && actual->getId() != id) {
        padre = actual;

        if (id < actual->getId()) {
            actual = actual->getHijoIzquierdo();
        } else {
            actual = actual->getHijoDerecho();
        }
    }

    if (!actual) return false;

    bool tieneIzq = (actual->getHijoIzquierdo() != nullptr);
    bool tieneDer = (actual->getHijoDerecho()  != nullptr);

    if (!tieneIzq && !tieneDer) {
        if (!padre) {
            delete raiz;
            raiz = nullptr;
        } else {
            if (padre->getHijoIzquierdo() == actual) {
                padre->setHijoIzquierdo(nullptr);
            } else {
                padre->setHijoDerecho(nullptr);
            }
            delete actual;
        }

        return true;
    }

    if (tieneIzq ^ tieneDer) {
        producto* hijo = tieneIzq ? actual->getHijoIzquierdo() : actual->getHijoDerecho();

        if (!padre) {
            delete raiz;
            raiz = hijo;
        } else {
            if (padre->getHijoIzquierdo() == actual) {
                padre->setHijoIzquierdo(hijo);
            } else {
                padre->setHijoDerecho(hijo);
            }
            delete actual;
        }

        return true;
    }

    producto* sucesor = getSucesor(actual);

    if (!padre) {
        producto* viejaRaiz = raiz;
        raiz = sucesor;
        sucesor->setHijoIzquierdo(viejaRaiz->getHijoIzquierdo());
        delete viejaRaiz;
    } else {
        if (padre->getHijoIzquierdo() == actual) {
            padre->setHijoIzquierdo(sucesor);
        } else {
            padre->setHijoDerecho(sucesor);
        }
        sucesor->setHijoIzquierdo(actual->getHijoIzquierdo());
        delete actual;
    }
    return
     true;
}

void arbolProductos::imprimir() {
    SetConsoleOutputCP(CP_UTF8);

    if (!raiz) {
        std::cout << "El árbol está vacío." << std::endl;
        return;
    }

    enOrden(raiz, [](producto* p) {
        p->imprimir();
    });
}
