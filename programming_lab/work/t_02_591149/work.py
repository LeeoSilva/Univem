#!/usr/bin/python3

n = int(input("Digite N: "))

for i in range(1, n+1):
    for j in range(1, n+1):
        if (i+j) <= (n+1):
            print(min(i, j), end=" ");
        else:
            print(abs(max(i, j) - (n+1)), end=" ");
    print();
