#include "../headers/priorityQueue.hpp"


int insert(_priorityQueue** row, const char* pass, const unsigned char priority){
    printf("it reached insert\n");
    _priorityQueue * aux;
    aux = (_priorityQueue*) calloc(1, sizeof(_priorityQueue));
    strcpy(aux->queues[priority].pass, pass);
    return 0;
}

unsigned getSize(const _priorityQueue* rows, const unsigned char priority){
    return sizeof(rows->queues) / sizeof(rows->queues[priority]);
}

void showAll(_priorityQueue * l){ }


