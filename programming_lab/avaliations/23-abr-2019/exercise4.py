#!/usr/bin/python3

# Em uma determinada competição, os juízes dão 10 notas.
# A nota final do competidor é a média destas notas 
# excluindo a maior e a menor nota. Faça um programa 
# que leia as dez notas e mostre a média do competidor
# seguindo esta regra.

def IndexMaiorNota(vec):
	maior = int(0);
	maiorIndex = int(0);
	for i in range(0, len(vec) ):
		if(vec[i] > maior):
			maior = vec[i];
			maiorIndex = i;

	print("Maior nota {}".format(maior));
	return maiorIndex;

def IndexMenorNota(vec):
	menor = vec[0]; # Put the first index of the vector
	menorIndex = int(0);
	for i in range(0, len(vec) ):
		if(vec[i] < menor):
			menor = vec[i];
			menorIndex = i;

	print("Menor nota {}".format(menor));
	return menorIndex;

notas = [0]*10
for j in range(0, len(notas)):
	notas[j] = int(input("Informe a {} nota: ".format(j)));


result = int(0)
for i in range(0, len(notas) ):
	result += notas[i];

result -= notas[IndexMaiorNota(notas)];
result -= notas[IndexMenorNota(notas)];
result /= (len(notas) - 2);

print("A média foi {}".format(result));


