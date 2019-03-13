'''
1.) Elabore um algoritmo que leia duas notas pelo teclado e calcule e mostre a média aritmética entre elas.


nota1 =float(input("\nDigite a 1º nota:\t"))
nota2 =float(input("Digite a 2º nota:\t"))

print("\n\nA média aritmética das duas notas é:\t",(nota1+nota2)/2)
'''

# -----------------------

'''
2.) Elabore um algoritmo que leia as medidas de um terreno retangular 
(comprimento e largura) e calcule e mostre qual é o perímetro e qual é a área do terreno.


comprimento =float(input("\nDigite o comprimentodo do terreno:\t"))
largura =float(input("Digite a largura do terreno:\t"))

print("\nO perímetro do terreno é: {:.2f}".format((comprimento+largura)*2),"\nA área do terreno é: {:.2f}".format(comprimento*largura))
'''

# -----------------------

'''
3.) Um motorista deseja realizar uma viagem e, com isso precisa saber 
quanto tempo levará o seu percurso. Elabore um algoritmo que leia a distância em km e a 
velocidade média que o veículo irá transitar e calcule e mostre o tempo da viagem.


km =int(input("\nDigite sua distancia em Km:\t"))
vel_media =int(input("Digite a velocidade média que o veículo irá transitar:\t"))

print("\nVocê irá percorrer {}".format(km/vel_media))
'''

# -----------------------

'''
4.) Faça um algoritmo que receba o preço de um produto, calcule e mostre 
o novo preço, sabendo-se que este sofreu um desconto de 10%.


preco =float(input("\nDigite o preço do produto:\t"))

print("\nO preço do produto com desconto é: {:.0f}".format(preco*0.9))
'''