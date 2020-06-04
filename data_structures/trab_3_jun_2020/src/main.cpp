#include <stdio.h>
#include <stdlib.h>
#include <cstring>

// magic numbers 
#define BUFFER_SIZE 6 
#define FAILED -1

enum _menu {
    NORMAL = 1,
    AGED,
    PREGNANT,
    DEFICIENT,
    CALL_NEXT,
    SHOW_QUEUE,
    EXIT
} menu;

enum _level {
    DEFICIENT,
    PREGNANT,
    AGED,
    NORMAL,
} level;

typedef struct _priorityQueue {
    client person; 
    struct _priorityQueue* next;
} priorityQueue;

typedef struct _client{
    char pass[BUFFER_SIZE];
    enum level priorityLevel;
} client;


void inicializar(priorityQueue** lst){
    *lst = NULL;
}

int inserirInicio(priorityQueue** lst, char* pass){
    priorityQueue * aux;
    aux = (priorityQueue*) calloc(1,sizeof(priorityQueue));
    aux->pass = pass;
    aux->next = *lst;
    *lst = aux;
    return 0;
}

void mostrarTodos(priorityQueue * l){
    priorityQueue * aux=l;
    while(aux!=NULL){
        printf("Senha: %s\n", aux->pass);
        aux = aux->next;
    }
}

int eliminar(priorityQueue ** lst, int n){
    int i;
    priorityQueue * aux = *lst;
    priorityQueue * excluir;

    if((n == 0) && (aux != NULL)){
        *lst = aux->next;
        free(aux);
        return 0;
    }else{
        for(i = 0; i < n-1; ++i){
            aux = aux->next;
            if(aux == NULL) break;
        }
        if((aux != NULL) && (aux->next != NULL)){
            excluir = aux->next;
            aux->next = excluir->next;
            free(excluir);
            return 0;
        }
        return FAILED;
    }
}

void destruir(priorityQueue ** lst){
    priorityQueue * aux = *lst;
    priorityQueue * excluir;

    while(aux!=NULL){
        excluir = aux;
        aux = aux->next;
        free(excluir);
    }

    *lst = NULL;
}

void mostrarN(priorityQueue * l, int n){ 
    priorityQueue * aux = l;
    int i = 0;

    while(aux!=NULL){
        if(i==n){
            printf("Senha: %s\n",aux->pass);
        }
        aux = aux->next;
        i+=1;
    }
}

int inserirPosicao(priorityQueue ** lst, int n, char* c){
    priorityQueue * aux = *lst;
    priorityQueue * aux2;
    int i=0;
    if(n==0) return inserirInicio(lst, c); 

    for(i = 0; i < n-1; ++i){
        if(aux->next == NULL){
            printf("Posicao invalida.\n");
            return FAILED;
        }
        aux = aux->next;
    }

    aux2 = (priorityQueue *) calloc(1,sizeof(priorityQueue));
    aux2->pass= c;
    aux2->next = aux->next;
    aux->next = aux2;
    return 0;
}

char* acessar(priorityQueue * l, int n){
    int i;
    priorityQueue * aux = l;
    for(i = 0; i < n; ++i){
        if(aux==NULL) break;
        aux = aux->next;
    }
    if(aux!=NULL) return &aux->pass;
    return NULL;
}

int buscar(priorityQueue * lst, char* pass)
    int i=0;
    priorityQueue * aux = lst;

    while(aux != NULL){
        if(strcmp(pass, aux->pass)) break;
        aux = aux->next;
        i++;
    }
    if(aux==NULL) return FAILED;
    return i;
}

int tamanho(priorityQueue * lst){
    int i=0;
    priorityQueue * aux = lst;
    while(aux!=NULL){
        aux = aux->next;
        i++;
    }
    return i;
}

int inserirFinal(priorityQueue ** lst, char* c){
    priorityQueue * aux = *lst;
    priorityQueue * aux2;
    if(aux==NULL){
        return inserirInicio(lst, c);
    }
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux2 = (priorityQueue *) calloc(1,sizeof(priorityQueue));
    aux2->pass = c;
    aux2->next = aux->next;
    aux->next = aux2;
    return 0;
}

int drawMenuAndGetUserDecition(){
    int userChoise = EXIT; 
    printf("1 - Retirar senha - atendimento normal. \n");
    printf("2 - Retirar senha - atendimento idoso. \n");
    printf("3 - Retirar senha - atendimento gestante. \n");
    printf("4 - Retirar senha - atendimento deficiente. \n");
    printf("5 - Proximo na fila. \n");
    printf("6 - Mostrar Fila. \n");
    printf("7 - Sair. \n");
    printf("Informe sua ação: \n");
    scanf("%d", &userChoise);
    fflush(stdin);
    return userChoise;
}

int main(void){
    int userChoise = drawMenuAndGetUserDecition();
    switch(userChoise){
        case NORMAL: printf("Normal\n");break;
        case AGED: printf("Aged\n"); break;
        case PREGNANT: printf("Pregnant\n"); break;
        case DEFICIENT: printf("Deficient\n"); break;
        case CALL_NEXT: printf("call_next\n"); break;
        case SHOW_QUEUE: printf("show_queue\n"); break;
        case EXIT: return 0;
        default: printf("Ação inválida! Fechando Sistema.\n"); return 0;
    };
}
