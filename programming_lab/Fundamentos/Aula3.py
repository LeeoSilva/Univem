'''
1 - Um funcionario recebe um salario fixo ...


salario =float(input("\nDigite o salário do funcionário:\t"))
vendas =int(input("Digite a quantidade de vendas do funcionário:\t"))

print("\n\nO valor da comissão deu:\t{}\nO novo salário é de:\t{}".format(0.04*vendas, salario+(0.04*vendas)))
'''

'''
2 - Elabore um algoritimo que leia ...

valor_reais =float(input("\nDigite um valor em reais:\t"))
cotacao_dolar =float(input("Digite a cotação do dolar do dia atual:\t"))

print("\n\nO valor {} em dólares é:\t{:.2f}".format(valor_reais,(valor_reais/cotacao_dolar)))
'''

'''
3 - Elabore um algoritimo que leia ...

num_int =int(input("\nDigite um número inteiro(max. 3 algarismos) :\t"))

print("\n\nCentena:\t{}\nDezena:\t\t{}\nUnidade:\t{}".format((num_int // 100), (num_int%100)//10, (num_int % 10)))
'''

'''
4 - Faca um algoritimo que leia ...

a =int(input("Digite o 1º número:\t"))
b =int(input("Digite o 2º número:\t"))

a,b = b,a

print("\nValores Trocados:\nA(1º número):\t{}\nB(2º número):\t{}".format(a,b))
'''

'''
5 - Escreva um algoritimo que leia ...

segundos =int(input("\nDigite seu tempo em segundos:\t"))
print("\n\n{} segundos é igual a: {} horas {} minutos e {} segundos".format(segundos,segundos // 3600, (segundos // 720), segundos % 60))
'''