#!/usr/bin/python3

# Faça um programa que lê uma letra e uma string e verifica quantas vezes esta aparece na string.

    
def countChar(srt, char):
    if len(char) != 1: print("Não é uma letra"); exit()
    count = int(0);
    for i in srt:
        if i == char: count+=1;
    return count;

if __name__ == "__main__":
    str = input("Informe uma frase: ");
    char = input("Informe a letra que deseja contar: ");
    print(countChar(str, char));
