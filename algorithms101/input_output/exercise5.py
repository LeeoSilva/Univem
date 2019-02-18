# Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas.
# Faça um programa que receba o salário fixo de um funcionário e o
# valor de suas vendas, calcule e mostre a comissão e o salário
# final do funcionário.

salary = float(input("Solicite o salário do funcionário: "))
sales  = float(input("Solicite o valor de suas vendas: "))
print("Commisão do funcionario: ", (sales * 0.04))
print("Salário final do funcionário: ", (salary + (sales * 0.04)))
