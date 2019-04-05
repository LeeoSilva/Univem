#!/usr/bin/python
# -*- coding: utf-8 -*-

# Leonardo Camargo Silva
# RA: 591149

# Você deverá implementar um algoritmo em Python que receba como dado de entrada
# um valor inteiro e, mostrar passo a passo as operações acima descritas,
# ao final, mostre quantas iterações foram necessárias para a conversão do referido
# valor. Fiquem atentos que para valores de 3 algarismos, a conversão será para 495
# e valores de 4 algarismos, a conversão será para 6174.
# Quaisquer outros valores, deverão ser ignorados e mostre a mensagem “ Valor não permitido”

def QuantifyCent(number):
	cent  = int(number // 100); # Getting the centenal number.
	deze  = int((number % 100) // 10); # Getting the dezenal number.
	unit  = int(number % 10); # Getting the unit number.

def QuantifyMil(number):
	mil = int(number // 1000); # Getting the milenial number.
	cent = int((number % 1000) / 100); # Getting the centenal number.
	deze = int((number % 100) // 10); # Getting the dezenal number.
	unit = int(number % 10); # Getting the unit number.

number = int(input("Insira um número inteiro: "));
if( number < 999 and number > 0 ): QuantifyCent(number);
elif( number > 999 and number < 10000 ): QuantifyMil(number);
else: print("Valor não permitido");
