#pragma once 
#define BUFFER_SIZE 6 

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


