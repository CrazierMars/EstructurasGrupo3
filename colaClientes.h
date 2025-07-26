#include "cliente.h"

#ifndef COLA_CLIENTES_H
#define COLA_CLIENTES_H

class colaClientes {
private:
    cliente* frente;
    cliente* final;

public:
    colaClientes();
    ~colaClientes();
    void insertar(cliente* cliente);
    cliente* quitar();
    cliente* verFrente();
    bool estaVacia();
    void imprimirCola();
};

#endif
