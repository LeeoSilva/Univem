#include <iostream>

// Escreva um algoritmo que leia um tempo em segudos e calcule o total de horas
// minutos e segundos equivalentes a este tempo dado de entrada.

// Por exemplo: 7850 segundos é igual a: 2 horas, 10 minutos e 50 segundos.


int main(void){
  int totalSeconds = 0;
  int hours = 0;
  int min = 0;
  int sec = 0;

  std::cout << "Solicite o tempo em segundos a ser convertido: ";
  std::cin >> totalSeconds;
  if( totalSeconds <= 0 ) return 1;


  hours = totalSeconds / 3600;
  min = ((totalSeconds / 60) % 60); // minutos
  sec = totalSeconds % 60;


  std::cout << totalSeconds << " é igual a: " << hours << " horas, ";
  std::cout << min << " minutos e ";
  std::cout << sec << " segundos." << std::endl;
  return 0;
}
