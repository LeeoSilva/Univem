#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// magic numbers 
#define BUFFER_SIZE 30 
#define FAILED -1

typedef struct _cliente{
    char nome[BUFFER_SIZE];
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


int inserirInicio(lista ** lst, cliente c){ // DONE
    lista * aux;
    aux = (lista*) calloc(1,sizeof(lista));
    aux->info = c;
    //*lst ==> l
    aux->prox = *lst;
    *lst = aux;
    return 0;
}

void mostrarPrimeiro(lista * l){
    printf("Nome: %s\n",l->info.nome);
    printf("Idade: %d\n\n",l->info.idade);
}

void mostrarTodos(lista * l){
    lista * aux=l;
    while(aux!=NULL){
        printf("Nome: %s\n", aux->info.nome);
        printf("Idade: %d\n", aux->info.idade);
        aux = aux->prox;
    }
}

int eliminar(lista ** lst, int n){
    int i;
    lista * aux = *lst;
    lista * excluir;

    if((n == 0) && (aux != NULL)){ // eliminar raiz da lista 
        *lst = aux->prox;
        free(aux);
        return 0;
    }else{
        for(i = 0; i < n-1; ++i){ // andar até antes do elemento que vamos eliminar 
            aux = aux->prox;
            if(aux == NULL) break;
        }
        if((aux != NULL) && (aux->prox != NULL)){
            excluir = aux->prox; // proximo elemento é o escolhido 
            aux->prox = excluir->prox; // reajeitar ponteiros anteriores
            free(excluir); // eliminar elemento escolhido 
            return 0;
        }
        return FAILED;
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

int inserirPosicao(lista ** lst, int n, cliente c){ // DONE 
    lista * aux = *lst;
    lista * aux2;
    int i=0;
    if(n==0){
        return inserirInicio(lst, c);
    }

    for(i = 0; i < n-1; ++i){
        if(aux->prox == NULL){
            printf("Posicao invalida.\n");
            return FAILED;
        }
        aux = aux->prox;
    }

    aux2 = (lista *) calloc(1,sizeof(lista));
    aux2->info = c;
    aux2->prox = aux->prox;
    aux->prox = aux2;
    return 0;
}

cliente* acessar(lista * l, int n){
    int i;
    lista * aux = l;
    for(i = 0; i < n; ++i){
        if(aux==NULL) break;
        aux = aux->prox;
    }
    if(aux!=NULL) return &aux->info;
    return NULL;
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
        return FAILED;
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

int inserirFinal(lista ** lst, cliente c){ // DONE
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

void showOptions(){
    printf("1- Inserir no inicio\n"); // DONE
    printf("2- Inserir na posição\n"); // DONe
    printf("3- Inserir no final\n"); // DONE
    printf("4- Acessar cliente\n"); // DONE
    printf("5- Eliminar\n"); // DONE
    printf("6- Listar\n"); // DONE -> mostrarTodos
    printf("7- Buscar\n"); // DONE
    printf("8- Sair\n\n"); // DONE
}

void populateCliente(cliente* client){
    printf("Insira o nome do Cliente \n");
    fflush(stdin);
    scanf("%s", &client->nome);

    printf("Insira a idade de %s:\n", client->nome);
    fflush(stdin);
    scanf("%i", &client->idade);
}

int showClient(cliente* client){
    if(client == NULL){
        printf("Cliente não existe\n");
        return FAILED;
    }
    printf("Nome: %s\n", client->nome);
    printf("Idade: %d\n", client->idade);
    return 0;
}

size_t getPosFromUser(){
    size_t pos;
    printf("Insira a posicao: ");
    fflush(stdin);
    scanf("%d", &pos);
    return pos;
}

int main(void){
    enum options{ // The exit option is not necessary
        UNSHIFT = 1, SPLICE, CONCAT, ACCESS, ELIMINATE, LIST, SEARCH
    };

    lista listaAux;
    lista * p_list = &listaAux;
    cliente clienteAux;
    cliente * p_cliente = &clienteAux;

    int option;
    size_t pos;
    char idade;
    char nome[BUFFER_SIZE];

    inicializar(&p_list);

    // menu segment
    while(option != 8){
        showOptions();
        scanf("%d", &option);
        fflush(stdin);


        switch(option){
            case UNSHIFT: 
                populateCliente(p_cliente);
                inserirInicio(&p_list, clienteAux);
                printf("Inserido com sucesso\n");
                break;
            case SPLICE:
                populateCliente(p_cliente);  
                pos = getPosFromUser();
                if(inserirPosicao(&p_list, pos, clienteAux) == 0)
                    printf("%s inserido com sucesso na posicao %d.\n", clienteAux.nome, pos);
                break;
            case CONCAT:
                populateCliente(p_cliente);  
                if(inserirFinal(&p_list, clienteAux) == 0)
                    printf("%s inserido com sucesso no final da lista.\n", clienteAux.nome);
                break;
            case ACCESS:
                pos = getPosFromUser();
                showClient(acessar(p_list, pos));
                break;
            case ELIMINATE:
                pos = getPosFromUser();
                if(eliminar(&p_list, pos) == 0)
                    printf("Posicao %d eliminada com sucesso\n", pos);
                break;
            case LIST:
                mostrarTodos(p_list);
                break;
            case SEARCH:
                printf("Insira um nome a ser procurado: \n");
                fflush(stdin);
                scanf("%s", nome);
                showClient(acessar(p_list, buscar(p_list, nome)));
                break;
            default:
                return 0;
        }
    }
    return 0;
}



