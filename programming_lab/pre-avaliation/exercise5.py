#!/usr/bin/python3


def printVector(vec, n):
    for i in range(0, n):
        print(vec[i]);



n = int(input("Informe N: "))
vector = [0]*n

for i in range(0, n):
    vector[i] = int(input("Informe o index {}: ".format(i) ))

print("Não ordenado.")
printVector(vector, n) 



vector.sort()
print("Ordenado em ordem crescente")
printVector(vector, n)

print("Ordenado em ordem decrescente")
vector.sort(reverse=True)
printVector(vector, n)



