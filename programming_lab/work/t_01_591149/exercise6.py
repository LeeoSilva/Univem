#!/usr/bin/python

# Escreva um programa que pergunte o deposito inicial e a taxa de juros de uma
# poupança. Exiba os valores mês a mês para os 24 primeiros meses. Escreva o total de
# juros no periodo.


initial_depot = float(input("Informe o deposito inicial: "))
rate = float(input("Informe o taxa de juros de uma poupança: "))
sum = initial_depot;

for i in range(0, 25):
	print("mês {:02} com {}".format(i, sum))
	sum += initial_depot * rate;

print("\nSua poupança gerou R$ {:2f} com o valor inicial de {:.2} após 24 mêses.".format(sum, (sum - initial_depot)))
