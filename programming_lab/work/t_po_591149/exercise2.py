#!/usr/bin/python3

# Modifique o exercicio anterior para que seja possível ler as dimensões das matrizes e em seguida ler as matrizes.
# Por fim, faça a multiplicação destas duas matrizes. Lembre-se de que para que seja possível multiplicar, o
# número de colunas de A deve ser igual ao número de linhas de B.

def populateMatrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] = int(input("Informe um valor pra matrix: "));
       
def multiplyMatrix(matrix, otherMatrix):
    matrix_rows      = len(matrix)
    matrix_cols      = len(matrix[0])
    otherMatrix_rows = len(otherMatrix)
    otherNatrix_cols = len(otherMatrix[0])
    
    if matrix_cols != otherMatrix_rows: print("Impossível calcular "); exit()

    result = [[0 for j in range(otherMatrix_cols)] for i in range(matrix_rows)]
    result = [[0 for j in range(2)] for i in range(2)];      

    # Discusting piece of code incomming 
    for i in range(matrix_rows):
        for j in range(otherMatrix_cols):
            for k in range(otherMatrix_rows):
                result[i][j] += matrix[i][k] * otherMatrix[k][j]
    return result;
    # Sorry you had to see that '-'

if __name__ == "__main__":
    matrix_rows = int(input("Informe as fileiras da matrix: "));
    matrix_cols = int(input("Informe as colunas da matrix: "));

    otherMatrix_rows = int(input("Informe as fileiras da outra matrix: "));
    otherMatrix_cols = int(input("Informe as colunas da outra matrix: "));
    
    matrix = [[0 for j in range(matrix_rows)] for i in range(matrix_cols)];      
    otherMatrix = [[0 for j in range(otherMatrix_rows)] for j in range(otherMatrix_cols)];      
    populateMatrix(matrix); 
    populateMatrix(otherMatrix); 
    print(multiplyMatrix(matrix, otherMatrix));

