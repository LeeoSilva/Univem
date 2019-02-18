# Um motorista deseja realizar uma viagem e, com isso
# precisa saber quanto tempo levará o seu percurso.
# Elabore um algoritmo que leia a distância em km e a
# velocidade média que o veículo irá transitar e
# calcule e mostre o tempo da viagem.


dist = float(input("Solicite a distância em Km do percurso: "))
vel  = float(input("Solicite a velocidade média do veículo de escolha: "))
print("O tempo da viagem é aproximadamente", (dist / vel), " horas")
