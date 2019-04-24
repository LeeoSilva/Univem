#!/usr/bin/python3


# Faça um programa que leia 3 valores inteiros e mostre-os em ordem crescente.

values = [0] * 3

for i in range(0, 3):
    values[i] = int(input("Informe o {} valor: ".format(i) ))

values.sort();

for i in range(0, len(values)):
    print(values[i])

