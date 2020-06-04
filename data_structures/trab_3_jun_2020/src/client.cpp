#include "../headers/client.hpp"

void prepareNumber(const int number, char* output){
    printf("prepareNumber has been called\n");
    char newNumber[BUFFER_SIZE];
    sprintf(newNumber, "%03d", number);
    printf("%s", newNumber);
    strcpy(output, newNumber);
}

void getDeficientPass(const int number, char* output){
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, DEFICIENT_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}

void getPregnantPass(const int number, char* output){
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, DEFICIENT_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}


void getAgedPass(const int number, char* output){
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, DEFICIENT_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}

void getNormalPass(const int number, char* output){
    printf("get normal pass has been called\n");
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, DEFICIENT_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}
