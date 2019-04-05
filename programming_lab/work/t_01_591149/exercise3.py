#!/usr/bin/python
# -*- coding: utf-8 -*-

# Escreva um program que leia dois números e que pergunte qual operação você deseja
# realizar. Você deve poder calcular a soma (+), subtração (-), multiplicação (*) e divisão
# (/). Exiba o resultado da operação solicitada.


def sum():
	print("\n A + B");
	a = float(input("Informe a variavel A: "))
	print("{} + B".format(a));
	b = float(input("Informe a variavel B: "))
	print("{} + {} = {}".format(a, b, (a + b)));

def sub():
	print("\n A - B");
	a = float(input("Informe a variavel A: "))
	print("{} - B".format(a));
	b = float(input("Informe a variavel B: "))
	print("{} - {} = {}".format(a, b, (a - b)));

def mult():
	print("\n A * B");
	a = float(input("Informe a variavel A: "))
	print("{} * B".format(a));
	b = float(input("Informe a variavel B: "))
	print("{} * {} = {}".format(a, b, (a * b)));

def div():
	print("\n A / B");
	a = float(input("Informe a variavel A: "))
	if( a == 0 ): print("Impossível dividir por 0"); exit();
	print("{} / B".format(a));
	b = float(input("Informe a variavel B: "))
	if( b == 0 ): print("Impossível dividir por 0"); exit();
	print("{} / {} = {}".format(a, b, (a / b)));

def showMenu():
	choise =  input("""
Escolha sua operação desejada:
[+] - Adição
[-] - Subtração
[*] - Multiplicação
[/] - Divisão
> """);
	if  ( choise == "+" ): return 1;
	elif( choise == "-" ): return 2;
	elif( choise == "*" ): return 3;
	elif( choise == "/" ): return 4;
	else: return -1;

choise_id = showMenu();
if  ( choise_id == 1 ): sum();
elif( choise_id == 2 ): sub();
elif( choise_id == 3 ): mult();
elif( choise_id == 4 ): div();
else: print("\nTipo de operação inválida.");
