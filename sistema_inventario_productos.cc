#include <iostream>

struct Producto {
  int codigo;
  std::string nombre;
  double precio;
  Producto  *anterior;
  Producto *siguiente;
};

int main() {
    return 0;
}