#!/usr/bin/python3

# Faça um programa que leia três notas e calcule e mostra a média ponderada
# do aluno considerando que a nota 1 tem peso 2, a nota 2 tem peso 3 e a nota 3
# tem peso 5.

nota1 = int(input("Informe a nota 1: "))
nota2 = int(input("Informe a nota 2: "))
nota3 = int(input("Informe a nota 3: "))

nota1 *= 2
nota2 *= 3
nota3 *= 5

result = (nota1 + nota2 + nota3) / 3

print("{:.2}".format(result))
