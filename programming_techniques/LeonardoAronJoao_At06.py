#!/usr/bin/python3

# Leonardo Camargo - RM: 591149
# Aron Vinícius - RM: 589977
# João G - RM: 588466

import sys; # Lib for entering the name of the file.
import pickle;

dic = {
    "amarelo": "yellow",
    "abaxaci": "pineapple",
    "bicicleta": "bike",
    "peru": "peru",
    "relogio": "watch",
    "computador": "computer",
    "anel": "ring",
    "celular": "cellphone",
    "mouse": "rato",
    "teclado": "keyboard",
    "refrigerante": "soda",
    "tenis": "shoes",
    "oculos": "glasses",
    "bolsa": "bag",
    "mesa": "table",
    "agua": "water",
    "fone de ouvido": "earphone"
};

def updateWord():
    word = input("Informe a palavra que deseja atualizar: ");
    for key, val in dic.items():
        if(word == key or word == val): del dic[key]; break;
    dic[word] = input("Informe sua alteração: ");
    print(word, "=>", dic[word]);
    print("Alterada com sucesso.");

def excludeWord():
    word = input("Informe a palavra que deseja excluir: ");
    if word in list(dic.keys()): 
        for key, val in dic.items():
            if(word == key or word == val):
                del dic[key];
                print(key, "deletada com sucesso.");
                break;
    else: print(key, "não encontrada.");

def drawTranslationTable(): [print(k, '=>', dic[k]) for k in list(dic.keys())];
def getTranslation(choise):
    if choise == int(0): # The user wants a portuguese word.
        word = input('[Português]: ').lower();
        if word in list(dic.keys()): print(dic.get(word))
        else: print('Palavra não encontrada.');
    elif choise == int(1): # The user wants a english word.
        word = input('[Inglês]: ').lower();
        if word in list(dic.values()) or dic.keys():
            for key, val in dic.items():
                if word == val: print(key);
        else: print('Palavra não encontrada.');

def setNewWord():
    ptWord = input('[Português]: ').lower();
    enWord = input('[Inglês]: ').lower();
    if ptWord == '' and ptWord == '': print("Palavras não podem ser nulas."); return;
    dic[ptWord] = enWord;

def saveInMemory(filename): # The dictionary is saved in memory and is saved in the file when the user wants
    with open(filename, mode='rb') as filehandler:
        dic = pickle.load(filehandler);
        print("Salvo na memoria com sucesso.");

def saveInBin(obj): 
    if(len(sys.argv) == 1): # None argument given
        print("Argumento de arquivo não encontrado.");
        filename = input("Digite o nome de um novo arquivo (sem extensão): ") + '.bin';
        with open(filename, mode='wb') as filehandler: pickle.dump(obj, filehandler);
        print("Salvo em ", filename, "com sucesso");
    else:
        with open(sys.argv[1], mode='wb') as filehandler: pickle.dump(obj, filehandler);
        print("Salvo em ", sys.argv[1], "com sucesso");
    
def getUserChoise(): 
    print();
    print("1) Cadastrar palavras.");
    print("2) Consultar palavras em inglês.");
    print("3) Consultar palavras em português.");
    print("4) Listar tabela de traduções.");
    print("5) Alterar palavra.");
    print("6) Excluir palavra.");
    print("7) Salvar em arquivo binário.");
    print();
    return int(input("Informe sua opção: "));

if __name__ == "__main__":
    if "amarelo" in dic.items(): print("Hey")
    if(len(sys.argv) > 1): saveInMemory(sys.argv[1]);
    print('ProTip: Informe o nome do arquivo binário como argumento na execução desde código. :)')
    userChoise = int(1);
    while(userChoise != 0):
        userChoise = getUserChoise();
        if userChoise == int(1): setNewWord();
        elif userChoise == int(2): getTranslation(int(0));
        elif userChoise == int(3): getTranslation(int(1));
        elif userChoise == int(4): drawTranslationTable();
        elif userChoise == int(5): updateWord();
        elif userChoise == int(6): excludeWord();
        elif userChoise == int(7): saveInBin(dic)
        else: exit();
