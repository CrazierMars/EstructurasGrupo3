
#include "colaClientes.h"
#include <iostream>

colaClientes::colaClientes() {
    frente = final = nullptr;
}

colaClientes::~colaClientes() {
    while (frente != nullptr) {
        cliente* temp = frente;
        frente = frente->getSiguiente();
        delete temp;
    }
    
    final = nullptr;
}

void colaClientes::insertar(cliente* cliente) {
    if (estaVacia()) {
        frente = cliente;
        final = cliente;
    } else {
        final->setSiguiente(cliente);
        final = cliente;
    }

    cliente->setSiguiente(nullptr);
}

cliente* colaClientes::quitar() {
    if (estaVacia()) {
        std::cout << "La cola está vacía." << std::endl;
        return nullptr;
    }

    cliente* temp = frente;
    frente = frente->getSiguiente();

    if (frente == nullptr) {
        final = nullptr;
    }

    temp->setSiguiente(nullptr);

    return temp;
}

cliente* colaClientes::verFrente() {
    return frente;
}

bool colaClientes::estaVacia() {
    return frente == nullptr;
}

void colaClientes::imprimirCola() {
    cliente* actual = frente;

    while (actual != nullptr) {
        actual->imprimir();
        std::cout << "----------------------" << std::endl;
        actual = actual->getSiguiente();
    }
}
