#!/usr/bin/python

# Escreva um programa que calcule o preço a pagar pelo emprestimo de energia
# elétrica. Pergunte a quantidade de kWh consumida e o tipo de instalação: R para
# residências I para indústrias e C para comércios. Calcule o preço a pagar de acordo
# com a tabela a seguir:

# Preço por tipo e a faixa de consumo:

# TIPO	      | FAIXA (kWh)   | PREÇO
# Residêncial | Até 500	      | R$ 0,40
#			  | Acima de 500  | R$ 0,65

# Comercial   | Até 1000      | R$ 0,55
#       	  | Acima de 1000 | R$ 0,60

# Industrial  | Até 5000	  | R$ 0,55
#  			  | Acima de 5000 | R$ 0,60


def showPrices():
	print("""
	# TIPO\t\t| FAIXA (kWh)\t| PREÇO\t\t#
	# Residêncial\t| Até 500\t| R$ 0,40\t#
	#\t\t| Acima de 500\t| R$ 0,65\t#
	# Comercial\t| Até 1000\t| R$ 0,55\t#
	#\t\t| Acima de 1000\t| R$ 0,60\t#
	# Industrial\t| Até 5000\t| R$ 0,55\t#
	#\t\t| Acima de 5000\t| R$ 0,60\t#
	""")

def showMenu():
	choise = input("""
Qual seu tipo de instalação?
[R] - Residêncial
[C] - Comercial
[I] - Industrial
> """)
	if  ( choise == "R" or choise == "r" ): return 1;
	elif( choise == "C" or choise == "c" ): return 2;
	elif( choise == "I" or choise == "i" ): return 3;
	else: return -1;


def residential_choise():
	kwh = int(input("\nInforme a quantidade de KWh consumida pela sua residência: "))
	if  ( kwh <= 0 ): exit();
	elif( kwh <= 500 ): print("O preço a 	pagar de acordo com a tabela é {:.2f}".format(kwh / 0.40));
	else: print("O preço a pagar de acordo com a tabela é {:.2f}".format( (kwh / 0.65) ));

def comercial_choise():
	kwh = int(input("\nInforme a quantidade de KWh consumida pelo seu comércio: "))
	if  ( kwh <= 0 ): exit();
	elif( kwh <= 1000 ): print("O preço a pagar de acordo com a tabela é {:.2f}".format(kwh / 0.55));
	else: print("O preço a pagar de acordo com a tabela é {:.2f}".format( (kwh / 0.60) ));

def industrial_choise():
	kwh = int(input("\nInforme a quantidade de KWh consumida pela sua industria: "))
	if  ( kwh <= 0 ): exit();
	elif( kwh <= 5000 ): print("O preço a pagar de acordo com a tabela é {:.2f}".format(kwh / 0.55));
	else: print("O preço a pagar de acordo com a tabela é {:.2f}".format( (kwh / 0.60) ));

showPrices();
choise_id = showMenu();
if  ( choise_id == 1 ): residential_choise()
elif( choise_id == 2 ): comercial_choise()
elif( choise_id == 3 ): industrial_choise()
else: print("Tipo de instalação inválida.");
exit();
