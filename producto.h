#include <string>
class producto {
    private: 
        int id;
        std::string nombre;
        double precio;
        int cantidad;
        producto* siguiente;
    public: 
        // Constructor
        producto(int pId, const std::string& pNombre, double pPrecio, int pCantidad){
            id = pId;
            nombre = pNombre; 
            precio = pPrecio;
            cantidad = pCantidad;
            siguiente = nullptr;
        }
        // Getters 
        int getId();
        std::string getNombre(); 
        double getPrecio();
        int getCantidad();
        producto* getSiguiente();

        // Setters 
        void setId(int pId);
        void setNombre(const std::string& pNombre);
        void setPrecio(double pPrecio);
        void setCantidad(int pCantidad);
        void setSiguiente(producto* nuevoSiguiente);
};