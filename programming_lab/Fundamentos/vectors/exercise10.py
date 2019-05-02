#!/usr/bin/python3

# Ler um número inteiro N e criar um vetor com o número em binário.
# Exemplo 10:
# [1] [0] [0]

cont = int(0)
div = int(1)
rest = int(0)
final = []

n = int(input("Informe N: "))
    
while div != 0:
    div = n//2
    rest = n%2
    final.insert(cont, rest)
    n = div

print(final)
