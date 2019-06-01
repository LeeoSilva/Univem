#!/usr/bin/python3

# Cria um programa que leia uma string e conte quantas palavras existem na string.

def countWords(str): return len(str.split()); 

if __name__ == "__main__":
    str = input("Informe uma string: ");
    print(countWords(str));

