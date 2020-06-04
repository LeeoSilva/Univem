#pragma once 
#define BUFFER_SIZE      6 
#define MAX_QUEUE_SIZE   999
#define NORMAL_PREFIX    "N1"
#define AGED_PREFIX      "I2"
#define DEFICIENT_PREFIX "D3"
#define PREGNANT_PREFIX  "G4"

#include <cstring>
#include <stdio.h>
#include <stdlib.h>

extern enum _level {
    NORMAL = 1,
    AGED,
    DEFICIENT,
    PREGNANT,
} level;

typedef struct _queue {
    char pass[BUFFER_SIZE];
} queue;


static void prepareNumber(const int number, char* output);
void getDeficientPass(const int number, char* output);
void getPregnantPass(const int number, char* output);
void getAgedPass(const int number, char* output);
void getNormalPass(const int number, char* output);
void insertStart(queue* row, const char* c);
void insertEnd(queue* row, const char* c);
void initialize(queue* row);
void showAll(queue* row);
