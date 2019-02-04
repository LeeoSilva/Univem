#include <iostream>

// Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas.
// Faça um programa que receba o salário fixo de um funcionário e o valor de suas
// vendas. Calcule e mostre a comissão e o salário final do funcionário.

int main(void){
  float salary = 0;
  float sales = 0;
  float commission = 0;

  std::cout << "Solicite o salário do funcionario: ";
  std::cin >> salary;

  if( salary <= 0 ) return 1;

  std::cout << "Solicite o valor de suas vendas para o cálculo de sua commisão: ";
  std::cin >> commission;

  if( commission <= 0 ) return 1;

  commission *= 0.04;

  std::cout << "Commisão do funcionário: " << (commission) << std::endl;
  std::cout << "Salário final do funcionário: " << (salary + commission) << std::endl;
  return 0;
}
