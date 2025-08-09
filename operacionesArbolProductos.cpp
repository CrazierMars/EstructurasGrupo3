#include "arbolProductos.h"
#include <iostream>

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

// ---------- Insertar en BST (sin duplicados) ----------
void arbolProductos::insertarNodo(int id, std::string nombre, double precio, int cantidad) {
    producto* nuevo = new producto(id, nombre, precio, cantidad);

    if (!raiz) { raiz = nuevo; return; }

    producto* actual = raiz;
    producto* padre  = nullptr;

    while (actual) {
        padre = actual;
        if (id == actual->getId()) {
            // Duplicado: opcionalmente podrías actualizar valor en vez de ignorar
            delete nuevo;
            return;
        } else if (id < actual->getId()) {
            actual = actual->getHijoIzquierdo();
        } else {
            actual = actual->getHijoDerecho();
        }
    }

    if (id < padre->getId()) padre->setHijoIzquierdo(nuevo);
    else                            padre->setHijoDerecho(nuevo);
}

// ---------- Búsqueda segura ----------
producto* arbolProductos::buscarNodo(int llaveBuscar) const {
    producto* nodoTemp = raiz;
    while (nodoTemp && nodoTemp->getId() != llaveBuscar) {
        if (llaveBuscar < nodoTemp->getId())
            nodoTemp = nodoTemp->getHijoIzquierdo();
        else
            nodoTemp = nodoTemp->getHijoDerecho();
    }
    return nodoTemp; // nullptr si no existe
}

producto* arbolProductos::buscarPadre(int llaveBuscar) const {
    producto* nodoActual = raiz;
    producto* nodoPadre  = nullptr;

    while (nodoActual && nodoActual->getId() != llaveBuscar) {
        nodoPadre = nodoActual;
        if (llaveBuscar < nodoActual->getId())
            nodoActual = nodoActual->getHijoIzquierdo();
        else
            nodoActual = nodoActual->getHijoDerecho();
    }
    return (nodoActual == nullptr) ? nullptr : nodoPadre; // nullptr si no existe o si es la raíz
}

// ---------- Recorridos (sin '\\n' extra por llamada) ----------
void arbolProductos::enOrden(producto* r) const {
    if (!r) return;
    enOrden(r->getHijoIzquierdo());
    r->imprimir();
    enOrden(r->getHijoDerecho());
}

void arbolProductos::preOrden(producto* r) const {
    if (!r) return;
    r->imprimir();
    preOrden(r->getHijoIzquierdo());
    preOrden(r->getHijoDerecho());
}

void arbolProductos::postOrden(producto* r) const {
    if (!r) return;
    postOrden(r->getHijoIzquierdo());
    postOrden(r->getHijoDerecho());
    r->imprimir();
}

// ---------- Sucesor in-order (mínimo del subárbol derecho) ----------
// Si el sucesor NO es el hijo derecho directo, se hace:
//   padreSucesor->left = sucesor->right
//   sucesor->right     = nodo->right
// Devolvemos 'sucesor' ya listo para colocarlo en lugar de 'nodo'.
producto* arbolProductos::getSucesor(producto* nodo) const {
    producto* padreSucesor = nodo;
    producto* sucesor      = nodo->getHijoDerecho();

    // Bajar a la izquierda hasta el mínimo del subárbol derecho
    while (sucesor && sucesor->getHijoIzquierdo()) {
        padreSucesor = sucesor;
        sucesor      = sucesor->getHijoIzquierdo();
    }

    // Si el sucesor NO era el hijo derecho directo, reacomodamos
    if (sucesor && sucesor != nodo->getHijoDerecho()) {
        // mover el posible hijo derecho del sucesor hacia arriba
        padreSucesor->setHijoIzquierdo(sucesor->getHijoDerecho());
        // y colgarle al sucesor el subárbol derecho original del nodo
        sucesor->setHijoDerecho(nodo->getHijoDerecho());
    }
    return sucesor;
}

// ---------- Eliminar por llave ----------
void arbolProductos::eliminar(int llaveEliminar) {
    if (!raiz) return;

    // 1) Buscar nodo y su padre
    producto* actual = raiz;
    producto* padre  = nullptr;

    while (actual && actual->getId() != llaveEliminar) {
        padre = actual;
        if (llaveEliminar < actual->getId())
            actual = actual->getHijoIzquierdo();
        else
            actual = actual->getHijoDerecho();
    }
    if (!actual) return; // no existe

    bool tieneIzq = (actual->getHijoIzquierdo() != nullptr);
    bool tieneDer = (actual->getHijoDerecho()  != nullptr);

    // Caso A: 0 hijos (hoja)
    if (!tieneIzq && !tieneDer) {
        if (!padre) {
            // borrar la raíz
            delete raiz;
            raiz = nullptr;
        } else {
            if (padre->getHijoIzquierdo() == actual) padre->setHijoIzquierdo(nullptr);
            else                                     padre->setHijoDerecho(nullptr);
            delete actual;
        }
        return;
    }

    // Caso B: 1 hijo
    if (tieneIzq ^ tieneDer) {
        producto* hijo = tieneIzq ? actual->getHijoIzquierdo()
                                   : actual->getHijoDerecho();
        if (!padre) {
            // reemplazar raíz
            delete raiz;
            raiz = hijo;
        } else {
            if (padre->getHijoIzquierdo() == actual) padre->setHijoIzquierdo(hijo);
            else                                     padre->setHijoDerecho(hijo);
            delete actual;
        }
        return;
    }

    // Caso C: 2 hijos
    // Tomamos el sucesor y lo colocamos en lugar de 'actual'
    producto* sucesor = getSucesor(actual); // ya viene con right bien colgado
    // Conectar sucesor con el padre de 'actual' (o convertirlo en raíz)
    if (!padre) {
        // sustituimos la raíz
        // Importante: NO borramos 'raiz' todavía porque necesitamos sus punteros izquierda/derecha
        producto* viejaRaiz = raiz;
        raiz = sucesor;
        // el sucesor nunca tiene hijo izquierdo; cuélgale el subárbol izquierdo de 'actual'
        sucesor->setHijoIzquierdo(viejaRaiz->getHijoIzquierdo());
        // 'sucesor' ya tiene el subárbol derecho correcto gracias a getSucesor()
        delete viejaRaiz;
    } else {
        if (padre->getHijoIzquierdo() == actual) padre->setHijoIzquierdo(sucesor);
        else                                     padre->setHijoDerecho(sucesor);
        // colgar al sucesor el subárbol izquierdo de 'actual'
        sucesor->setHijoIzquierdo(actual->getHijoIzquierdo());
        // el subárbol derecho del sucesor ya quedó correcto en getSucesor()
        delete actual;
    }
}
