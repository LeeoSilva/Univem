#include "../headers/priorityQueue.hpp"


void insert(priorityQueue* row, const char* pass, const unsigned char priority){
    _priorityQueue * aux;
    insertStart(&aux->queues[priority], pass);
}

unsigned getSize(const priorityQueue* rows, const unsigned char priority){
    return sizeof(rows->queues) / sizeof(rows->queues[priority]);
}

unsigned getSize(const queue** rows, const unsigned char priority){
    return sizeof(rows) / sizeof(rows[priority]);
}

void showRow(const queue* row){
    unsigned i = 0;
    for(; i <= getSize(&row, i); ++i)
        printf("%s", row[i].pass);
}
    

void showAll(const priorityQueue * rows){ 
    unsigned i = 0;
    for(; i <= NUMBER_OF_QUEUES; ++i){
        showRow(&rows->queues[i]);
    }
}


