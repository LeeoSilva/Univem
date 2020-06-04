#include "../headers/priorityQueue.hpp"



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

void initialize(priorityQueue* row){
    row->beginning = 0;
    row->end = 0;
}

int checkFull(const priorityQueue* row){
    if(row == NULL) return -1;
    if(row->length == MAX_QUEUE_SIZE) return 1;
    return 0;
}

int insert(priorityQueue* row, const char* pass, const unsigned char priority){
    if(row == NULL || checkFull(row)) return 0;
    strcpy(row->queues[row->end].pass, pass);
    row->end = (row->beginning+1) % MAX_QUEUE_SIZE;
    row->length++;
    return 1;
}

void showAll(const priorityQueue* row) {
    int head = row->beginning;
    while (head != row->end){
        printf("%s \n", row->queues[head].pass);
        head=(head + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}


