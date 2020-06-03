#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// magic numbers 
#define BUFFER_SIZE 30 
#define FAILED -1

typedef struct _lista{
    char info;
    struct _lista * prox;
} lista;

void inicializar(lista ** lst){
    *lst = NULL;
}

int inserirInicio(lista ** lst, char c){
    lista * aux;
    aux = (lista*) calloc(1,sizeof(lista));
    aux->info = c;
    aux->prox = *lst;
    *lst = aux;
    return 0;
}

void mostrarTodos(lista * l){
    lista * aux=l;
    while(aux!=NULL){
        printf("%c, ", aux->info);
        aux = aux->prox;
    }
}

int inserirFinal(lista ** lst, char c){
    lista * aux = *lst;
    lista * aux2;
    if(aux==NULL){
        return inserirInicio(lst, c);
    }
    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    aux2 = (lista *) calloc(1,sizeof(lista));
    aux2->info = c;
    aux2->prox = aux->prox;
    aux->prox = aux2;
    return 0;
}


void intercalate(lista** f1, lista** f2, lista** output){
    int i = 0;

    lista* f1_aux = *f1; 
    lista* f2_aux = *f2;

    while(f1_aux != NULL || f2_aux != NULL){
        if(!(i % 2)){
            if(f1_aux != NULL){
                inserirFinal(output, f1_aux->info);
                f1_aux = f1_aux->prox;
            }
        }
        else{
            if(f2_aux != NULL){
                inserirFinal(output, f2_aux->info);
                f2_aux = f2_aux->prox;
            }
        }
        ++i;
    }

}


int main(void){

    lista f1;
    lista *f1_ptr = &f1;
    lista f2;
    lista *f2_ptr = &f2;
    lista f3;
    lista *f3_ptr = &f3;

    inicializar(&f1_ptr);
    inicializar(&f2_ptr);
    inicializar(&f3_ptr);


    printf("before\n");
    // param1: a, b, c, d
    inserirFinal(&f1_ptr, 'a');
    inserirFinal(&f1_ptr, 'b');
    inserirFinal(&f1_ptr, 'c');
    inserirFinal(&f1_ptr, 'd');
    mostrarTodos(f1_ptr);
    printf("\n");

    // param2: r, s, t, u, v, w
    inserirFinal(&f2_ptr, 'r');
    inserirFinal(&f2_ptr, 's');
    inserirFinal(&f2_ptr, 't');
    inserirFinal(&f2_ptr, 'u');
    inserirFinal(&f2_ptr, 'v');
    inserirFinal(&f2_ptr, 'w');
    mostrarTodos(f2_ptr);
    printf("\n");


    printf("after\n");
    intercalate(&f1_ptr, &f2_ptr, &f3_ptr);
    mostrarTodos(f3_ptr);
    printf("\n");

    // result: a, r, b, s, c, t, d, u, v, w


    return 0; 
}

