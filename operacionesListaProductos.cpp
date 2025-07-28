#include "listaProductos.h"
#include <iostream>
#include <functional>

using namespace std;

listaProductos::~listaProductos() {
    producto* actual = primero;
    while (actual != nullptr) {
        producto* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;
}

producto* listaProductos::getPrimero() {
    return primero;
}
producto* listaProductos::getUltimo() {
    producto* actual = primero; 
    if (imprimirVacia()) {
        return nullptr;
    }
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    return actual;
}

producto* listaProductos::buscarId(int id) {
    if (estaVacia()) {
        return nullptr;
    }
    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getId() == id) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con ID " << id << " no encontrado." << endl;
}
producto* listaProductos::buscarNombre(string nombre) {
    if (estaVacia()) {
        return nullptr;
    }
    producto* actual = primero;
    while (actual != nullptr) {
        if (actual->getNombre() == nombre) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
    cout << "Producto con nombre " << nombre << "no encontrado." << endl;
}
producto* listaProductos::buscarPrecio(double precio) {
    if (estaVacia()) {
        return nullptr;
    }
    producto* actual = primero; 
    while (actual != nullptr) {
        if (actual->getPrecio() == precio) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
    cout << "Producto con precio " << precio << "no encontrado." << endl;
}
producto* listaProductos::buscarCantidad(int cantidad) {
    if (estaVacia()) {
        return nullptr;
    }
    producto* actual = primero; 
    while (actual != nullptr) {
        if (actual->getCantidad() == cantidad) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr; 
    cout << "Producto con cantidad " << cantidad << " no encontrado." << endl;
}

void listaProductos::insertarInicio(string nombre, double precio, int cantidad) {
    int id = generarId();
    while (buscarId(id) != nullptr) {
        id = generarId();
    }
    producto* nuevoProducto = new producto(id, nombre, precio, cantidad);
    nuevoProducto->setSiguiente(primero);
    primero = nuevoProducto;
}
void listaProductos::insertarFinal(string nombre, double precio, int cantidad) {
    int id = generarId();
    while (buscarId(id) != nullptr) {
        id = generarId();
    }
    producto* nuevoProducto = new producto(id, nombre, precio, cantidad);
    if (primero == nullptr) {
        primero = nuevoProducto;
    } else {
        producto* ultimo = this->getUltimo();
        ultimo->setSiguiente(nuevoProducto);
    }
}

producto *listaProductos::eliminar(string value, string target) {
    if (imprimirVacia()) {
        return nullptr;
    }

    producto* anterior = nullptr;
    producto* actual = primero;
    
    if (target == "nombre") {
        while (actual != nullptr && actual->getNombre() != value) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }

    if (target == "id") {
        int idEliminar = stoi(value);
        while (actual != nullptr && actual->getId() != idEliminar) {
            anterior = actual;
            actual = actual->getSiguiente();
        }
    }
    
    if (actual == nullptr) {
        cout << "El producto no existe." << endl;
        return nullptr;
    }

    if (actual == primero) {
        primero = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual;
    return actual;
}

void listaProductos::imprimirLista() {
    if (!imprimirVacia()) {
        producto* actual = primero; 
        
        while(actual != nullptr) {
            cout << "ID: " << actual->getId() << ", Nombre: " << actual->getNombre()
                 << ", Precio: " << actual->getPrecio() << ", Cantidad: " << actual->getCantidad() << endl;
            actual = actual->getSiguiente();
        }
    }
}

int listaProductos::contarProductos() {
    if (imprimirVacia()) {
        return 0;
    }

    int contador = 0;
    producto* actual = primero; 
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }
    return contador;
}

bool listaProductos::estaVacia() {
    return primero == nullptr;
}

bool listaProductos::imprimirVacia() {
    if (estaVacia()) {
        cout << "La lista esta vacía." << endl;
        return true;
    }

    return false;
}

int listaProductos::generarId() {
    return rand() % 90000 + 10000;
}

// Métodos de ordenamiento
// Ordenamiento por Insercion
void listaProductos::ordenamientoInsercionIdAsc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getId() > temp.getId()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionIdDesc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getId() < temp.getId()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionNombreAsc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getNombre() > temp.getNombre()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionNombreDesc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getNombre() < temp.getNombre()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionPrecioAsc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getPrecio() > temp.getPrecio()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionPrecioDesc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getPrecio() < temp.getPrecio()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionCantidadAsc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getCantidad() > temp.getCantidad()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void listaProductos::ordenamientoInsercionCantidadDesc(producto arr[], int n) {
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getCantidad() < temp.getCantidad()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//Metodos por mezcla
void merge(producto arr[], int izquierda, int mitad, int derecha, function<bool(producto&, producto&)> comp) {
    int n1 = mitad - izquierda + 1;
    int n2 = derecha - mitad;

    producto* L = new producto[n1];
    producto* R = new producto[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izquierda + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mitad + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(producto arr[], int izquierda, int derecha, function<bool(producto&, producto&)> comp) {
    if (izquierda < derecha) {
        int mitad = izquierda + (derecha - izquierda) / 2;
        mergeSort(arr, izquierda, mitad, comp);
        mergeSort(arr, mitad + 1, derecha, comp);
        merge(arr, izquierda, mitad, derecha, comp);
    }
}

#define GEN_ORDEN_MEZCLA(nombre, criterio, operador) \
void listaProductos::nombre(producto arr[], int n) { \
    mergeSort(arr, 0, n - 1, [](producto& a, producto& b) { \
        return a.criterio() operador b.criterio(); \
    }); \
}

GEN_ORDEN_MEZCLA(OrdenamientoMezclaIdAsc, getId, <)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaIdDesc, getId, >)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaNombreAsc, getNombre, <)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaNombreDesc, getNombre, >)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaPrecioAsc, getPrecio, <)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaPrecioDesc, getPrecio, >)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaCantidadAsc, getCantidad, <)
GEN_ORDEN_MEZCLA(OrdenamientoMezclaCantidadDesc, getCantidad, >)

