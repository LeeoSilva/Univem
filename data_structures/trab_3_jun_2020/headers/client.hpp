#pragma once 
#define BUFFER_SIZE 6 

#define NORMAL_PREFIX    "N1"
#define AGED_PREFIX      "I2"
#define DEFICIENT_PREFIX "D3"
#define PREGNANNT_PREFIX "G4"

#include <cstring>
#include <stdio.h>

static enum _level {
    DEFICIENT,
    PREGNANT,
    AGED,
    NORMAL,
} level;

typedef struct _client{
    char pass[BUFFER_SIZE];
    enum _level priorityLevel;
} client;

void getDeficientPass(const int number, char* output);
void getPregnantPass(const int number, char* output);
void getAgedPass(const int number, char* output);
void getNormalPass(const int number, char* output);
void prepareNumber(const int number, char* output);
