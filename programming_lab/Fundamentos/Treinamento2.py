''' EX.11
largura =float(input("Digite a largura da parede:\t"))
altura =float(input("Digite a altura da parede:\t"))

area = largura * altura

print("\n\nSua parede tem a dimensão de {}x{} e sua área é de {}m2."
      "\nPara pintar essa parede, você precisará  de {}L de tinta.".format(largura,altura,area,(area / 2)))
'''

''' EX.13

salario =float(input("Digite o salário do funcionário:\t"))
print("\n\nO novo salário do funcionário será de:\t{}".format(salario + (salario * 0.15)))
'''

''' EX.15

km =float(input("Digite a quantidade de Km percorrido:\t"))
dias =int(input("Digite a quantidade de dias que o Carro foi alugado:\t"))

d = dias * 60
h = km * 0.15

print("\nR$60 reais por dia, o carro rodou {} DIA(S), preço dos dias deu: {}"
      "\nRS0,15 por Km rodado, o carro rodou {} KM(S), o preço dos Km deu: {}"
      "\n\nPreço final a pagar:\t{:.2f}".format(dias, d, km, h, (d + h)))
'''

''' EX.16

#num =float(input("Digite um número:\t"))
#print("\n\nO número digitado foi: {}, e sua porção inteira é: {:.0f}".format(num,num))

#ou

from math import trunc
num =float(input("Digite um número:\t"))
print("\n\nO número digitado foi: {}, e sua porção inteira é: {}".format(num, trunc(num)))

#ou

num =float(input("Digite um número:\t"))
print("\n\nO número digitado foi: {}, e sua porção inteira é: {}".format(num, int(num)))
'''

''' EX.17

cateto_oposto =float(input("Digite o comprimento do cateto oposto:\t"))
cateto_adjacente =float(input("Digite o comprimento do cateto adjacente:\t"))

print("\n\nA hipotenusa irá medir: {:.2f}".format((cateto_oposto ** 2 + cateto_adjacente ** 2) ** (0.5)))

#ou

from math import hypot
cateto_oposto =float(input("Digite o comprimento do cateto oposto:\t"))
cateto_adjacente =float(input("Digite o comprimento do cateto adjacente:\t"))

print("\n\nA hipotenusa irá medir: {:.2f}".format(hypot(cateto_oposto, cateto_adjacente)))
'''

'''EX.18

from math import sin,cos,tan,radians
angulo =float(input("Digite um ângulo qualquer:\t"))

seno =sin(radians(angulo))
cosseno =cos(radians(angulo))
tangente =tan(radians(angulo))

print("\n\nO angulo de {} tem:\nSeno: {:.2f}\nCosseno: {:.2f}\nTangente: {:.2f}".format(angulo, seno, cosseno, tangente))
'''

''' EX. 19

from random import choice
nome1 =input("Digite o nome do 1º aluno:\t")
nome2 =input("Digite o nome do 2º aluno:\t")
nome3 =input("Digite o nome do 3º aluno:\t")
nome4 =input("Digite o nome do 4º aluno:\t")

lista = [nome1,nome2,nome3,nome4]

escolhido =random.choice(lista)

print("\n\nO nome escolhido foi: ",escolhido)

#ou

from random import choice
lista =[]
for i in range(4):
      lista.append(input("Digite o {}º nome:\t".format(i+1)))

print("\n\nO nome escolhido foi: {}".format(choice(lista)))
'''

''' EX.20

from random import shuffle
nome1 =input("Digite o nome do 1º aluno:\t")
nome2 =input("Digite o nome do 2º aluno:\t")
nome3 =input("Digite o nome do 3º aluno:\t")
nome4 =input("Digite o nome do 4º aluno:\t")

lista =[nome1,nome2,nome3,nome4]
shuffle(lista)

print(lista)

#ou

from random import shuffle

lista =[]
for i in range(4):
      lista.append(input("Digite o nome do {}º aluno:\t".format(i+1)))
shuffle(lista)
print(lista)
'''
