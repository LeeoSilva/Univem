#include "../headers/actions.hpp"

int drawMenuAndGetUserDecision(){
    int userChoise = 0; 
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

void getPassAndRegister(const unsigned char priority, priorityQueue* queues){
    const int len = queues->length;
    printf("len: %d\n", len);
    char output[BUFFER_SIZE]; 
    if(priority == NORMAL) getNormalPass(len, output);
    else if(priority == DEFICIENT) getDeficientPass(len, output);
    else if(priority == PREGNANT) getPregnantPass(len, output);
    else if(priority == AGED) getAgedPass(len, output);
    insert(queues, output);
}


