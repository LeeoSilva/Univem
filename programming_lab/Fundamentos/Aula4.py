#EXERCICIO 1:
'''
4 - Faca um algoritimo que leia ...

a =int(input("Digite o 1º número:\t"))
b =int(input("Digite o 2º número:\t"))

a,b = b,a

print("\nValores Trocados:\nA(1º número):\t{}\nB(2º número):\t{}".format(a,b))
'''

#EXERCICIO 2:
'''
dist =float(input("Digite a distancia percorrida em km:\t"))
comb =float(input("Digite o total de combustível gasto:\t"))

print("\nO comsumo médio de combustível é: {:.3f}Km/L".format((dist/comb)))
'''

#EXERCICIO 3:


#EXERCICIO 4:
''' EX.15 

km =float(input("Digite a quantidade de Km percorrido:\t"))
dias =int(input("Digite a quantidade de dias que o Carro foi alugado:\t"))

d = dias * 60
h = km * 0.15

print("\nR$60 reais por dia, o carro rodou {} DIA(S), preço dos dias deu: {}"
      "\nRS0,15 por Km rodado, o carro rodou {} KM(S), o preço dos Km deu: {}"
      "\n\nPreço final a pagar:\t{:.2f}".format(dias, d, km, h, (d + h)))

'''
#EXERCICIO 5:
'''from math import sqrt
valor1 =float(input("Digite o nome do 1º valor:\t"))
valor2 =float(input("Digite o nome do 2º valor:\t"))
valor3 =float(input("Digite o nome do 3º valor:\t"))
valor4 =float(input("Digite o nome do 4º valor:\t"))

print("A distancia entre eles é: {:.4f}".format(sqrt((valor2 - valor1)**2 + (valor4 - valor3)**2)))
'''

#EXERCICIO 6:
'''
alt =float(input("\nDigite sua altura:\t"))
sexo =input("Digite seu sexo:\nH - Homens ou F - Feminino\n")

if sexo == 'H':
    print("Seu peso ideal: {:.2f}".format((72.7 * alt) - 58))
if sexo == 'F':
    print("Seu peso ideal: {:.2f}".format((62.1 * alt) - 44.7))
'''

#EXERCICIO 7:
'''
i = 0
vet =[]
aux = 0

for i in range(3):
    vet.append(input("\nDigite a {}º medida:\t".format(i+1)))
    aux =aux + i

if ((vet[0] == vet[1]) & (vet[1] == vet[2])):
    print("\nEsse triangulo é equilátero!")
if ((vet[0] == vet[1]) & (vet[0] != vet[2]) | (vet[1] == vet[2]) & (vet[1] != vet[0]) | (vet[2] == vet[0]) & (vet[0] != vet[1])):
    print("\nEsse triangulo é isósceles!")
if ((vet[0] != vet[1]) & (vet[1] != vet[2])):
    print("\nEsse triangulo é escaleno!")
'''

#EXERCICIO 8:
'''
alunos =1
while (alunos < 61):
	aln1 =float(input("Digite a nota do 1º aluno:\t"))
	aln2 =float(input("Digite a nota do 2º aluno:\t"))

	calc = (aln1 + aln2) / 2

	if (calc >= 6):
		print("\nAluno Aprovado!\n\n")
	else :
		print("\nAluno Reprovado!\n\n")
	alunos +=1
'''