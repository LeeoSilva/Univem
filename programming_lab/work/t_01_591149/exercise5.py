#!/usr/bin/python

# Faça um programa que leia um número e mostre sua tabuada.

number = int(input("Informe um número para ilustrar sua tabuada: "))

print("");
for i in range(1, 11):
	print("\t{} * {} = {:02}".format(number, i, (number * i) ) );
