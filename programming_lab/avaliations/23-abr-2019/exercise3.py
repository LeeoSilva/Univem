#!/usr/bin/python3

# Faça um programa que leia um valor n e mostre 
# uma sequencia com n+1 elementos onde o elemento
# na posição i (i entre 0 e n) é dado por: i * (n-i).

n = int(input("Informe N: "));

for i in range(0, n+1):
	print(i * (n-i));

