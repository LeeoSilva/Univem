#!/usr/bin/python3

# Crie um programa que leia uma palavra e uma string e conte quantas vezes a palavra aparece na string.

def countOccurances(str, word):
    value = int(0) 
    for i in str.split():
        if i == word: value+=1
    return value;

if __name__ == "__main__":
    str = input("Informe uma frase: ");
    word = input("Informe uma palavra à ser contada na frase: ");
    print(countOccurances(str, word)); 



