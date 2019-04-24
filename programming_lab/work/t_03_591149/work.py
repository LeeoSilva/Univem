#!/usr/bin/python3
# -*- coding: utf-8 -*-

# Você deverá implementar um algoritmo em Python que receba 
# como dado de entrada um valor inteiro e, mostrar passo a 
# passo as operações acima descritas, ao final, mostre quantas 
# iterações foram necessárias para a conversão do referido valor. 
# Fiquem atentos que para valores de 3 algarismos, a conversão será 
# para 495 e valores de 4 algarismos, a conversão será para 6174.
# Quaisquer outros valores, deverão ser ignorados e mostre a 
# mensagem “ Valor não permitido”


# def split(number):
    

def four_alg(number):
    # Converging the value to 6174.
    hundr = int( (number // 1000) ); 
    cente = int( (number %  1000) // 100 );  
    dezen = int( (number %  100)  // 10 );
    units = int( (number %  10) );
    print("{}\n{}\n{}\n{}\n".format(hundr, cente, dezen, units));
    

def three_alg(number):
    # Convergin the value to 495.
    cente = int( (number // 100) );
    dezen = int( (number % 100) // 10 );
    units = int( (number % 10) );
    print("{}\n{}\n{}\n".format(cente, dezen, units));


if __name__ == "__main__":
    n = int(input("Informe N: "));
    if( n > 999 and n <= 9999 ):  four_alg(n);    
    elif( n <= 999 and n > 99 ): three_alg(n);


