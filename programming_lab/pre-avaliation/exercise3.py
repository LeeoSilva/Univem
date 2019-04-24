#!/usr/bin/python3

# 1 - Alcool
# 2 - Gasolina
# 3 - Diesel
# 4 - Fim

alc = int(0)
gas = int(0)
die = int(0)
choise = int(0)


print("Alcool   -> 1")
print("Gasolina -> 2")
print("Diesel   -> 3")
print("")

while choise != 4:
    choise = int(input("Informe o combustivel escolhido: "));
    
    if  ( choise == 1 ): alc += 1;
    elif( choise == 2 ): gas += 1;
    elif( choise == 3 ): die += 1;

print("Quantidade de clientes que abasteceram com: ");
print("Alcool: {}".format(alc))
print("Gasolina: {}".format(gas))
print("Diesel: {}".format(die))

