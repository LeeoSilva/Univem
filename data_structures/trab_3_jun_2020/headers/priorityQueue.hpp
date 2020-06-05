#pragma once 
#define NUMBER_OF_QUEUES 3

#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "../headers/queue.hpp"

typedef struct _priorityQueue {
    queue queues[NUMBER_OF_QUEUES];
    int length = 0;
    int beginning;
    int end;
} priorityQueue;

unsigned getSize(const priorityQueue* rows, const unsigned char priority);
unsigned getSize(const queue** rows, const unsigned char priority);
void initialize(priorityQueue* row);
void displayQueue(priorityQueue* row);
void remove(queue* row, const char* pass);
int call_next_in_queue(priorityQueue* row);
int checkFull(const priorityQueue* row);
int insert(priorityQueue* row, const char* pass);
