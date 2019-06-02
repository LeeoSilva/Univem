#!/usr/bin/python3

# Quadrado é uma matriz quadrada de lado N, onde a soma dos números das linhas, das
# colunas e das diagonais é constante, sendo que nenhum destes números se repete.


def rows(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            value += matrix[j][i];
            if (value == somation(matrix) 

#def cols(matrix):
#def diagonals(matrix):


def squareSomation(matrix): return (rows(matrix) + cols(matrix) + diagonals(matrix))

def generateMatrix(N): return [[0]*N for i in range(N)] 
def somation(N): return ((N + (N**3)) // 2)

def visualizeMatrix(matrix):
    for i in range(len(matrix)):
        print("");
        for j in range(len(matrix)):
            print("{} ".format(matrix[i][j]), end=" ");
    print("");

def populateMatrix(N):
    for i in range(N):
        for j in range(N):
            print();
            matrix[i][j] = int(input("Informe o valor: "));
            visualizeMatrix(matrix);
    return matrix;


if __name__ == "__main__":
    N = int(input("Informe o lado da matrix: ")) 
    if N <= 0 or N < 2: print("Lado inválido!"); exit()
    matrix = generateMatrix(N);
    matrix = populateMatrix(N);
    if squareSomation(matrix) == somation(N): print("Quadrado Mágico"); 
    else: print("Não é um Quadrado Magico");
    exit();
