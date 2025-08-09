#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class producto {
private:
    int id;
    std::string nombre;
    double precio;
    int cantidad;
    producto* siguiente;

public:
    // Constructor por defecto
    producto() {
        id = 0;
        nombre = "";
        precio = 0.0;
        cantidad = 0;
        siguiente = nullptr;
    }
    // Constructor parametrizado
    producto(int pId, const std::string& pNombre, double pPrecio, int pCantidad){
        id = pId;
        nombre = pNombre;
        precio = pPrecio;
        cantidad = pCantidad;
        siguiente = nullptr;
    }

    int getId();
    std::string getNombre();
    double getPrecio();
    int getCantidad();
    producto* getSiguiente();

    void setId(int pId);
    void setNombre(const std::string& pNombre);
    void setPrecio(double pPrecio);
    void setCantidad(int pCantidad);
    void setSiguiente(producto* nuevoSiguiente);

    void imprimir();
};

#endif
