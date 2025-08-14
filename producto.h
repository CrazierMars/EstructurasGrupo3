#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class producto {
private:
    int id;
    int padreId;
    std::string nombre;
    double precio;
    int cantidad;
    producto* hijoIzquierdo;
    producto* hijoDerecho;

public:
    producto() {
        id = 0;
        nombre = "";
        precio = 0.0;
        cantidad = 0;
        hijoIzquierdo = nullptr;
        hijoDerecho = nullptr;
    }

    producto(int id, const std::string& nombre, double precio, int cantidad, int padreId) {
        this->id = id;
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
        this->padreId = padreId;
        hijoIzquierdo = nullptr;
        hijoDerecho = nullptr;
    }

    int getId();
    int getPadreId();
    std::string getNombre();
    double getPrecio();
    int getCantidad();
    producto* getHijoIzquierdo();
    producto* getHijoDerecho();

    void setId(int id);
    void setPadreId(int padreId);
    void setNombre(const std::string& nombre);
    void setPrecio(double precio);
    void setCantidad(int cantidad);
    void setHijoIzquierdo(producto* hijoIzquierdo);
    void setHijoDerecho(producto* hijoDerecho);

    void imprimir();
};

#endif
