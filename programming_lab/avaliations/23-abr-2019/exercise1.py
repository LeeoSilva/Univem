#/usr/bin/python3

# Faça um programa que leia o número de notas de 
# R$ 2,00; R$ 5,00; R$ 10,00 e R$ 20,00 reais que estão
# presentes em um cofre. Em seguida, mostre o valor
# total contido no cofre.


result = float(0);

two    = int(input("Informe o número de notas de 2 reais: "))
result += 2 * two;

five   = int(input("Informe o número de notas de 5 reais: "))
result += 5 * five;

ten    = int(input("Informe o número de notas de 10 reais: "))
result += 10 * ten;

twenty = int(input("Informe o número de notas de 20 reais: "))
result += 10 * twenty;

fifty  = int(input("Informe o número de notas de 50 reais: "))
result += 50 * fifty;

print("O valor total do cofre é: R$ {}".format(result))

