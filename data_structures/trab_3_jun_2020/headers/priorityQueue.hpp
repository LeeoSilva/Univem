#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include "../headers/client.hpp"

typedef struct _priorityQueue {
    client person; 
    _priorityQueue* next;
} priorityQueue;


static int tamanho(priorityQueue * lst);
void inicializar(priorityQueue** lst);
void mostrarTodos(priorityQueue * l);
void destruir(priorityQueue ** lst);
int inserirInicio(priorityQueue** lst, char* pass);
int eliminar(priorityQueue ** lst, int n);
