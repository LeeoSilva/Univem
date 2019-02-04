#include <iostream>

// Faça um algoritmo que leia dois valores inteiros e positivos e armazene nas
// variáveis. A e B respectivamente. Em seguida troque o conteúdo das variáveis,
// ou seja, A deverá receber o valor de B e B o valor de A.

int main(void){
  int a = 0;
  int b = 0;
  int temp = 0;

  std::cout << "Solicite o valor da variavel A: ";
  std::cin >> a;
  std::cout << "Solicite o valor da variavel B: ";
  std::cin >> b;

  temp = a;
  a = b;
  b = temp;

  std::cout << "A -> " << a << std::endl;
  std::cout << "B -> " << b << std::endl;
  return 0;
}
