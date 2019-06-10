#!/usr/bin/python3

# Quadrado é uma matriz quadrada de lado N, onde a soma dos números das linhas, das
# colunas e das diagonais é constante, sendo que nenhum destes números se repete.

def rows(matrix):
    sumRows = int(0);
    value = int(0);
    for i in range(len(matrix)):
        sumRows += value;
        value = 0
        for j in range(len(matrix[0])):
            value += matrix[i][j] 
    return sumRows / len(matrix);

def cols(matrix):
    sumCols = int(0);
    value = int(0);
    for i in range(len(matrix)):
        sumCols += value;
        value = 0;
        for j in range(len(matrix[0])):
            value += matrix[j][i]
    return sumCols / len(matrix);

def diagonals(matrix):
    value =  int(0);
    value =  sum([matrix[i][i] for i in range(len(matrix))]) # Somando valores da diagonal principal
    value += sum(matrix[i][len(matrix)-i-1] for i in range(len(matrix))) # Somando valores da diagonal secundaria
    return value / len(matrix); 

def squareSomation(matrix): return ((rows(matrix) + cols(matrix) + diagonals(matrix)) / 2); 
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
    print("somation = {}".format(somation(N)));
    print("squareSomation = {}".format(squareSomation(matrix)));
    if squareSomation(matrix) == somation(N): print("Quadrado Mágico"); 
    else: print("Não é um Quadrado Magico");
    exit();
