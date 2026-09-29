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
void InsertarInicio(int codigo, const std::string& nombre, double precio);
void BorrarInicio();

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

void InsertarInicio(int codigo, const std::string& nombre, double precio) {
  // Pedimos memoria con 'new' y creamos el nuevo producto
  Producto* nuevo_producto = new Producto{codigo, nombre, precio, nullptr, nullptr};

  // Si la lista ya tiene productos, enlazamos el nuevo con el actual inicio
  if (puntero_global != nullptr) {
    nuevo_producto->siguiente = puntero_global;
    puntero_global->anterior = nuevo_producto;
  }
  
  // Hacemos que el puntero global apunte al nuevo producto que acaba de entrar
  puntero_global = nuevo_producto;
  
  std::cout << "Producto agregado con exito.\n";
}

void BorrarInicio() {
  // Si la lista está vacía, no hay nada que borrar
  if (puntero_global == nullptr) {
    std::cout << "No hay productos para borrar.\n";
    return;
  }

  // Guardamos el primer producto en una variable temporal
  Producto* temporal = puntero_global;
  
  // Movemos el puntero global al segundo producto
  puntero_global = puntero_global->siguiente;
  
  // Si la lista no quedó vacía, cortamos el enlace hacia atrás
  if (puntero_global != nullptr) {
    puntero_global->anterior = nullptr;
  }
  
  // Liberamos la memoria del producto borrado usando 'delete'
  delete temporal; 
  std::cout << "Primer producto borrado y memoria liberada.\n";
}