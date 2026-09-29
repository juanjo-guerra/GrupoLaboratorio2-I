#include <iostream>

struct Producto {
  int codigo;
  std::string nombre;
  double precio;
  Producto  *anterior;
  Producto *siguiente;
};

//Puntero global
struct Producto *puntero_global = nullptr;

//Declaracion de funciones
void ImprimirInventario();

int main() {
    return 0;
}

void ImprimirInventario(){
    
    if (puntero_global == nullptr){
        std:: cout << "\nEl inventario esta vacio.\n";
        return;
    }

     std::cout << "\n--- Inventario ---\n";
    Producto* actual = puntero_global;

    while (actual != nullptr) {
        std::cout << "Codigo: " << actual->codigo 
                << " | Nombre: " << actual->nombre 
                << " | Precio: $" << actual->precio << "\n";
        actual = actual->siguiente;
    }
}
