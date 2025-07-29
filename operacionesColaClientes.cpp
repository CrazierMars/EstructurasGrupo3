
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

cliente* colaClientes::quitarPorPrioridad() {
    if (estaVacia()) {
        std::cout << "La cola está vacía." << std::endl;
        return nullptr;
    }

    cliente* actual = frente;
    cliente* anterior = nullptr;
    cliente* maxPrioridadCliente = frente;
    cliente* anteriorMax = nullptr;

    int maxPrioridad = frente->getPrioridad();

    while (actual != nullptr) {
        if (actual->getPrioridad() > maxPrioridad) {
            maxPrioridad = actual->getPrioridad();
            maxPrioridadCliente = actual;
            anteriorMax = anterior;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    }

    // Eliminar el nodo de la cola
    if (maxPrioridadCliente == frente) {
        frente = frente->getSiguiente();
        if (frente == nullptr) final = nullptr;
    } else {
        anteriorMax->setSiguiente(maxPrioridadCliente->getSiguiente());
        if (maxPrioridadCliente == final) final = anteriorMax;
    }

    maxPrioridadCliente->setSiguiente(nullptr);
    return maxPrioridadCliente;
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
