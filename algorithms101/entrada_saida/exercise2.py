# Elabore um algoritmo que leia as medidas de um terreno retangular
# (comprimento e largura) e calcule e mostre qual é o perímetro e qual e a
# area do terreno

comprimento = float(input("Solicite o comprimento do terreno: "))
largura     = float(input("Solicite a largura do terreno: "))

print("O perímetro do terreno é: ", ((comprimento * 2) + (largura * 2)))
print("A área do terreno é: ", (comprimento * largura))
