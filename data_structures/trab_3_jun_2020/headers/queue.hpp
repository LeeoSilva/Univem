#pragma once 
#define BUFFER_SIZE      6 
#define NORMAL_PREFIX    "N1"
#define AGED_PREFIX      "I2"
#define DEFICIENT_PREFIX "D3"
#define PREGNANT_PREFIX  "G4"

#include <cstring>
#include <stdio.h>

extern enum _level {
    NORMAL = 1,
    AGED,
    DEFICIENT,
    PREGNANT,
} level;

typedef struct _queue {
    char pass[BUFFER_SIZE];
} queue;

void getDeficientPass(const int number, char* output);
void getPregnantPass(const int number, char* output);
void getAgedPass(const int number, char* output);
void getNormalPass(const int number, char* output);
static void prepareNumber(const int number, char* output);
