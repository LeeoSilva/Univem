#!/usr/bin/python3

def getLinhagem():
		return input("Informe a linhagem do animal: ")
		linhagem(linhagem);

def linhagemAve(linhagem):
	if(linhagem == "carnivoro"): print("aguia");
	elif(linhagem == "onivoro"): print("pomba");
	else: print("Não existe"); exit()

def linhagemMamifero(linhagem):
	if(linhagem == "onivoro"): print("Homem");
	elif(linhagem == "herbivoro"): print("Vaca");
	else: print("Não existe"); exit()

def linhagemInseto(linhagem):
	if(linhagem == "hematofago"): print("pulga");
	elif(linhagem == "herbivoro"): print("lagarta");
	else: print("Não existe"); exit()

def linhagemAnalideo(linhagem):
	if(linhagem == "hematofago"): print("sanguessuga");
	elif(linhagem == "onivoro"): print("minhoca");
	else: print("Não existe"); exit()


def semNome(animal):
	if  (animal == "ave"): linhagemAve(getLinhagem())
	elif(animal == "mamifero"): linhagemMamifero(getLinhagem())
	elif(animal == "inseto"): linhagemInseto(getLinhagem())
	elif(animal == "analideo"): linhagemAnalideo(getLinhagem())
	else: print("Não existe"); exit()


def vertebrado():
	Animal = input("Animal: ")
	if(Animal == "ave"):  semNome("ave")
	elif(Animal == "mamifero"): semNome("mamifero")
	else: print("Não existe"); exit()

def invertebrado():
	Animal = input("Animal: ")
	if(Animal == "inseto"): semNome("inseto")
	elif(Animal == "analideo"): semNome("analideo") 
	else: print("Não existe"); exit()

vertebra = input("Vertebra: ")
if(vertebra == "vertebrado"): vertebrado()
elif(vertebra == "invertebrado"): invertebrado()
else: print("Não existe"); exit() 


