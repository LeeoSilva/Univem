#!/usr/bin/python3

# Crie um programa que leia duas matrizes 2x2 e calcules sua multiplicação

def populateMatrix(matrix):
    for i in range(2):
        for j in range(2):
            matrix[i][j] = int(input("Informe um valor pra matrix: "));
   
def multiplyMatrix(matrix, otherMatrix):
    result = [[0 for j in range(2)] for i in range(2)];      
    for i in range(len(matrix)):
        for j in range(len(otherMatrix)):
            for k in range(len(matrix)):
                result[i][j] += matrix[i][k] * otherMatrix[k][j]
    return result;

if __name__ == "__main__":
    matrix = [[0 for j in range(2)] for i in range(2)];      
    otherMatrix = [[0 for j in range(2)] for j in range(2)];      
    populateMatrix(matrix); 
    populateMatrix(otherMatrix); 
    print(multiplyMatrix(matrix, otherMatrix));

