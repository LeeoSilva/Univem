# Leia o peso e a altura e calcule o IMC:
# IMC = peso / (altura ^ 2)

weight = float(input("Solicite seu peso: "))
height = float(input("Solicite sua altura: "))
print("Seu IMC é {}".format((weight / (height**2))))
