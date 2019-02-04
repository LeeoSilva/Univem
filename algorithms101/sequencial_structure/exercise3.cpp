#include <iostream>

// Elabore um algoritmo que leia um número inteiro (max. 3 algarismos) e mostre
// os algarismos em separado. Ex NUM == 725 o algoritmo produzirá: Centena = 7
// Dezena = 2 e Unidade = 5.


int main(void){
  int value = 0;

  std::cout << "Solicite numero inteiro de no máximo 3 algarismos: ";
  std::cin >> value;

  if( value > 999 || value <= 0 ) return 1;

  std::cout << "Centenas: " << ((value / 100) % 100) << std::endl;
  std::cout << "Dezenas: " << ((value / 10) % 10) << std::endl;
  std::cout << "Unidades: " << (value % 10) << std::endl;
  return 0;
}
