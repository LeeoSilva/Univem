#pragma once
#include <stdio.h>

extern enum _menuOptions {
    GET_PASS_NORMAL = 1,
    GET_PASS_AGED,
    GET_PASS_PREGNANT,
    GET_PASS_DEFICIENT,
    CALL_NEXT,
    SHOW_QUEUE,
    EXIT
} menuOptions;

int drawMenuAndGetUserDecition();
