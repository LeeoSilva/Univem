#!/usr/bin/python

# Considering a class of 60 studdents
# make an algorithm that read 2 notes of
# each studdent, get the average and verify if
# each studdent is aproved or disaproved. To
# be aproved the average must be >= 6.

i = 1;
finalsum = 0;
num1 = 0;
mum2 = 0;

while i <= 60:
    num1 = int(input("First score: ")
    if num1 < 0 or num1 > 10: quit()

    num2 = int(input("Second score: ")
    if num2 < 0 or num2 > 10: quit()

	finalsum += (num1 + num2) / 2

    if( finalsum >= 6): print("APROVED")
    else: print("DISAPROVED")
    i+=1;
