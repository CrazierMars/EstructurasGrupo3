#include "listaProductos.h"
#include <iostream>

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
    //Ordenamiento por Insercion
    void listaProductos::OrdenamientoInsercionIdAsc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionIdDesc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionNombreAsc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionNombreDesc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionPrecioAsc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionPrecioDesc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionCantidadAsc(producto arr[], int n) {
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

void listaProductos::OrdenamientoInsercionCantidadDesc(producto arr[], int n) {
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
