#pragma once
#include <stdio.h>
#include "../headers/priorityQueue.hpp"

extern enum _actions {
    GET_PASS_NORMAL = 1,
    GET_PASS_AGED,
    GET_PASS_PREGNANT,
    GET_PASS_DEFICIENT,
    CALL_NEXT,
    SHOW_QUEUE,
    EXIT
} actions; 

int drawMenuAndGetUserDecision();
void getPassAndRegister(const unsigned char priority, _priorityQueue* queues);
