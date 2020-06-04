#include "../headers/priorityQueue.hpp"

void inicializar(priorityQueue** lst){
    *lst = NULL;
}

int inserirInicio(priorityQueue** lst, char pass[]){
    priorityQueue * aux;
    aux = (priorityQueue*) calloc(1,sizeof(priorityQueue));
    strcpy(aux->person.pass, pass);
    aux->next = *lst;
    *lst = aux;
    return 0;
}

void mostrarTodos(priorityQueue * l){
    priorityQueue *aux = l;
    while(aux!=NULL){
        printf("Senha: %s\n", aux->person.pass);
        aux = aux->next;
    }

}


