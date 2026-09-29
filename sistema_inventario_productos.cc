//UTILIZAMOS GITFLOW POR COMANDOOOOOS <3

#include <iostream>
#include <string>

struct Producto {
  int codigo;
  std::string nombre;
  double precio;
  Producto *anterior;
  Producto *siguiente;
};

//Puntero global
struct Producto *puntero_global = nullptr;

//Declaracion de funciones
void ImprimirInventario();
void InsertarInicio(int codigo, const std::string& nombre, double precio);
void BorrarInicio();

int main() {
  int opcion_menu = 0;

  while (opcion_menu != 4) {
    std::cout << "\n1. Insertar al inicio\n"
              << "2. Borrar al inicio\n"
              << "3. Imprimir (Obligatoria)\n"
              << "4. Salir\n"
              << "Opcion: ";
    std::cin >> opcion_menu;

    if (opcion_menu == 1) {
      int codigo_ingresado;
      std::string nombre_ingresado;
      double precio_ingresado;
      
      std::cout << "Codigo: ";
      std::cin >> codigo_ingresado;
      std::cout << "Nombre: ";
      std::cin.ignore(); 
      std::getline(std::cin, nombre_ingresado);
      std::cout << "Precio: ";
      std::cin >> precio_ingresado;
      
      InsertarInicio(codigo_ingresado, nombre_ingresado, precio_ingresado);
    } 
    else if (opcion_menu == 2) {
      BorrarInicio();
    } 
    else if (opcion_menu == 3) {
      ImprimirInventario();
    }
  }
  
  while (puntero_global != nullptr) {
    BorrarInicio();
  }
  
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