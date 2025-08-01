#include "listaProductos.h"
#include <iostream>
#include <functional>

using namespace std;

auto toLower = [](const std::string& s) {
    std::string res = s;
    for (char& c : res) c = tolower(static_cast<unsigned char>(c));
    return res;
};

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
}
producto* listaProductos::buscarNombre(string nombre) {
    if (estaVacia()) {
        return nullptr;
    }
    producto* actual = primero;
    while (actual != nullptr) {
        if (toLower(actual->getNombre()) == toLower(nombre)) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
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
        cout << "La lista esta vacia." << endl;
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
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getId() > temp.getId()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionIdDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getId() < temp.getId()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionNombreAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getNombre() > temp.getNombre()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionNombreDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getNombre() < temp.getNombre()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionPrecioAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getPrecio() > temp.getPrecio()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionPrecioDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getPrecio() < temp.getPrecio()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionCantidadAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getCantidad() > temp.getCantidad()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoInsercionCantidadDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 1; i < n; i++) {
        producto temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].getCantidad() < temp.getCantidad()) {
            arr[j + 1] = arr[j];
            comparaciones++;
            j--;
        }
        arr[j + 1] = temp;
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

// Ordenamiento por selección

// Función auxiliar para intercambiar dos productos
void listaProductos::auxIntercambiar(producto& a, producto& b) {
    producto temp = a;
    a = b;
    b = temp;
}

// ID
void listaProductos::ordenamientoSeleccionIdAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getId() < arr[min].getId()) {
                min = j;
            }
        }
        auxIntercambiar(arr[i], arr[min]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}
void listaProductos::ordenamientoSeleccionIdDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getId() > arr[max].getId()) {
                max = j;
            }
        }
        auxIntercambiar(arr[i], arr[max]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

// Nombre
void listaProductos::ordenamientoSeleccionNombreAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getNombre() < arr[min].getNombre()) {
                min = j;
            }
        }
        auxIntercambiar(arr[i], arr[min]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}
void listaProductos::ordenamientoSeleccionNombreDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getNombre() > arr[max].getNombre()) {
                max = j;
            }
        }
        auxIntercambiar(arr[i], arr[max]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

// Precio
void listaProductos::ordenamientoSeleccionPrecioAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getPrecio() < arr[min].getPrecio()) {
                min = j;
            }
        }
        auxIntercambiar(arr[i], arr[min]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}
void listaProductos::ordenamientoSeleccionPrecioDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getPrecio() > arr[max].getPrecio()) {
                max = j;
            }
        }
        auxIntercambiar(arr[i], arr[max]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

// Cantidad
void listaProductos::ordenamientoSeleccionCantidadAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getCantidad() < arr[min].getCantidad()) {
                min = j;
            }
        }
        auxIntercambiar(arr[i], arr[min]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}
void listaProductos::ordenamientoSeleccionCantidadDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            comparaciones++;
            if (arr[j].getCantidad() > arr[max].getCantidad()) {
                max = j;
            }
        }
        auxIntercambiar(arr[i], arr[max]);
    }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}


//Metodos por mezcla
void merge(producto arr[], int izquierda, int mitad, int derecha, function<bool(producto&, producto&)> comp, int& comparaciones) {
    int n1 = mitad - izquierda + 1;
    int n2 = derecha - mitad;

    producto* L = new producto[n1];
    producto* R = new producto[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izquierda + i], comparaciones++;
    for (int j = 0; j < n2; j++) R[j] = arr[mitad + 1 + j], comparaciones++;

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        comparaciones++;
        if (comp(L[i], R[j])) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++], comparaciones++;
    while (j < n2) arr[k++] = R[j++], comparaciones++;

    delete[] L;
    delete[] R;
}

void mergeSort(producto arr[], int izquierda, int derecha, function<bool(producto&, producto&)> comp, int& comparaciones) {
    if (izquierda < derecha) {
        int mitad = izquierda + (derecha - izquierda) / 2;
        mergeSort(arr, izquierda, mitad, comp, comparaciones);
        mergeSort(arr, mitad + 1, derecha, comp, comparaciones);
        merge(arr, izquierda, mitad, derecha, comp, comparaciones);
    }
}

#define GEN_ORDEN_MEZCLA(nombre, criterio, operador) \
void listaProductos::nombre(producto arr[], int n) { \
    int comparaciones = 0; \
    mergeSort(arr, 0, n - 1, [](producto& a, producto& b) { \
        return a.criterio() operador b.criterio(); \
    }, comparaciones); \
    cout << "\nComparaciones realizadas: " << comparaciones << endl; \
}


GEN_ORDEN_MEZCLA(ordenamientoMezclaIdAsc, getId, <)
GEN_ORDEN_MEZCLA(ordenamientoMezclaIdDesc, getId, >)
GEN_ORDEN_MEZCLA(ordenamientoMezclaNombreAsc, getNombre, <)
GEN_ORDEN_MEZCLA(ordenamientoMezclaNombreDesc, getNombre, >)
GEN_ORDEN_MEZCLA(ordenamientoMezclaPrecioAsc, getPrecio, <)
GEN_ORDEN_MEZCLA(ordenamientoMezclaPrecioDesc, getPrecio, >)
GEN_ORDEN_MEZCLA(ordenamientoMezclaCantidadAsc, getCantidad, <)
GEN_ORDEN_MEZCLA(ordenamientoMezclaCantidadDesc, getCantidad, >)

// Ordenamiento burbuja
void listaProductos::ordenamientoBurbujaIdAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getId() > arr[j + 1].getId()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaIdDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getId() < arr[j + 1].getId()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaNombreAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getNombre() > arr[j + 1].getNombre()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaNombreDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getNombre() < arr[j + 1].getNombre()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaPrecioAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getPrecio() > arr[j + 1].getPrecio()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaPrecioDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getPrecio() < arr[j + 1].getPrecio()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaCantidadAsc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getCantidad() > arr[j + 1].getCantidad()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;
}

void listaProductos::ordenamientoBurbujaCantidadDesc(producto arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j].getCantidad() < arr[j + 1].getCantidad()) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    cout << "\nComparaciones realizadas: " << comparaciones << endl;

}

// Búsqueda binaria

producto* listaProductos::busquedaBinariaPorId(producto arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int id = arr[mid].getId();

        if (id == target) return &arr[mid];
        if (id < target) low = mid + 1;
        else high = mid - 1;
    }
    return nullptr;
}

producto* listaProductos::busquedaBinariaPorNombre(producto arr[], int n, std::string& target) {
    int low = 0, high = n - 1;
    target = toLower(target);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        std::string nombre = arr[mid].getNombre();

        if (toLower(nombre) == target) return &arr[mid];
        if (toLower(nombre) < target) low = mid + 1;
        else high = mid - 1;
    }
    return nullptr;
}

producto* listaProductos::busquedaBinariaPorPrecio(producto arr[], int n, double target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        double precio = arr[mid].getPrecio();

        if (precio == target) return &arr[mid];
        if (precio < target) low = mid + 1;
        else high = mid - 1;
    }
    return nullptr;
}

producto* listaProductos::busquedaBinariaPorCantidad(producto arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cantidad = arr[mid].getCantidad();

        if (cantidad == target) return &arr[mid];
        if (cantidad < target) low = mid + 1;
        else high = mid - 1;
    }
    return nullptr;
}
