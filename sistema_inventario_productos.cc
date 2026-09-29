#include <iostream>
#include <string>

struct Producto {
  int codigo;
  std::string nombre;
  double precio;
  Producto  *anterior;
  Producto *siguiente;
};

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
      
      InsertarAlInicio(codigo_ingresado, nombre_ingresado, precio_ingresado);
    } 
    else if (opcion_menu == 2) {
      BorrarAlInicio();
    } 
    else if (opcion_menu == 3) {
      ImprimirInventario();
    }
  }

  
  while (puntero_global != nullptr) {
    BorrarAlInicio();
  }
  
  return 0;
}