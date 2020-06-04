#include "../headers/queue.hpp"

void prepareNumber(const int number, char* output){
    char newNumber[BUFFER_SIZE];
    sprintf(newNumber, "%03d", number);
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
    strcpy(pass, PREGNANT_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}


void getAgedPass(const int number, char* output){
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, AGED_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}

void getNormalPass(const int number, char* output){
    char pass[BUFFER_SIZE];
    char actualNumber[BUFFER_SIZE];
    strcpy(pass, NORMAL_PREFIX);
    prepareNumber(number, actualNumber);
    strcat(pass, actualNumber);
    strcpy(output, pass);
}


void insertStart(queue* row, const char* c){
    queue* aux;
    aux = (queue*) calloc(1, sizeof(queue));
    strcpy(aux->pass, c);
    aux->next = row;
    *row = *aux;
}

void initialize(queue** row){
    *row= NULL;
}

void showAll(queue* row){
    queue* aux = row;
    while(aux != NULL){
        printf("Senha: %s\n", aux->pass);
        aux = aux->next;
    }
}
