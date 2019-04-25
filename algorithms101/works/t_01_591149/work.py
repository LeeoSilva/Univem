#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Você deverá implementar um algoritmo em Python que receba 
# como dado de entrada um valor inteiro e, mostrar passo a 
# passo as operações acima descritas, ao final, mostre quantas 
# iterações foram necessárias para a conversão do referido valor. 
# Fiquem atentos que para valores de 3 algarismos, a conversão será 
# para 495 e valores de 4 algarismos, a conversão será para 6174.
# Quaisquer outros valores, deverão ser ignorados e mostre a 
# mensagem “Valor não permitido”


def four_alg(number, iterations = 0):
    # Converging the value to 6174 recursevely
    vec = [0] * 4
    vec[0] = int( (number // 1000) ); 
    vec[1] = int( (number %  1000) // 100 );  
    vec[2] = int( (number %  100)  // 10 );
    vec[3] = int( (number %  10) );

    bigger       = int(0)
    smaller      = int(0) 
    result       = int(0)
    MAGIC_NUMBER = int(6174)

    vec.sort();
    for i in range(4): bigger += vec[i] * (10**i) # Generates the biggest number possible
    vec.sort(reverse=True)
    for i in range(4): smaller += vec[i] * (10**i) # Generates the smaller number possible

    result = bigger - smaller
    print("Maior_valor - Menor_Valor -> {} - {} = {}".format(bigger, smaller, result))

    if result == MAGIC_NUMBER: print("{} iterações".format(iterations+1)); exit()
    four_alg(result, (iterations+1))
    
def three_alg(number, iterations = 0):
    # Convergin the value to 495 recursevely.
    vec = [0] * 3
    vec[0] = int( (number // 100) );
    vec[1] = int( (number % 100) // 10 );
    vec[2] = int( (number % 10) );
    
    bigger       = int(0)
    smaller      = int(0) 
    result       = int(0)
    MAGIC_NUMBER = int(495)

    vec.sort();
    for i in range(3): bigger += vec[i] * (10**i) # Generates the biggest number possible
    vec.sort(reverse=True)
    for i in range(3): smaller += vec[i] * (10**i) # Generates the biggest number possible

    result = bigger - smaller;
    print("Maior_valor - Menor_valor -> {} - {} = {}".format(bigger, smaller, result)) 
    

    if result == MAGIC_NUMBER: print("{} iterações".format(iterations+1)); exit()
    three_alg(result, (iterations+1))


if __name__ == "__main__":
    n = int(input("Informe N: "));
    if( n > 999 and n <= 9999 ):  four_alg(n);    
    elif( n <= 999 and n > 99 ):  three_alg(n);
    else: print("usage: 999 > N <= 9999");



