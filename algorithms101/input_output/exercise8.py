# Faça um algoritmo que leia dois valores inteiros e positivos
# e armazene nas variáveis A e B respectivamente. Em seguida
# troque o conteúdo das variáveis, ou seja,
# A d everá receber o valor de B e B o valor de A.

A = int(input("Solicite um numero para a variavel A: "))
B = int(input("Solicite um numero para a variavel B: "))

temp = A
A = B
B = temp

print("A -> ", A) 
print("B -> ", B) 


