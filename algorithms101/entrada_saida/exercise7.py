# Elabore um algoritmo que leia um numero inteiro (max. 3 algarismos)
# e mostre os algarismos em separado. Ex. NUM == 725 o algoritmo
# produzirá: Centena = 7, Dezena = 2 e Unidade = 5.

num = int(input("Solicite um número inteiro de no máximo 3 algarismos: "))
print("Centena: ", (num // 100) )
print("Dezena: ", ((num % 100) // 10))
print("Unidade: ", (num % 100) % 10)
