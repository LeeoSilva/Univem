#include <iostream>

// Elabore um algoritmo que leia um valor em reais (R$) e mostre sua conversão
// para dolares ($). Para isto o algoritmo deverá solicitar ao usuário a cotação do
// dolar. Mostre o resultado.

int main(void){
  float value = 0;
  float cotation = 0;

  std::cout.precision(2);
  std::cout << std::fixed;
  std::cout << "Solicite o valor em reais (R$) para a conversão: ";
  std::cin >> value;
  std::cout << "Solicite o valor da contação do dolar atual: ";
  std::cin >> cotation;

  std::cout << "R$ " << value << " -> $ " << (value * cotation) << std::endl;
  return 0;
}
