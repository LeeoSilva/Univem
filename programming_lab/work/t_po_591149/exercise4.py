#!/usr/bin/python3

# Crie um programa que verifique se a string tem apenas números

def onlyNumbers(str):
    for i in str:
        if i < "0" or i > "9": return False;
    return True;

if __name__ == "__main__":
    str = str(input("Informe uma frase: "));
    if onlyNumbers(str): print("A frase tem apenas números")
    else: print("A frase não tem apenas números")


