#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cliente{
    char nome[30];
    int idade;
} cliente;

typedef struct _lista{
    cliente info;
    struct _lista * prox;
} lista;

void inicializar(lista ** lst){
    //*lst ==> l
    *lst = NULL;
}

void inicializarCliente(cliente* lst){
    //*lst ==> l
    *lst = NULL;
}

void inserirInicio(lista ** lst, cliente c){
    lista * aux;
    aux = (lista*) calloc(1,sizeof(lista));
    aux->info = c;
    //*lst ==> l
    aux->prox = *lst;
    *lst = aux;
}

void mostrarPrimeiro(lista * l){
    printf("Nome: %s\n",l->info.nome);
    printf("Idade: %d\n",l->info.idade);
}

void mostrarTodos(lista * l){
    lista * aux=l;
    while(aux!=NULL){
        printf("Nome: %s\n",aux->info.nome);
        printf("Idade: %d\n",aux->info.idade);
        aux = aux->prox;
    }
}

void eliminar(lista ** lst, int n){
    int i;
    lista * aux = *lst;
    lista * excluir;

    //*lst ==> l

    if((n==0)&&(aux!=NULL)){
        *lst = aux->prox;
        free(aux);
    }
    else { //aux caminhar até antes do que queremos excluir
        //excluir
        for(i=0;i<n-1;i++){
            aux = aux->prox;
            if(aux==NULL){
                break;
            }
        }
        if((aux!=NULL)&&(aux->prox!=NULL)){
            excluir = aux->prox;
            aux->prox = excluir->prox;
            free(excluir);
        }
    }
}

void destruir(lista ** lst){
    lista * aux = *lst;
    lista * excluir;

    while(aux!=NULL){
        excluir = aux;
        aux = aux->prox;
        free(excluir);
    }

    *lst = NULL;
}

// https://meet.google.com/qmr-ihre-nty

void mostrarN(lista * l, int n){ 
    // se n == 0, mostrar o primeiro
    // se n == 1, mostrar o segundo
    // ...
    lista * aux = l;
    int i = 0;

    while(aux!=NULL){
        if(i==n){
            printf("Nome: %s\n",aux->info.nome);
            printf("Idade: %d\n",aux->info.idade);
        }
        aux = aux->prox;
        i+=1;
    }
}

void inserirPosicao(lista ** lst, int n, cliente c){
    lista * aux = *lst;
    lista * aux2;
    int i=0;
    if(n==0){
        inserirInicio(lst, c);
    }
    else{
        for(i=0;i<n-1;i++){
            aux = aux->prox;
        }
        if(aux!=NULL){
            aux2 = (lista *) calloc(1,sizeof(lista));
            aux2->info = c;
            aux2->prox = aux->prox;
            aux->prox = aux2;
        }
        else{
            printf("posicao invalida\n");
        }
    }
}

cliente* acessar(lista * l, int n){
    lista * aux = l;
    int i;
    for(i=0;i<n;i++){
        if(aux==NULL) {
            break;
        }
        aux = aux->prox;
    }
    if(aux!=NULL) {
        return &aux->info;
    }
    else {
        return NULL;
    }
}

cliente createCliente(){
    cliente  
}


int buscar(lista * lst, char nome[]){
    int i=0;
    lista * aux = lst;

    while(aux!=NULL){
        if(strcmp(nome,aux->info.nome)==0){
            break;
        } else {
            aux = aux->prox;
            i++;
        }
    }
    if(aux==NULL) {
        return -1;
    }
    else {
        return i;
    }
}

int tamanho(lista * lst){
    int i=0;
    lista * aux = lst;
    while(aux!=NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

void inserirFinal(lista ** lst, cliente c){
    lista * aux = *lst;
    lista * aux2;
    if(aux==NULL){
        inserirInicio(lst,c);
    }
    else {
        while(aux->prox!=NULL) {
            aux = aux->prox;
        }
        aux2 = (lista *) calloc(1,sizeof(lista));
        aux2->info = c;
        aux2->prox = aux->prox;
        aux->prox = aux2;
    }
}

void showOptions(){
    printf("1- Inserir no inicio\n");
    printf("2- Inserir na posição\n");
    printf("3- Inserir no final\n");
    printf("4- Acessar cliente\n");
    printf("5- Eliminar\n");
    printf("6- Listar\n");
    printf("7- Buscar\n");
    printf("8- Sair\n\n");
}


int main(void){
    enum options{ // The exit option is not necessary
        UNSHIFT = 1,
        SPLICE,
        CONCAT,
        ACCESS,
        ELIMINATE,
        LIST,
        SEARCH
    };


    lista * l;
    cliente c;
    cliente * pc;
    inicializar(&l);

    int option;
    size_t pos;

    char nome[30];

    showOptions();
    scanf("%d", &option);
    fflush(stdin);

    switch(option){
        case UNSHIFT:
            printf("Insira o nome do Cliente \n") 
            break; 



        case SPLICE: printf("inserir"); break;
        case CONCAT: printf("inserir"); break;
        case ACCESS: printf("inserir"); break;
        case ELIMINATE: printf("inserir"); break;
        case LIST: printf("inserir"); break;
        case SEARCH: printf("inserir"); break;
        default: return 0;
    }



    return 0;
}



