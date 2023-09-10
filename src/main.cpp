#include <iostream>
#include <MASCOTA.hpp>
int main(int argc, char const *argv[])
{
  std::cout << "Juego de mascotas" << std::endl;
  Mascota m1("Firulais");
  m1.jugar();
  m1.jugar();
  m1.jugar();
  std::cout
      << m1.DecirNombre() << "tiene"
      << m1.DecirNombre() << "de hambre";

  m1.comer(5);

  return 0;
}
