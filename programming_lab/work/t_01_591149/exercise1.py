#!/usr/bin/python

# Escreva um programa para aprovar o empréstimo bancario para a compra de uma casa. O
# programa deve perguntar o valor da casa a comprar, o salário e a quantidade de anos a
# pagar. O valor da prestação mensal não pode ser superior a 30% do salário. Calcule o
# valor da prestação como sendo o valor da casa a comprar dividido pelo número de
# meses a pagar.

home_value = float(input("Informe o valor da casa a comprar: "))
if( home_value <= 0 ): print("Valor inválido"); exit() # Evita divisão por 0 ou número negativo

years = int(input("Informe a quantidade de anos a pagar: "))
if( years <= 0 ): print("Valor inválido"); exit() # Evita divisão por 0 ou número negativo

salary = float(input("Informe o valor de seu salário: "))
if( salary < 0 ): print("Valor inválido"); exit() # Salário não pode negativo.

# Calculo da prestação mensal
installment = home_value / years

if( installment > (salary * 0.3) ): print("Valor da mensalidade maior que 30% de seu salário, Emprestimo bancário reprovado.")
else: print("Emprestimo bancário aprovado.")
exit();
