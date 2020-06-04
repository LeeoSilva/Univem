#pragma once 
#define NUMBER_OF_QUEUES 3

#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "../headers/queue.hpp"

typedef struct _priorityQueue {
    queue queues[NUMBER_OF_QUEUES];
} priorityQueue;

unsigned getSize(const priorityQueue* rows, const unsigned char priority);
unsigned getSize(const queue** rows, const unsigned char priority);
void showAll(const priorityQueue* queues);
void showRow(const queue* row);
void insert(priorityQueue* row, const char* pass, const unsigned char priority);
void remove(queue* row, const char* pass);
