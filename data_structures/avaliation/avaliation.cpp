/*
 * Implemente uma função que receba como parâmetro uma list simplesmente encadeada
 * e um valor inteiro n e divida esta list em outras duas, de tal forma que a
 * primeira list contenha n elementos e a segunda list contenha o restante dos 
 * elementos. A função deve retornar um ponteiro para a segunda list gerada a
 * partir da list original (novo), enquanto lst deve continuar apontando para
 * o primeiro elemento da list original.
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct _list{
    int data;
    struct _list *next;
} list;

void initialize(list** lst){
    *lst = NULL;
}

void displayNodes(list * l){
    list *aux = l;
    while(aux!=NULL){
        printf("data: %d\n", aux->data);
        aux = aux->next;
    }
}


int unshift(list ** lst, int c){
    list* aux;
    aux = (list*) calloc(1,sizeof(list));
    aux->data = c;
    aux->next = *lst;
    *lst = aux;
    return 0;
}

list *generateNewList(list *lst, int index) {
    list *aux = lst;
    list *newList =NULL;
    int i;
    for(i = 0; aux!= NULL; ++i) {
        if (i == index){
            newList= aux;
        }
        aux= aux->next;
    }
    return newList;
}

int push(list** lst, int c){
    list* aux = *lst;
    list * aux2;
    if(aux==NULL){
        return unshift(lst, c);
    }
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux2 = (list *) calloc(1,sizeof(list));
    aux2->data= c;
    aux2->next = aux->next;
    aux->next = aux2;
    return 0;
}

void switchAG(list** lst, lista ** end){
    list* aNode = *lst; // struct to get the values from the original struct 
    list* gNode = *end->prev; // G
    list* bNode = aNode->next;

    aNode->next = *end; // makes the A node point to the end 
    *end->prev = aNode; // makes the last node point to A node


    // making F to A and H to NULL
    aNode->prev = fNode->prev; 
    (fNode->prev)->prox= aNode;
    fNode->next = bNode;
    (fNode->next)->prev= fNode;
    fNode->prev= NULL;

    *lst= fNode; // points the begginning of the list to F
}



list* divide(list* l, int n) {
    list* aux = l; // array to get the values from the original list
    list* newList; // list to be returned
    int i = 0; // index

    for (i = 0; aux != NULL; ++i){
        if (i == n) { // if index is equal to the desired value
            newList = aux->next; // new lists starts at desired index
            aux->next= NULL; // aux->next is now NULL 
            return newList; // return generatedList 
        }
        aux = aux->next;
    }
    return NULL;
}


int main(void){
    list *p_list;
    list *p_newList;
    int i;

    initialize(&p_list);
    initialize(&p_newList);
    for(i = 0 ;i <= 30; ++i){
        push(&p_list, i);
    }

    p_newList = divide(p_list, 8);
    displayNodes(p_newList);
    return 0;
}
