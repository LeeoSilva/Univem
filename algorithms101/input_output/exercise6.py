# Elabore um algoritmo que leia um valor em reais (R$)
# e mostre sua conversão para dólares ($). Para isto o
# algoritmo deverá solicitar ao usuário a cotação do dólar.
# Mostre o resultado.

cotation = float(input("Informe a atual cotação do dolar ($): "))
reais    = float(input("Informe o valor em reais a ser convertido: "))
print("O valor R$", reais, "em doláres é: $", (cotation * reais))
